#include <stdlib.h>
#include <linux/slab.h>
#include "hashfunctions.h"

//magic numbers that come from the FNV paper
#define FNV_PRIME 1099511628211ULL
#define FNV_OFFSET  14695981039346656037ULL

#ifdef DEBUG_HASH
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...)
#endif



/*
 * implement the FNV hashing algorithm - this is a high efficiency hash that is
 * not as strict as the MD5 hash (its not cryptographic grade) but it is superior to
 * CRC and much quicker than MD5
 */
uint32_t hash_function(uint8_t* bytes, uint32_t length)
{
	uint64_t hash;
	int i;

	hash = FNV_OFFSET;
	for (i=0; i<length; i++)
	{
		hash = hash ^ (uint64_t)(bytes[i]);
		hash = hash * FNV_PRIME;
	}
	return ((hash & 0x00000000FFFFFFFF) ^ ((hash & 0xFFFFFFFF00000000)>>32));
}
/*create a new hash table structure - allocate memory, initialise locks etc.
 * we pass in the table size, the rate at which entries are aged out - entries that
 * are older than table_age_rate are treated as free entries, hash_insert_retry_count
 * specifies how many different hash locations to try when trying to find a free spot -
 * setting it larger makes more efficient use of the table, but is slower, smaller values
 * are faster, but may fail to find a free spot and so will over-write the least recently
 * added entry
 */
hash_ctx* hash_init(uint32_t table_sz, uint64_t table_age_rate, uint32_t hash_insert_retry_count)
{
	hash_ctx* ptr = kmalloc(sizeof(hash_ctx),GFP_ATOMIC);
	if(!ptr)
	{
		return 0;
	}
	ptr->entries =  kmalloc(sizeof(entries_t) * table_sz,GFP_ATOMIC);
	if(!ptr->entries)
	{
		kfree(ptr);
		return 0;
	}

	ptr->hash_insert_retry_count = hash_insert_retry_count;
	ptr->table_age_rate = table_age_rate;
	ptr->table_sz = table_sz;
	memset(ptr->entries,0,sizeof(entries_t) * table_sz);

	spin_lock_init(&ptr->lock);

	return ptr;
}

/*
 * atomically insert a packet in the table - find a spot which is
 * try hash_insert_retry_count times to find a spot which is greater than table_age_rate
 * ticks old. return the indx of the bin - will overwrite if no free bin is available or
 * return -1 if the entry already exists - the packet has already been inserted
 */
int32_t hash_insert(hash_ctx* ctx, uint8_t* bytes, uint32_t sz, uint64_t timestamp)
{
	uint32_t h;


	h = hash_function(bytes, sz) ;
	return hash_insert_with_hash(ctx,h,timestamp);
}


/*
 * atomically insert a packet in the table - find a spot which is
 * try hash_insert_retry_count times to find a spot which is greater than table_age_rate
 * ticks old. return the indx of the bin - will overwrite if no free bin is available or
 * return -1 if the entry already exists - the packet has already been inserted
 */
int32_t hash_insert_with_hash(hash_ctx* ctx, uint32_t h, uint64_t timestamp)
{
	uint32_t h;
	uint32_t i;
	entries_t* p_entry;
	uint64_t cutoff_time;
	uint64_t best_time;
	uint32_t indx;

	int32_t retval;

	retval = 0;

	best_time = UINT64_MAX;


	cutoff_time = timestamp - ctx->table_age_rate;

	//need to lock the table here
	PRINTF("looking for hash %d\n",h);

	//lock access to the hash while we search through it
	spin_lock_bh(&ctx->lock);
	for (i=0; i<ctx->hash_insert_retry_count; i++)
	{
		indx = (h+i) % ctx->table_sz;
		p_entry = &ctx->entries[ indx ];
		PRINTF("at index %d - found hash %d and timestamp %d\n", indx,p_entry->hash, p_entry->timestamp);
		if(p_entry->hash == h)
		{
			//found it - already exists
			if(p_entry->timestamp > cutoff_time)
			{
				retval =  -1;	//and it hasn't expired - we have found it
			}
			else
			{
				retval = indx;	//but it has expired - but insert here anyway
			}
			break;
		}

		if(best_time!=0)
		{
			if(p_entry->timestamp < cutoff_time )
			{
				//we have found an empty bucket - lock it in (this is the first one we found - so we prefer it
				//for quicker access later - but we need to search through all the of the bins incase we find our entry
				retval = indx;
				best_time = 0;
			}
			else if (p_entry->timestamp < best_time)
			{
				retval=indx;
				best_time = p_entry->timestamp;
			}
		}
	}

	if(retval >= 0)
	{
		p_entry = &ctx->entries[retval];
		p_entry->hash = h;
		p_entry->timestamp = timestamp;
	}
	spin_unlock_bh(&ctx->lock);

	//and unlock the table here
	return retval;
}



/*
 * atomically find a packet in the table - find a spot which is
 * try hash_insert_retry_count times to find a spot which is greater than table_age_rate
 * ticks old. return the indx of the bin - will overwrite if no free bin is available or
 * return -1 if the entry already exists - the packet has already been inserted
 */
int32_t hash_find(hash_ctx* ctx, uint8_t* bytes, uint32_t sz, uint64_t timestamp)
{
	uint32_t h;


	h = hash_function(bytes, sz) ;
	return hash_find_with_hash(ctx,h,timestamp);
}


/*
 * atomically insert a packet in the table - find a spot which is
 * try hash_insert_retry_count times to find a spot which is greater than table_age_rate
 * ticks old. return the indx of the bin - will overwrite if no free bin is available or
 * return -1 if the entry already exists - the packet has already been inserted
 */
int32_t hash_find_with_hash(hash_ctx* ctx, uint32_t h, uint64_t timestamp)
{
	uint32_t h;
	uint32_t i;
	entries_t* p_entry;
	uint64_t cutoff_time;
	uint64_t best_time;
	uint32_t indx;

	int32_t retval;

	retval = 0;

	best_time = UINT64_MAX;


	cutoff_time = timestamp - ctx->table_age_rate;

	//need to lock the table here
	PRINTF("looking for hash %d\n",h);

	//lock access to the hash while we search through it
	spin_lock_bh(&ctx->lock);
	for (i=0; i<ctx->hash_insert_retry_count; i++)
	{
		indx = (h+i) % ctx->table_sz;
		p_entry = &ctx->entries[ indx ];
		PRINTF("at index %d - found hash %d and timestamp %d\n", indx,p_entry->hash, p_entry->timestamp);
		if(p_entry->hash == h)
		{
			//found it - already exists
			if(p_entry->timestamp > cutoff_time)
			{
				retval =  indx;	//and it hasn't expired - we have found it
			}
			else
			{
				retval = -1;	//but it has expired - no need to look further
			}
			break;
		}
		indx=-1;
	}

	spin_unlock_bh(&ctx->lock);

	//and unlock the table here
	return retval;
}

/*
 * clean up the hash table, freeing resources such as locks and memory
 */
void hash_free(hash_ctx* ctx)
{
	kfree(ctx->entries);
	kfree(ctx);
}
