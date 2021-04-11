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
    int fake_id;
    int is_single;
    
    int* index_array;
    int index_array_len;
    Init_List init_val;

    int is_value;
    int single_val;
}Var_Attrib;

typedef struct Hash_Bucket{
    struct Hash_Bucket* next;
    char* name;
    int count;
    int eey_idx;
    Var_Attrib* var_list_head;
}Hash_Bucket;


void init_var_table(int param_var_cnt, int original_var_cnt);

void destroy_var_table();

int calc_hash(char* name);

Hash_Bucket* hash_insert_key(char* name);

int delete_insert_key(char* name);

void hash_table_clear();

Hash_Bucket* hash_find_buc(char* name);

#endif
