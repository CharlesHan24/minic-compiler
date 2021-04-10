#include "gen_eey.h"
#include "./name_hash.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int original_var_id = -1;
static int temp_var_id = -1;
static int param_var_id = -1;

#define MAX_LINE_WIDTH 80

typedef struct Prov_Params{
    char* prefix_code;
    int return_flag;
    Var_Attrib* variable;

}Prov_Params;

typedef struct Ret_Params{
    char* return_code;
    Init_List init_val;
    int* index_array;
    int index_array_len;
    int val_from_son;
}Ret_Params;

static int new_temp_var(){
    temp_var_id++;
    return temp_var_id;
}

static int new_original_var(){
    original_var_id++;
    return original_var_id;
}

static int new_param_var(){
    param_var_id++;
    return param_var_id;
}

static int compute_total_dimension(int* index_array, int index_array_len){
    int res = 1;
    for (int i = 0; i < index_array_len; i++){
        res *= index_array[i];
    }
    return res;
}

static char* generate_assign_code(char prefix, int var_id, Init_List init_list){
    char* result = calloc(MAX_LINE_WIDTH * init_list.len, 1);
    char* ptr = result;
    for (int i = 0; i < init_list.len; i++){
        sprintf(ptr, "%c%d[%d] = %d", prefix, var_id, init_list.index_arr[i] * 4, init_list.val_arr[i]);
        ptr += strlen(ptr);
    }
    return result;
}

static Hash_Bucket* __wrap_insert_key(char* name, int var_id, char prefix){
    Hash_Bucket* bucket = hash_insert_key(name);
    bucket->var_list_head->var_id = var_id;
    bucket->var_list_head->prefix = prefix;
    return bucket;
}

static int check_const(Syntax_Tree* root){
    if ((root->node_type == TP_TOKEN) && (root->token_type == TOK_IDENT)){
        if (root->restric == CONST_REST){
            fprintf(stderr, "Error: Expect const init_value/index. Find %s\n", root->ident_name);
            return 0;
        }
    }
    for (Syntax_Tree* son = root->head_son; son != NULL; son = son->next_sib){
        if (check_const(son)){
            return 0;
        }
    }
}

static int get_num_params(Syntax_Tree* root){
    int res = 0;
    for (Syntax_Tree* son = root->head_son; son != NULL; son = son->next_sib){
        res++;
    }
    return res;
}

static int dfs_generate(Syntax_Tree* root, FILE* fout, const Prov_Params* prov_param, Ret_Params* return_param){
    if (prov_param->prefix_code != NULL){
        fprintf(fout, "%s", prov_param->prefix_code);
    }

    Syntax_Tree* son;
    Prov_Params next_prov_param;
    Ret_Params next_ret_param;
    memset(&next_prov_param, 0, sizeof(next_prov_param));
    memset(&next_ret_param, 0, sizeof(next_ret_param));
    memset(return_param, 0, sizeof(Ret_Params));

    switch (root->node_type){
        case TP_COMP_UNIT:
            int num_of_declaration = 0;

            for (son = root->head_son; son != NULL; son = son->next_sib){
                if (son->node_type == TP_DECL){
                    num_of_declaration++;
                }
            }

            char** pref_code_list = malloc(sizeof(char*) * num_of_declaration);
            num_of_declaration = 0;
            int tot_len = 0;

            for (son = root->head_son; son != NULL; son = son->next_sib){
                if (son->node_type == TP_DECL){
                    next_prov_param.return_flag = 1;
                    if (dfs_generate(son, fout, &next_prov_param, &next_ret_param) == 0){
                        return 0;
                    }
                    if (next_ret_param.return_code != NULL){
                        pref_code_list[num_of_declaration++] = next_ret_param.return_code;
                        tot_len += strlen(next_ret_param.return_code);
                    }
                }
            }
            next_prov_param.prefix_code = calloc((tot_len + 1), sizeof(char));
            for (int i = 0; i < num_of_declaration; i++){
                strcat(next_prov_param.prefix_code, pref_code_list[i]);
                free(pref_code_list[i]);
            }
            char* tmp_prefix_code = next_prov_param.prefix_code;
            free(pref_code_list);

            for (son = root->head_son; son != NULL; son = son->next_sib){
                if (son->node_type == TP_FUNC_DEF){
                    if (strcmp(son->head_son->next_sib->ident_name, "main") == 0){
                        next_prov_param.return_flag = 0;
                        next_prov_param.prefix_code = tmp_prefix_code;
                        if (dfs_generate(son, fout, &next_prov_param, &next_ret_param) == 0){
                            return 0;
                        }
                    }
                    else{
                        next_prov_param.return_flag = 0;
                        next_prov_param.prefix_code = NULL;
                        if (dfs_generate(son, fout, &next_prov_param, &next_ret_param) == 0){
                            return 0;
                        }
                    }
                }
            }
            free(next_prov_param.prefix_code);
            break;
        
        case TP_DECL:
            int num_of_declaration = 0, tot_len = 0;

            for (son = root->head_son; son != NULL; son = son->next_sib){
                if (son->node_type == TP_DEF){
                    num_of_declaration++;
                }
            }
            char** pref_code_list = malloc(sizeof(char*) * num_of_declaration);
            num_of_declaration = 0;

            next_prov_param.prefix_code = NULL;

            for (son = root->head_son; son != NULL; son = son->next_sib){
                if (son->node_type == TP_DEF){
                    next_prov_param.return_flag = 1;
                    if (dfs_generate(son, fout, &next_prov_param, &next_ret_param) == 0){
                        return 0;
                    }
                    if (next_ret_param.return_code != NULL){
                        pref_code_list[num_of_declaration++] = next_ret_param.return_code;
                        tot_len += strlen(next_ret_param.return_code);
                    }
                }
            }
            if (tot_len == 0){
                return_param->return_code = NULL;
            }
            else{
                return_param->return_code = calloc((tot_len + 1), sizeof(char));
                for (int i = 0; i < num_of_declaration; i++){
                    strcat(return_param->return_code, pref_code_list[i]);
                    free(pref_code_list[i]);
                }
            }
            free(pref_code_list);
            break;
        
        case TP_DEF:
            int var_id;
            char prefix_key = (root->option & 4)? 'p': 'T';
            if (prefix_key == 'T'){
                var_id = new_original_var();
            }
            else{
                var_id = new_param_var();
            }
            Var_Attrib* cur_var = __wrap_insert_key(root->head_son->ident_name, var_id, prefix_key)->var_list_head;

            if ((root->option) & 2){ // with index
                cur_var->is_single = 0;
                if (dfs_generate(root->head_son, fout, &next_prov_param, &next_ret_param) == 0){
                    return 0;
                }
                cur_var->index_array = malloc(sizeof(int) * next_ret_param.index_array_len);
                for (int i = 0; i < next_ret_param.index_array_len; i++){
                    cur_var->index_array[i] = next_ret_param.index_array[i];
                }
                cur_var->index_array_len = next_ret_param.index_array_len;
                free(next_ret_param.index_array);
            }

            if ((root->option) & 1){
                next_prov_param.variable = cur_var;
                if (dfs_generate(root->head_son, fout, &next_prov_param, &next_ret_param) == 0){
                    return 0;
                }
                cur_var->is_single = 1;
                if (next_ret_param.val_from_son){
                    cur_var->single_val = next_ret_param.val_from_son;
                }
                else{
                    cur_var->init_val.len = next_ret_param.init_val.len;
                    cur_var->init_val.index_arr = malloc(sizeof(int) * cur_var->init_val.len);
                    cur_var->init_val.val_arr = malloc(sizeof(int) * cur_var->init_val.len);

                    for (int i = 0; i < cur_var->init_val.len; i++){
                        cur_var->init_val.index_arr[i] = next_ret_param.init_val.index_arr[i];
                        cur_var->init_val.val_arr[i] = next_ret_param.init_val.val_arr[i];
                    }
                    free(next_ret_param.init_val.index_arr);
                    free(next_ret_param.init_val.val_arr);
                }
            }
            if (!((root->option) & 4)){
                if (root->option & 2){
                    fprintf(fout, "var %d %c%d\n", cur_var->index_array_len * 4, prefix_key, var_id);
                }
                else{
                    fprintf(fout, "var %c%d\n", prefix_key, var_id);
                }
                if (root->option & 1){
                    char* assign_str;
                    if (root->option & 2){
                        assign_str = generate_assign_code(prefix_key, var_id, cur_var->init_val);
                    }
                    else{
                        assign_str = malloc(MAX_LINE_WIDTH);
                        sprintf(assign_str, "var %c%d = %d\n", prefix_key, var_id, cur_var->single_val);
                    }
                    if (prov_param->return_flag){
                        return_param->return_code = assign_str;
                    }
                    else{
                        fprintf(fout, "%s", assign_str);
                    }
                }
            }
            break;
        
        case TP_INDEXES:
            int dimension = 0;
            for (son = root->head_son; son != NULL; son = son->next_sib){
                dimension++;
            }
            int* cur_index;

            if (root->option == 1){
                dimension++;
                return_param->index_array = malloc(sizeof(int) * dimension);
                return_param->index_array[0] = -1;
                cur_index = return_param->index_array + 1;
            }
            else{
                return_param->index_array = malloc(sizeof(int) * dimension);
                cur_index = return_param->index_array;
            }
            return_param->index_array_len = dimension;

            for (son = root->head_son; son != NULL; son = son->next_sib){
                dfs_generate(son, fout, &next_prov_param, &next_ret_param);
                *cur_index = next_ret_param.val_from_son;
                cur_index++;
            }
            break;

        case TP_INIT_VAL:
            break;
        case TP_FUNC_DEF:
            son = root->head_son->next_sib;
            dfs_generate(son, fout, &next_prov_param, &next_ret_param);
            int param_cnt = get_num_params(son);


        default:
            break;
    }
}

void generate_eeyore(Syntax_Tree* root, FILE* fout){
    forward_const_label(root);
    if (!check_const(root)){
        return;
    }

    Prov_Params next_prov_param;
    Ret_Params next_ret_param;
    memset(&next_prov_param, 0, sizeof(next_prov_param));
    memset(&next_ret_param, 0, sizeof(next_ret_param));
    dfs_generate(root, fout, &next_prov_param, &next_ret_param);
}