/*
 * hashfunctions.h
 *
 *  Created on: 29/02/2016
 *      Author: robert
 */

#ifndef HASHFUNCTIONS_H_
#define HASHFUNCTIONS_H_

#include <stdint.h>

typedef struct s_entries
{
	uint32_t	hash;
	uint64_t	timestamp;
} entries_t;

typedef struct s_hash_ctx
{
	uint32_t 	table_sz;
	uint64_t 	table_age_rate;
	uint32_t 	hash_insert_retry_count;
	spinlock_t	lock;

	entries_t* entries;
} hash_ctx;

typedef  struct s_hash_ctx hash_ctx;
/*create a new hash table structure - allocate memory, initialise locks etc.
 * we pass in the table size, the rate at which entries are aged out - entries that
 * are older than table_age_rate are treated as free entries, hash_insert_retry_count
 * specifies how many different hash locations to try when trying to find a free spot -
 * setting it larger makes more efficient use of the table, but is slower, smaller values
 * are faster, but may fail to find a free spot and so will over-write the least recently
 * added entry
 */
hash_ctx* hash_init(uint32_t table_sz, uint64_t table_age_rate, uint32_t hash_insert_retry_count);
/*
 * atomically insert a packet in the table - find a spot which is
 * try hash_insert_retry_count times to find a spot which is greater than table_age_rate
 * ticks old. return the indx of the bin - will overwrite oldest entry if no free bin available
 * or return -1 if the packet already exists
 */
int32_t hash_insert(hash_ctx* ctx, uint8_t* bytes, uint32_t sz, uint64_t timestamp);

/*
 * atomically insert a packet in the table - find a spot which is
 * try hash_insert_retry_count times to find a spot which is greater than table_age_rate
 * ticks old. return the indx of the bin - will overwrite oldest entry if no free bin available
 * or return -1 if the packet already exists - uses a pre-calculated hash
 */
int32_t hash_insert_with_hash(hash_ctx* ctx, uint32_t hash_value, uint64_t timestamp);

/*
 * atomically insert a packet in the table - find a spot which is
 * try hash_insert_retry_count times to find a spot which is greater than table_age_rate
 * ticks old. return the indx of the bin - will overwrite oldest entry if no free bin available
 * or return -1 if the packet already exists
 */
int32_t hash_find(hash_ctx* ctx, uint8_t* bytes, uint32_t sz, uint64_t timestamp);

/*
 * atomically insert a packet in the table - find a spot which is
 * try hash_insert_retry_count times to find a spot which is greater than table_age_rate
 * ticks old. return the indx of the bin - will overwrite oldest entry if no free bin available
 * or return -1 if the packet already exists - uses a pre-calculated hash
 */
int32_t hash_find_with_hash(hash_ctx* ctx, uint32_t hash_value, uint64_t timestamp);

/*
 * generate the hash of the supplied byte array
 */
uint32_t hash_function(uint8_t* bytes, uint32_t sz);

/*
 * clean up the hash table, freeing resources such as locks and memory
 */
void hash_free(hash_ctx* table);

#endif /* HASHFUNCTIONS_H_ */
