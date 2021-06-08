#include "gen_eey.h"
#include "name_hash.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern Var_Attrib* param_attrib;
extern Var_Attrib* original_var_attrib;

static Syntax_Tree* tree_root;

static int original_var_id = -1;
static int temp_var_id = -1;
static int param_var_id = -1;
static int fake_param_var_id = -1;
static int label_id = -1;
static int max_param;

typedef struct Func_Register{
    char* name;
    struct Func_Register* next;
    int exist_ret;
}Func_Register;

Func_Register* func_register_head;

void func_regist(char* name, int exist_ret){
    Func_Register* new_func = calloc(sizeof(Func_Register), 1);
    new_func->name = name;
    new_func->exist_ret = exist_ret;
    new_func->next = func_register_head;
    func_register_head = new_func;
}

int func_exist_ret(char* name){
    for (Func_Register* reg = func_register_head; reg != NULL; reg = reg->next){
        if (strcmp(name, reg->name) == 0){
            return reg->exist_ret;
        }
    }
    return 0;
}

void delete_func_reg_table(){
    Func_Register* tmp;
    for (Func_Register* reg = func_register_head; reg != NULL; reg = tmp){
        tmp = reg->next;
        free(reg);
    }
}

#define MAX_LINE_WIDTH 80

typedef struct Prov_Params{
    int supple_init_flag;
    int is_declare;
    Var_Attrib* init_target_var;
    int dimension;
    int offset;
}Prov_Params;

typedef struct Ret_Psrams{
    int dimension_match; // 1: not match
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
    fake_param_var_id++;
    return param_var_id;
}

static int new_label(){
    label_id++;
    return label_id;
}

static Hash_Bucket* __wrap_insert_key(char* name, int var_id, int fake_id, char prefix){
    Hash_Bucket* bucket = hash_insert_key(name);
    bucket->var_list_head->var_id = var_id;
    bucket->var_list_head->fake_id = fake_id;
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
        if (!check_const(son)){
            return 0;
        }
    }
    return 1;
}


static int dfs_generate(Syntax_Tree* root, FILE* fout, const Prov_Params* prov_param, Ret_Params* return_param){
    if (root == NULL){
        return 1;
    }

    Prov_Params next_prov_param;
    Ret_Params next_ret_param;
    Syntax_Tree* son;
    Var_Attrib* cur_var;
    memset(&next_prov_param, 0, sizeof(next_prov_param));
    memset(&next_ret_param, 0, sizeof(next_ret_param));

    next_prov_param.is_declare = prov_param->is_declare;
    next_prov_param.supple_init_flag = prov_param->supple_init_flag;
    if (prov_param->is_declare == 1){
        if (root->node_type == TP_DEF){
            int tot_bytes = 1;
            if (root->head_son->var_prefix != 'p'){
                cur_var = &original_var_attrib[root->head_son->var_id];
                if (cur_var->is_single){
                    fprintf(fout, "var T%d\n", cur_var->var_id);
                }
                else{
                    for (int i = 0; i < cur_var->index_array_len; i++){
                        tot_bytes *= cur_var->index_array[i];
                    }
                    fprintf(fout, "var %d T%d\n", tot_bytes * 4, cur_var->var_id);
                }
            }
        }
        else{
            if (root->var_prefix == 't'){
                fprintf(fout, "var t%d\n", root->var_id);
            }
        }
        for (son = root->head_son; son != NULL; son = son->next_sib){
            if (!dfs_generate(son, fout, &next_prov_param, &next_ret_param)){
                return 0;
            }
        }
        return 1;
    }

    else{
        // if ((root->node_type == TP_DECL) || (root->node_type == TP_DEF)){
        //     return 1;
        // }
        switch (root->node_type){
            case TP_COMP_UNIT:{
                for (son = root->head_son; son != NULL; son = son->next_sib){
                    if (son->node_type == TP_DECL){
                        next_prov_param.is_declare = 1;
                    }
                    else{
                        next_prov_param.is_declare = 0;
                    }
                    if (!dfs_generate(son, fout, &next_prov_param, &next_ret_param)){
                        return 0;
                    }
                }
                break;
            }

            case TP_INDEXES:{
                for (son = root->head_son; son != NULL; son = son->next_sib){
                    if (!dfs_generate(son, fout, &next_prov_param, &next_ret_param)){
                        return 0;
                    }
                }
                if (root->prev_sib->var_prefix == 'p'){
                    cur_var = &param_attrib[root->prev_sib->fake_id];
                }
                else{
                    cur_var = &original_var_attrib[root->prev_sib->var_id];
                }
                son = root->head_son;
                fprintf(fout, "t%d = %c%d\n", root->var_id, son->var_prefix, root->head_son->var_id);
                son = son->next_sib;
                for (int i = 1; i < cur_var->index_array_len; i++){
                    fprintf(fout, "t%d = t%d * %d\n", root->var_id, root->var_id, cur_var->index_array[i]);
                    if (son != NULL){
                        fprintf(fout, "t%d = t%d + %c%d\n", root->var_id, root->var_id, son->var_prefix, son->var_id);
                        son = son->next_sib;
                    }
                    else{
                        return_param->dimension_match = 1;
                    }
                }
                fprintf(fout, "t%d = t%d * 4\n", root->var_id, root->var_id);
                break;
            }
            
            case TP_FUNC_DEF:{
                if (root->option == 0){
                    fprintf(fout, "f_%s [0]\n", root->head_son->next_sib->ident_name);
                }
                else{
                    fprintf(fout, "f_%s [%d]\n", root->head_son->next_sib->ident_name, root->head_son->next_sib->next_sib->sons_cnt);
                }

                next_prov_param.is_declare = 1;
                for (son = root->head_son; son != NULL; son = son->next_sib){
                    if (!dfs_generate(son, fout, &next_prov_param, &next_ret_param)){
                        return 0;
                    }
                }
                next_prov_param.is_declare = 0;
                if (strcmp(root->head_son->next_sib->ident_name, "main") == 0){
                    for (Syntax_Tree* tmp_son = tree_root->head_son; tmp_son != NULL; tmp_son = tmp_son->next_sib){
                        if (tmp_son->node_type == TP_DECL){
                            if (!dfs_generate(tmp_son, fout, &next_prov_param, &next_ret_param)){
                                return 0;
                            }
                        }
                    }
                }

                if (!dfs_generate(root->tail_son, fout, &next_prov_param, &next_ret_param)){
                    return 0;
                }
                if (root->head_son->token_type == TOK_VOID){
                    fprintf(fout, "return\n");
                }
                else{
                    fprintf(fout, "return 0\n");
                }

                fprintf(fout, "end f_%s\n", root->head_son->next_sib->ident_name);
                break;
            }

            case TP_BLOCK:{
                for (son = root->head_son; son != NULL; son = son->next_sib){
                    if (!dfs_generate(son, fout, &next_prov_param, &next_ret_param)){
                        return 0;
                    }
                }
                break;
            }

            case TP_TOKEN:{
                if (root->token_type == TOK_DEC){
                    fprintf(fout, "%c%d = %d\n", root->var_prefix, root->var_id, root->dec_val);
                }
                break;
            }
            
            case TP_FUNC_CALL:{
                for (son = root->head_son; son != NULL; son = son->next_sib){
                    if (!dfs_generate(son, fout, &next_prov_param, &next_ret_param)){
                        return 0;
                    }
                }
                for (son = root->head_son->next_sib; son != NULL; son = son->next_sib){
                    fprintf(fout, "param %c%d\n", son->var_prefix, son->var_id);
                }

                if (root->var_prefix == 't'){
                    fprintf(fout, "t%d = call f_%s\n", root->var_id, root->head_son->ident_name);
                }
                else{
                    if (func_exist_ret(root->head_son->ident_name)){
                        fprintf(fout, "t0 = call f_%s\n", root->head_son->ident_name);
                    }
                    else{
                        fprintf(fout, "call f_%s\n", root->head_son->ident_name);
                    }
                }
                break;
            }

            case TP_UNARY_EXP:{
                for (son = root->head_son; son != NULL; son = son->next_sib){
                    if (!dfs_generate(son, fout, &next_prov_param, &next_ret_param)){
                        return 0;
                    }
                }
                if (root->option == 0){
                    if (root->op_name[0] == '+'){
                        fprintf(fout, "%c%d = %c%d\n", root->var_prefix, root->var_id, root->head_son->var_prefix, root->head_son->var_id);
                    }
                    else{
                        fprintf(fout, "%c%d = %s%c%d\n", root->var_prefix, root->var_id, root->op_name, root->head_son->var_prefix, root->head_son->var_id);
                    }
                }
                else{
                    if ((next_ret_param.dimension_match) || ((root->father->node_type == TP_STMT) && (root->father->head_son == root) && (root->father->option == 0))){
                        fprintf(fout, "%c%d = %c%d + %c%d\n", root->var_prefix, root->var_id, root->head_son->var_prefix, root->head_son->var_id, root->tail_son->var_prefix, root->tail_son->var_id);
                    }
                    else{
                        fprintf(fout, "%c%d = %c%d[%c%d]\n", root->var_prefix, root->var_id, root->head_son->var_prefix, root->head_son->var_id, root->tail_son->var_prefix, root->tail_son->var_id);
                    }
                }
                break;
            }
            
            case TP_BINARY_EXP:{
                if ((root->op_name[0] == '|') || (root->op_name[0] == '&')){
                    if (!dfs_generate(root->head_son, fout, &next_prov_param, &next_ret_param)){
                        return 0;
                    }
                    int label = new_label();
                    int pref_val = root->op_name[0] == '|'? 1: 0;
                    fprintf(fout, "%c%d = %c%d\n", root->var_prefix, root->var_id, root->head_son->var_prefix, root->head_son->var_id);

                    fprintf(fout, "if %c%d == %d goto l%d\n", root->var_prefix, root->var_id, pref_val, label);
                    if (!dfs_generate(root->tail_son, fout, &next_prov_param, &next_ret_param)){
                        return 0;
                    }
                    fprintf(fout, "%c%d = %c%d\n", root->var_prefix, root->var_id, root->tail_son->var_prefix, root->tail_son->var_id);
                    fprintf(fout, "l%d:\n", label);
                }

                else{
                    for (son = root->head_son; son != NULL; son = son->next_sib){
                        if (!dfs_generate(son, fout, &next_prov_param, &next_ret_param)){
                            return 0;
                        }
                    }

                    fprintf(fout, "%c%d = %c%d %s %c%d\n", root->var_prefix, root->var_id, root->head_son->var_prefix, root->head_son->var_id, root->op_name,root->tail_son->var_prefix, root->tail_son->var_id);
                }
                break;
            }
            case TP_STMT:{
                if ((root->option <= 2) || (root->option >= 8)){
                    for (son = root->head_son; son != NULL; son = son->next_sib){
                        if (!dfs_generate(son, fout, &next_prov_param, &next_ret_param)){
                            return 0;
                        }
                    }
                    if (root->option == 0){
                        if (root->head_son->option == 1){   // indexing
                            fprintf(fout, "%c%d[0] = %c%d\n", root->head_son->var_prefix, root->head_son->var_id, root->tail_son->var_prefix, root->tail_son->var_id);
                        }
                        else{
                            fprintf(fout, "%c%d = %c%d\n", root->head_son->var_prefix, root->head_son->var_id, root->tail_son->var_prefix, root->tail_son->var_id);
                        }
                    }
                    else if (root->option == 8){
                        fprintf(fout, "return\n");
                    }
                    else if (root->option == 9){
                        fprintf(fout, "return %c%d\n", root->head_son->var_prefix, root->head_son->var_id);
                    }
                }
                else{
                    if ((root->option == 3) || (root->option == 4)){
                        if (!dfs_generate(root->head_son, fout, &next_prov_param, &next_ret_param)){
                            return 0;
                        }
                        int label = new_label();
                        fprintf(fout, "if %c%d == 0 goto l%d\n", root->head_son->var_prefix, root->head_son->var_id, label);
                        if (!dfs_generate(root->head_son->next_sib, fout, &next_prov_param, &next_ret_param)){
                            return 0;
                        }
                        int label_else;
                        if (root->option == 4){
                            label_else = new_label();
                            fprintf(fout, "goto l%d\n", label_else);
                        }
                        fprintf(fout, "l%d:\n", label);
                        if (root->option == 4){
                            if (!dfs_generate(root->tail_son, fout, &next_prov_param, &next_ret_param)){
                                return 0;
                            }
                            fprintf(fout, "l%d:\n", label_else);
                        }
                    }
                    else if (root->option == 5){
                        root->label_while_bg = new_label();
                        root->label_while_ed = new_label();
                        fprintf(fout, "l%d:\n", root->label_while_bg);
                        if (!dfs_generate(root->head_son, fout, &next_prov_param, &next_ret_param)){
                            return 0;
                        }
                        fprintf(fout, "if %c%d == 0 goto l%d\n", root->head_son->var_prefix, root->head_son->var_id, root->label_while_ed);
                        if (!dfs_generate(root->head_son->next_sib, fout, &next_prov_param, &next_ret_param)){
                            return 0;
                        }
                        fprintf(fout, "goto l%d\n", root->label_while_bg);
                        fprintf(fout, "l%d:\n", root->label_while_ed);
                    }
                    else{
                        for (Syntax_Tree* father = root->father; father != NULL; father = father->father){
                            if ((father->node_type == TP_STMT) && (father->option == 5)){ // while
                                if (root->option == 6){
                                    fprintf(fout, "goto l%d\n", father->label_while_ed);
                                }
                                else{
                                    fprintf(fout, "goto l%d\n", father->label_while_bg);
                                }
                                break;
                            }
                        }
                    }
                }
                break;
            }

            case TP_DECL:{
                for (son = root->head_son; son != NULL; son = son->next_sib){
                    if (!dfs_generate(son, fout, &next_prov_param, &next_ret_param)){
                        return 0;
                    }
                }
                break;
            }
            case TP_DEF:{
                if ((root->option & 1) && ((root->option & 4) == 0)){
                    if (root->tail_son->option == 0){
                        if (!dfs_generate(root->tail_son->head_son, fout, &next_prov_param, &next_ret_param)){
                            return 0;
                        }
                        fprintf(fout, "T%d = %c%d\n", root->head_son->var_id, root->tail_son->head_son->var_prefix, root->tail_son->head_son->var_id);
                    }
                    else{
                        next_prov_param.init_target_var = &original_var_attrib[root->head_son->var_id];
                        next_prov_param.dimension = 0;
                        next_prov_param.offset = 0;
                        if (!dfs_generate(root->tail_son, fout, &next_prov_param, &next_ret_param)){
                            return 0;
                        }
                    }
                }
                break;
            }

            case TP_INIT_VAL:{
                int cur_offset = prov_param->offset;
                int step = 1;
                cur_var = prov_param->init_target_var;
                for (int i = prov_param->dimension + 1; i < cur_var->index_array_len; i++){
                    step *= cur_var->index_array[i];
                }

                for (son = root->head_son; son != NULL; son = son->next_sib){
                    if (son->node_type != TP_INIT_VAL){
                        if (!dfs_generate(son, fout, &next_prov_param, &next_ret_param)){
                            return 0;
                        }
                        fprintf(fout, "T%d[%d] = %c%d\n", prov_param->init_target_var->var_id, cur_offset * 4, son->var_prefix, son->var_id);
                        cur_offset++;
                    }
                    else{
                        next_prov_param.offset = cur_offset;
                        next_prov_param.dimension = prov_param->dimension + 1;
                        next_prov_param.init_target_var = cur_var;
                        if (!dfs_generate(son, fout, &next_prov_param, &next_ret_param)){
                            return 0;
                        }
                        cur_offset += son->option == 1? step: 1;
                    }
                }
                break;
            }
            default:
                break;
        }
    }
    return 1;
}

void delete_variable(Syntax_Tree* root){
    Syntax_Tree* son;
    for (son = root->head_son; son != NULL; son = son->next_sib){
        if (son->node_type == TP_DEF){
            delete_insert_key(son->head_son->ident_name);
        }
        else if (son->node_type == TP_DECL){
            for (Syntax_Tree* grandson = son->head_son; grandson != NULL; grandson = grandson->next_sib){
                delete_insert_key(grandson->head_son->ident_name);
            }
        }
    }
}

void dfs_declaration(Syntax_Tree* root, int is_declare, int is_fparam){
    if (root->node_type == TP_DEF){
        is_declare = 1;
    }
    else if (root->node_type == TP_FUNC_DEF){
        param_var_id = -1;
    }
    if ((root->father != NULL) && (root->father->node_type == TP_DEF) && (root->node_type == TP_TOKEN) && (root->token_type == TOK_IDENT)){
        if (is_fparam){
            root->var_id = new_param_var();
            root->fake_id = fake_param_var_id;
            root->var_prefix = 'p';
        }
        else{
            root->var_id = new_original_var();
            root->fake_id = root->var_id;
            root->var_prefix = 'T';
        }
        __wrap_insert_key(root->ident_name, root->var_id, root->fake_id, root->var_prefix);
    }
    else if ((root->node_type == TP_TOKEN) && (root->token_type == TOK_IDENT)){
        Hash_Bucket* cur_bucket = hash_find_buc(root->ident_name);
        if (cur_bucket != NULL){
            root->var_id = cur_bucket->var_list_head->var_id;
            root->fake_id = cur_bucket->var_list_head->fake_id;
            root->var_prefix = cur_bucket->var_list_head->prefix;
        }
    }

    Syntax_Tree* son;
    for (son = root->head_son; son != NULL; son = son->next_sib){
        dfs_declaration(son, is_declare & (son->node_type != TP_INIT_VAL), is_fparam | ((root->node_type == TP_FUNC_DEF) && (son->next_sib != NULL)));
    }

    if ((root->node_type == TP_BINARY_EXP) || (root->node_type == TP_UNARY_EXP)){
        if (root->op_name != NULL){
            switch (root->op_name[0]){
                case '+':
                    if (root->node_type == TP_UNARY_EXP){
                        root->dec_val = root->head_son->dec_val;
                    }
                    else{
                        root->dec_val = root->head_son->dec_val + root->tail_son->dec_val;
                    }
                    break;
                case '-':
                    if (root->node_type == TP_UNARY_EXP){
                        root->dec_val = -root->head_son->dec_val;
                    }
                    else{
                        root->dec_val = root->head_son->dec_val - root->tail_son->dec_val;
                    }
                    break;
                case '*':
                    root->dec_val = root->head_son->dec_val * root->tail_son->dec_val;
                    break;
                case '/':
                    root->dec_val = root->tail_son->dec_val? root->head_son->dec_val / root->tail_son->dec_val: 0;
                    break;
                case '%':
                    root->dec_val = root->tail_son->dec_val? root->head_son->dec_val % root->tail_son->dec_val: 0;
                    break;
                case '&':
                    root->dec_val = root->head_son->dec_val && root->tail_son->dec_val;
                    break;
                case '|':
                    root->dec_val = root->head_son->dec_val || root->tail_son->dec_val;
                    break;
                case '!':
                    if (strlen(root->op_name) == 1){
                        root->dec_val = !root->head_son->dec_val;
                    }
                    else{
                        root->dec_val = root->head_son->dec_val != root->tail_son->dec_val;
                    }
                    break;
                case '=':
                    root->dec_val = root->head_son->dec_val == root->tail_son->dec_val;
                    break;
                case '>':
                    if (strlen(root->op_name) == 1){
                        root->dec_val = root->head_son->dec_val > root->tail_son->dec_val;
                    }
                    else{
                        root->dec_val = root->head_son->dec_val >= root->tail_son->dec_val;
                    }
                    break;
                case '<':
                    if (strlen(root->op_name) == 1){
                        root->dec_val = root->head_son->dec_val < root->tail_son->dec_val;
                    }
                    else{
                        root->dec_val = root->head_son->dec_val <= root->tail_son->dec_val;
                    }
                    break;
            }
        }
    }
    if (!is_declare){
        if ((root->node_type == TP_BINARY_EXP) || (root->node_type == TP_UNARY_EXP) ||
        ((root->node_type == TP_TOKEN) && (root->token_type == TOK_DEC))){
        root->var_prefix = 't';
        root->var_id = new_temp_var();
        root->fake_id = root->var_id;
        }
        else if ((root->node_type == TP_INDEXES) && (root->restric == NONCONST_REST)){
            root->var_prefix = 't';
            root->var_id = new_temp_var();
            root->fake_id = root->var_id;
        }
        else if (root->node_type == TP_FUNC_CALL){
            if ((root->father->node_type != TP_STMT) || (root->father->option != 1)){
                root->var_prefix = 't';
                root->var_id = new_temp_var();
                root->fake_id = root->var_id;
            }
        }
    } 
    

    if (root->node_type == TP_BLOCK){
        delete_variable(root);
    }
    else if ((root->node_type == TP_FUNC_DEF) && (root->option == 1)){ // function with parameter
        delete_variable(root->tail_son->prev_sib);
    }

    if (root->node_type == TP_DEF){
        Var_Attrib* cur_var;
        if (root->head_son->var_prefix == 'p'){
            cur_var = &param_attrib[root->head_son->fake_id];
        }
        else{
            cur_var = &original_var_attrib[root->head_son->var_id];
        }
        cur_var->fake_id = root->head_son->fake_id;
        cur_var->prefix = root->head_son->var_prefix;
        cur_var->var_id = root->head_son->var_id;

        if (root->restric == CONST_REST){
            cur_var->is_value = 1;
            cur_var->single_val = root->tail_son->head_son->dec_val; // const int a = 1;   init_val[0]
        }

        if (root->option & 2){
            cur_var->is_single = 0;
            int* cur_dimension;
            if (root->option & 4){
                cur_var->index_array = malloc(sizeof(int) * (root->head_son->next_sib->sons_cnt) + 1);
                cur_var->index_array_len = (root->head_son->next_sib->sons_cnt) + 1;
                cur_dimension = cur_var->index_array + 1;
                cur_var->index_array[0] = -1;
            }
            else{
                cur_var->index_array = malloc(sizeof(int) * (root->head_son->next_sib->sons_cnt));
                cur_var->index_array_len = (root->head_son->next_sib->sons_cnt);
                cur_dimension = cur_var->index_array;
            }
            for (son = root->head_son->next_sib->head_son; son != NULL; son = son->next_sib){
                *cur_dimension = son->dec_val;
                cur_dimension++;
            }
        }
        else{
            cur_var->is_single = 1;
        }
    }
    if ((root->node_type == TP_TOKEN) && (root->token_type == TOK_IDENT) && (!is_fparam)){
        Var_Attrib* cur_var;
        if (root->var_prefix == 'p'){
            cur_var = &param_attrib[root->fake_id];
        }
        else{
            cur_var = &original_var_attrib[root->var_id];
        }
        if (cur_var->is_value){
            root->dec_val = cur_var->single_val;
        }
    }
}

static int dfs_count_def(Syntax_Tree* root){
    int res = 0;
    if (root->node_type == TP_DEF){
        res++;
    }
    for (Syntax_Tree* son = root->head_son; son != NULL; son = son->next_sib){
        res += dfs_count_def(son);
    }
    return res;
}

// int get_max_param(Syntax_Tree* root){
//     int res = 0;
//     if (root->node_type == TP_FUNC_FPARAM){
//         res = root->sons_cnt;
//     }
//     for (Syntax_Tree* son = root->head_son; son != NULL; son = son->next_sib){
//         int son_res = get_max_param(son);
//         if (res < son_res){
//             res = son_res;
//         }
//     }
//     return res;
// }

void recursive_func_register(Syntax_Tree* root){
    if (root->node_type == TP_FUNC_DEF){
        func_regist(root->head_son->next_sib->ident_name, root->head_son->token_type == TOK_INT);
        return;
    }
    else{
        for (Syntax_Tree* son = root->head_son; son != NULL; son = son->next_sib){
            recursive_func_register(son);
        }
    }
}

void generate_eeyore(Syntax_Tree* root, FILE* fout){
    tree_root = root;

    temp_var_id = 0;
    fprintf(fout, "var t0\n");

    func_regist("getint", 1);
    func_regist("getch", 1);
    func_regist("getarray", 1);
    func_regist("putint", 0);
    func_regist("putarray", 0);
    func_regist("putch", 0);
    func_regist("putf", 0);
    func_regist("starttime", 0);
    func_regist("stoptime", 0);

    recursive_func_register(root);

    forward_const_label(root);
    // if (!check_const(root)){
    //     return;
    // }

    int tot_var = 0;
    tot_var = dfs_count_def(root);
    init_var_table(tot_var, tot_var);

    dfs_declaration(root, 0, 0);
    

    Prov_Params next_prov_param;
    Ret_Params next_ret_param;
    memset(&next_prov_param, 0, sizeof(next_prov_param));
    memset(&next_ret_param, 0, sizeof(next_ret_param));
    dfs_generate(root, fout, &next_prov_param, &next_ret_param);

    delete_func_reg_table();
    hash_table_clear();
    destroy_var_table();
}