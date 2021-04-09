#include "./name_hash.h"
#include <malloc.h>
#include <string.h>

static int hash_base = 233;

Hash_Bucket* hash_table[TABLE_SIZE];

int calc_hash(char* name){
    int len = strlen(name);
    int hash_val = 0;
    for (int i = 0; i < len; i++){
        hash_val = (hash_val * hash_base + name[i]) % TABLE_SIZE;
    }
    return hash_val;
}

Hash_Bucket* hash_insert_key(char* name){
    int hash_val = calc_hash(name);
    Hash_Bucket* ret = NULL;
    Hash_Bucket* cur_node;
    for (cur_node = hash_table[hash_val]; cur_node != NULL; cur_node = cur_node->next){
        if (strcmp(cur_node->name, name) == 0){
            ret = cur_node;
            cur_node->count++;
        }
    }
    if (ret == NULL){
        ret = malloc(sizeof(Hash_Bucket));
        ret->next = hash_table[hash_val];
        hash_table[hash_val] = ret;
        ret->count++;
        ret->name = malloc(strlen(name) + 1);
        memcpy(ret->name, name, strlen(name));
    }
    return ret;
}

void hash_table_clear(){
    for (int i = 0; i < TABLE_SIZE; i++){
        Hash_Bucket* cur_node = hash_table[i];
        Hash_Bucket* nxt_node;
        for(; cur_node != NULL; cur_node = nxt_node){
            nxt_node = cur_node->next;
            free(cur_node->name);
            free(cur_node);
        }
    }
}

Hash_Bucket* hash_find_buc(char* name){
    int hash_val = calc_hash(name);
    Hash_Bucket* ret = NULL;
    Hash_Bucket* cur_node;
    for (cur_node = hash_table[hash_val]; cur_node != NULL; cur_node = cur_node->next){
        if (strcmp(cur_node->name, name) == 0){
            ret = cur_node;
        }
    }
    return ret;
}