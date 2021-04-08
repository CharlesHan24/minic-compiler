#ifndef _NAME_HASH_H
#define _NAME_HASH_H

#define TABLE_SIZE 1009

typedef struct Hash_Buc{
    struct Hash_Buc* next;
    char* name;
    int count;
    int eey_idx;
    int* params;   // specifying [][][]
    int param_cnt;
}Hash_Buc;



Hash_Buc* calc_hash(char* name);

void hash_insert_key(char* name);

void hash_table_clear();

Hash_Buc* hash_find_buc(char* name);

#endif
