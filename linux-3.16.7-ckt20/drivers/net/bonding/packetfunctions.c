/*
 * packetfunctions.c
 *
 *  Created on: 01/03/2016
 *      Author: robert
 */

#include <stdlib.h>
#include <linux/spinlock.h>
#include <linux/jiffies.h>
#include "bonding.h"
#include "hashfunctions.h"
#include "packetfunctions.h"

#define MAX_BYTES_TO_TEST 64

int on_prp_bond_created(struct bonding * bond,prp_init_parameters_t* init_parameters)
{
	if(!bond)
	{
		pr_warn("on_prp_bond_created called with null bond");
		return -EINVAL;
	}

	bond->prp_bond_info.bond_recieved_hash=hash_init(init_parameters->packet_duplicate_table_sz,
			msecs_to_jiffies(init_parameters->packet_duplicate_table_age_rate),
			init_parameters->hash_insert_retry_count);
	if(!bond->prp_bond_info.bond_recieved_hash)
	{
		pr_warn("on_prp_bond_created failed to allocate bond_recieved_hash table");
		return -ENOMEM;
	}

	bond->prp_bond_info.bond_lively_macaddr=hash_init(init_parameters->MAC_address_table_sz,
			msecs_to_jiffies(init_parameters->MAC_address_table_age_rate),
			init_parameters->hash_insert_retry_count);

	if(!bond->prp_bond_info.bond_lively_macaddr)
	{
		pr_warn("on_prp_bond_created failed to allocate bond_lively_macaddr table");
		hash_free(bond->prp_bond_info.bond_recieved_hash);
		bond->prp_bond_info.bond_recieved_hash=0;
		return -ENOMEM;
	}

	return 0;
}

int on_prp_bond_deleted(struct bonding * bond)
{
	if(!bond)			//nothing to do - bond is already deleted
	{
		return -EINVAL;
	}

	if(bond->prp_bond_info.bond_recieved_hash)
	{
		hash_free(bond->prp_bond_info.bond_recieved_hash);
		bond->prp_bond_info.bond_recieved_hash=0;
	}

	if(bond->prp_bond_info.bond_lively_macaddr)
	{
		hash_free(bond->prp_bond_info.bond_lively_macaddr);
		bond->prp_bond_info.bond_lively_macaddr=0;
	}

	return 0;
}

int on_prp_slave_enrolled(struct slave * s)
{
	struct bonding * bond;
	if(!s)
	{
		pr_warn("on_prp_slave_enrolled called with null slave");
		return -EINVAL;
	}

	bond = s->bond;

	s->prp_bonding_slave_info.bond_lively_macaddr=hash_init(bond->prp_bond_info.bond_lively_macaddr->table_sz,
			bond->prp_bond_info.bond_lively_macaddr->table_age_rate,
			bond->prp_bond_info.bond_lively_macaddr->hash_insert_retry_count);

	if(!s->prp_bonding_slave_info.bond_lively_macaddr)
	{
		pr_warn("on_prp_slave_enrolled failed to allocate slave bond_lively_macaddr table");
		return -ENOMEM;
	}

	return 0;

}

int on_prp_slave_released(struct slave * s)
{


	if(!s)			//nothing to do - slave is already deleted
	{
		return -EINVAL;
	}


	if(s->prp_bonding_slave_info.bond_lively_macaddr)
	{
		hash_free(s->prp_bonding_slave_info.bond_lively_macaddr);
		s->prp_bonding_slave_info.bond_lively_macaddr=0;
	}



	return 0;
}


int on_prp_slave_pkt_received(const struct sk_buff * skb, struct bonding * bond, struct slave * s)
{
	/*
	 * when we receive on a slave interface packet we have to
	 * 		check if we have seen it  before
	 * 			if it is a duplicate swallow it up by setting return value to RX_HANDLER_CONSUMED
	 * 			if it is not a duplicate tag it as requiring further handling by setting return value to RX_HANDLER_PASS
	 * 		mark that the MAC addresses associated with the packet is lively on this slave interface, recording the timestamp
	 * 		and marking it lively at the bonding interface
	 *
	 */

	uint32_t indx;
	uint32_t bytes_to_test;
	uint8_t* p_bytes;
	uint64_t now;
	uint32_t hash;
	int rc;
	struct ethhdr *eth;

	now = jiffies_64;
	rc = RX_HANDLER_PASS;

	bytes_to_test = min(skb_headlen(skb),MAX_BYTES_TO_TEST);
	p_bytes = skb->data;

	indx =  hash_insert(bond->prp_bond_info.bond_recieved_hash, p_bytes, bytes_to_test, now);
	if(indx==-1)
	{
		rc = RX_HANDLER_CONSUMED;		//eat up the packet - it was a duplicate
	}

	//now find the MAC address in the packet
	eth = skb_mac_header(skb);
	//and update the liveliness of the bond and slave component
	hash = hash_function( eth->h_source, sizeof(eth->h_source));
	hash_insert_with_hash(bond->prp_bond_info.bond_recieved_hash,hash, now);
	hash_insert_with_hash(s->prp_bonding_slave_info.bond_lively_macaddr, hash, now);
	return rc;

}

void on_bond_prp_pkt_to_be_transmitted(struct sk_buff *skb, struct bonding *bond, struct slave *s)
{
	/*
	 * when we are to transmit a packet we have to
	 * 		check to see if the mac address is lively at the bonding interface level
	 * 		if it is not lively at the bonding interface level - send it on all interfaces
	 * 		if it is lively at the bonding interface level then send it on every slave that is also tagged as lively
	 */
	uint32_t bond_indx;
	uint32_t slave_indx;
	uint64_t now;
	uint32_t hash;
	struct ethhdr *eth;

	now = jiffies_64;



	//find the MAC address in the packet
	eth = skb_mac_header(skb);
	//and look it up in the bond and slave structures
	hash = hash_function( eth->h_source, sizeof(eth->h_source));
	bond_indx = hash_find_with_hash(bond->prp_bond_info.bond_recieved_hash,hash, now);
	slave_indx = hash_find_with_hash(s->prp_bonding_slave_info.bond_lively_macaddr, hash, now);

	if(slave_indx==-1 && bond_indx!=-1)
		return;	//if the slave has no traffic coming back but the bond is active it means that link to the slave is faulty - stop sending on it

	bond_dev_queue_xmit(bond, skb,s->dev);
}


