#ifndef _NAME_HASH_H
#define _NAME_HASH_H

#define TABLE_SIZE 1009

typedef struct Hash_Bucket{
    struct Hash_Bucket* next;
    char* name;
    int count;
    int eey_idx;
    int* params;   // specifying [][][]
    int param_cnt;
}Hash_Bucket;



int calc_hash(char* name);

Hash_Bucket* hash_insert_key(char* name);

void hash_table_clear();

Hash_Bucket* hash_find_buc(char* name);

#endif
