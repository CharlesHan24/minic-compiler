#include "./name_hash.h"
#include <malloc.h>
#include <string.h>

static int hash_base = 233;

Hash_Bucket* hash_table[TABLE_SIZE];

Var_Attrib* param_attrib;
Var_Attrib* original_var_attrib;

void init_var_table(int param_var_cnt, int original_var_cnt){
    param_attrib = calloc(sizeof(Var_Attrib) * param_var_cnt, 1);
    original_var_attrib = calloc(sizeof(Var_Attrib) * original_var_cnt, 1);
}

void destroy_var_table(){
    free(param_attrib);
    free(original_var_attrib);
}

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

            Var_Attrib* new_var = malloc(sizeof(Var_Attrib));
            new_var->next = cur_node->var_list_head;
            cur_node->var_list_head = new_var;
        }
    }
    if (ret == NULL){
        ret = malloc(sizeof(Hash_Bucket));
        ret->next = hash_table[hash_val];
        hash_table[hash_val] = ret;
        ret->count++;
        ret->name = malloc(strlen(name) + 1);
        memcpy(ret->name, name, strlen(name));

        Var_Attrib* new_var = malloc(sizeof(Var_Attrib));
        new_var->next = NULL;
        ret->var_list_head = new_var;
    }
    return ret;
}

int delete_insert_key(char* name){
    int hash_val = calc_hash(name);
    Hash_Bucket* ret = NULL;
    Hash_Bucket* cur_node;
    for (cur_node = hash_table[hash_val]; cur_node != NULL; cur_node = cur_node->next){
        if (strcmp(cur_node->name, name) == 0){
            ret = cur_node;
            cur_node->count--;
            free(cur_node->var_list_head->index_array);
            Var_Attrib* tmp = cur_node->var_list_head;
            cur_node->var_list_head = cur_node->var_list_head->next;
            free(tmp);

            if (cur_node->count == 0){
                for (Hash_Bucket* tmp_node = hash_table[hash_val]; tmp_node != NULL; tmp_node = cur_node->next){
                    if (tmp_node->next == cur_node){
                        tmp_node->next = cur_node->next;
                        free(cur_node->name);
                        free(cur_node);
                        break;
                    }
                }
            }
            return 1;
        }
    }
    if (ret == NULL){
        return 0;
    }
}

void hash_table_clear(){
    for (int i = 0; i < TABLE_SIZE; i++){
        Hash_Bucket* cur_node = hash_table[i];
        Hash_Bucket* nxt_node;
        for(; cur_node != NULL; cur_node = nxt_node){
            Var_Attrib* nxt_var;
            for (Var_Attrib* cur_var = cur_node->var_list_head; cur_var != NULL; cur_var = nxt_var){
                nxt_var = cur_var->next;
                free(cur_var->index_array);
                free(cur_var);
            }

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