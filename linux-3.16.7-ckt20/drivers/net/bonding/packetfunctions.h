/*
 * packetfunctions.h
 *
 *  Created on: 01/03/2016
 *      Author: robert
 */

#ifndef PACKETFUNCTIONS_H_
#define PACKETFUNCTIONS_H_


typedef struct s_prp_init_parameters
		{
			uint16_t	MAC_address_table_sz;			//how many entries to set aside for the lively MAC address cache
			uint16_t	MAC_address_table_age_rate;		//how rapidly to age out lively addresses - in milli-seconds
			uint16_t	packet_duplicate_table_sz;		//how many entries to set aside to detect duplicated packets
			uint16_t	packet_duplicate_table_age_rate;//how long before a table entry is discarded - in milli-seconds
			uint16_t	hash_insert_retry_count;		//how many different locations to try and insert a entry into the hash table
		} prp_init_parameters_t;

typedef struct s_prp_bonding
{
	hash_ctx*	bond_recieved_hash;
	hash_ctx* 	bond_lively_macaddr;

} prp_bonding_t;

typedef struct s_prp_bonding_slave
{
	hash_ctx* 	bond_lively_macaddr;
} prp_bonding_slave_t;



#endif /* PACKETFUNCTIONS_H_ */
