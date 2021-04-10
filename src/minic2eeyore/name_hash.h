#ifndef _NAME_HASH_H
#define _NAME_HASH_H

#define TABLE_SIZE 1009

typedef struct Init_List{
    int len;
    int* val_arr;
    int* index_arr;
}Init_List;

typedef struct Var_Attrib{
    struct Var_Attrib* next;
    int var_id;
    char prefix;
    int is_single;
    int single_val;
    int* index_array;
    int index_array_len;
    Init_List init_val;
}Var_Attrib;

typedef struct Hash_Bucket{
    struct Hash_Bucket* next;
    char* name;
    int count;
    int eey_idx;
    Var_Attrib* var_list_head;
}Hash_Bucket;



int calc_hash(char* name);

Hash_Bucket* hash_insert_key(char* name);

int delete_insert_key(char* name);

void hash_table_clear();

Hash_Bucket* hash_find_buc(char* name);

#endif
