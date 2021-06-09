#include "eeyore_parser.h"
#include "tigger_gen.h"
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "utils.h"

eeyore_program program;
#define BUFFER_LEN 1000

static eeyore_function* new_func(eeyore_function* nxt, int param_cnt, char* func_name){
    eeyore_function* res = calloc(1, sizeof(eeyore_function));
    res->next = nxt;
    res->param_cnt = param_cnt;
    res->func_name = mystrdup(func_name);
    return res;
}

static eeyore_vars* new_var(eeyore_vars* nxt, enum eey_var_option option, int var_val, int length, char var_type, int var_id, char index_var_type, int index_var_id){
    eeyore_vars* res = calloc(1, sizeof(eeyore_vars));
    res->next = nxt;
    res->option = option;
    res->length = length;
    res->var_id = var_id;
    res->var_type = var_type == 'T'? 0: (var_type == 't'? 1: 2);
    res->var_val = var_val;
    res->index_var_id = index_var_id;
    res->index_var_type = index_var_type == 'T'? 0: (index_var_type == 't'? 1: 2);
    return res;
}

static eeyore_instruct* new_instruct(eeyore_instruct* nxt, eeyore_vars** vars, enum eey_exp_option option, enum eey_op_type type, char* arith, char* func_call_name, char* label_name){
    eeyore_instruct* res = calloc(1, sizeof(eeyore_instruct));
    res->next = nxt;
    res->vars[0] = vars[0];
    res->vars[1] = vars[1];
    res->vars[2] = vars[2];
    res->option = option;
    res->op_type = type;
    res->arith = mystrdup(arith);
    res->func_call_name = mystrdup(func_call_name);
    res->label_name = mystrdup(label_name);
    return res;
}

static eeyore_vars* parse_var(char* word){
    if (is_digit(word[0])){
        return new_var(NULL, EEY_VAR_CONST, atoi(word), 0, 0, 0, 0, 0);
    }
    char var_type;
    int var_id;
    char index[50];
    int cnt;
    cnt = sscanf(word, "%c%d[%s]", &var_type, &var_id, index);
    if (cnt == 3){
        if (is_digit(index[0])){
            return new_var(NULL, EEY_VAR_ARRAY, 0, atoi(index), var_type, var_id, 0, 0);
        }
        else{
            return new_var(NULL, EEY_VAR_ARRAY, 0, -1, var_type, var_id, index[0], atoi(index + 1));
        }
    }
    else{
        return new_var(NULL, EEY_VAR_INT, 0, 0, var_type, var_id, 0, 0);
    }
}


void eeyore_parser(FILE* fin){
    char buffer[BUFFER_LEN];
    char words[10][BUFFER_LEN];
    eeyore_context context;
    eeyore_function* cur_func;
    eeyore_vars* tmp_var[3];

    context.in_func = 0;
    memset(&program, 0, sizeof(program));
    while (fgets(buffer, BUFFER_LEN, fin) != NULL){
        tmp_var[0] = tmp_var[1] = tmp_var[2] = NULL;
        if (buffer[0] == '\n'){
            continue;
        }
        sscanf(buffer, "%s", words[0]);
        switch (words[0][0]){
            case 'v':{
                int cnt = sscanf(buffer, "%s%s%s", words[0], words[1], words[2]);
                if (cnt == 2){
                    if (!context.in_func){
                        program.global_vars = new_var(program.global_vars, EEY_VAR_INT, 0, 0, words[1][0], atoi(words[1] + 1), 0, 0);
                        program.max_var_id = max(program.max_var_id, program.global_vars->var_id + 1);
                    }
                    else{
                        cur_func->vars = new_var(cur_func->vars, EEY_VAR_INT, 0, 0, words[1][0], atoi(words[1] + 1), 0, 0);
                        cur_func->ints_of_vars++;
                        cur_func->max_var_id = max(cur_func->max_var_id, cur_func->vars->var_id + 1);
                    }
                }
                else{
                    if (!context.in_func){
                        program.global_vars = new_var(program.global_vars, EEY_VAR_ARRAY, 0, atoi(words[1]), words[2][0], atoi(words[2] + 1), 0, 0);
                        program.max_var_id = max(program.max_var_id, program.global_vars->var_id + 1);
                    }
                    else{
                        cur_func->vars = new_var(cur_func->vars, EEY_VAR_ARRAY, 0, atoi(words[1]), words[2][0], atoi(words[2] + 1), 0, 0);
                        cur_func->ints_of_vars += atoi(words[1]) / 4;
                        cur_func->max_var_id = max(cur_func->max_var_id, cur_func->vars->var_id + 1);
                    }
                }
                break;
            }
            case 'f':{
                sscanf(buffer, "%s %s", words[0], words[1]);
                words[1][strlen(words[1]) - 1] = 0;
                program.functions = new_func(program.functions, atoi(words[1] + 1), words[0] + 2);
                cur_func = program.functions;
                cur_func->max_var_id = 8;
                context.in_func = 1;
                break;
            }
            case 'e':{
                context.in_func = 0;
                eeyore_instruct* cur_instruct;
                eeyore_instruct* next_instruct;
                eeyore_instruct* tmp;
                cur_instruct = cur_func->instructs;
                if (cur_instruct == NULL){
                    break;
                }
                next_instruct = cur_instruct->next;
                cur_instruct->next = NULL;
                while (next_instruct != NULL){
                    tmp = next_instruct->next;
                    next_instruct->next = cur_instruct;
                    cur_instruct = next_instruct;
                    next_instruct = tmp;
                }
                cur_func->instructs = cur_instruct;
                break;
            }
            case 'l':{
                cur_func->instructs = new_instruct(cur_func->instructs, tmp_var, 0, EEY_LABEL, NULL, NULL, words[0]);
                break;
            }
            case 'r':{
                int cnt = sscanf(buffer, "%s%s", words[0], words[1]);
                if (cnt == 1){
                    cur_func->instructs = new_instruct(cur_func->instructs, tmp_var, 0, EEY_RETURN, NULL, NULL, NULL);
                }
                else{
                    tmp_var[0] = parse_var(words[1]);
                    cur_func->instructs = new_instruct(cur_func->instructs, tmp_var, 0, EEY_RETURN, NULL, NULL, NULL);
                }
                break;
            }
            case 'g':{
                sscanf(buffer, "%s%s", words[0], words[1]);
                cur_func->instructs = new_instruct(cur_func->instructs, tmp_var, 0, EEY_GOTO, NULL, NULL, words[1]);
                break;
            }
            case 'p':{
                if (words[0][1] != 'a'){
                    goto l1;
                }
                sscanf(buffer, "%s%s", words[0], words[1]);
                tmp_var[0] = parse_var(words[1]);
                cur_func->instructs = new_instruct(cur_func->instructs, tmp_var, 0, EEY_PARAM, NULL, NULL, NULL);
                break;
            }
            case 'c':{
                sscanf(buffer, "%s%s", words[0], words[1]);
                cur_func->instructs = new_instruct(cur_func->instructs, tmp_var, 0, EEY_FUNC_CALL, NULL, words[1], NULL);
                break;
            }
            case 'i':{
                sscanf(buffer, "if %s %s %s goto %s", words[0], words[1], words[2], words[3]);
                tmp_var[0] = parse_var(words[0]);
                tmp_var[1] = parse_var(words[2]);
                cur_func->instructs = new_instruct(cur_func->instructs, tmp_var, 0, EEY_IF_GOTO, words[1], NULL, words[3]);
                break;
            }

            case 'T':
            case 't':{
                l1:;
                int cnt = sscanf(buffer, "%s = %s %s %s", words[0], words[1], words[2], words[3]);
                if (cnt == 4){
                    tmp_var[0] = parse_var(words[0]);
                    tmp_var[1] = parse_var(words[1]);
                    tmp_var[2] = parse_var(words[3]);
                    cur_func->instructs = new_instruct(cur_func->instructs, tmp_var, EEY_ARITH, EEY_EXP, words[2], NULL, NULL);
                }
                else if (cnt == 3){
                    tmp_var[0] = parse_var(words[0]);
                    cur_func->instructs = new_instruct(cur_func->instructs, tmp_var, 0, EEY_FUNC_CALL, NULL, words[2], NULL);
                }
                else if ((words[1][0] == '-') || (words[1][0] == '!')){
                    tmp_var[0] = parse_var(words[0]);
                    tmp_var[1] = parse_var(words[1] + 1);
                    words[1][1] = 0;
                    cur_func->instructs = new_instruct(cur_func->instructs, tmp_var, EEY_SG_OP, EEY_EXP,words[1], NULL, NULL);
                }
                else{
                    tmp_var[0] = parse_var(words[0]);
                    tmp_var[1] = parse_var(words[1]);
                    if (tmp_var[0]->option == EEY_VAR_ARRAY){
                        cur_func->instructs = new_instruct(cur_func->instructs, tmp_var, EEY_STORE, EEY_EXP, NULL, NULL, NULL);
                    }
                    else if (tmp_var[1]->option == EEY_VAR_ARRAY){
                        cur_func->instructs = new_instruct(cur_func->instructs, tmp_var, EEY_LOAD, EEY_EXP, NULL, NULL, NULL);
                    }
                    else{
                        cur_func->instructs = new_instruct(cur_func->instructs, tmp_var, EEY_ASSIGN, EEY_EXP, NULL, NULL, NULL);
                    }
                }
                break;
            }
        }
    }

    eeyore_function* cur_function;
    eeyore_function* next_function;
    eeyore_function* tmp;
    cur_function = program.functions;
    if (cur_function == NULL){
        return;
    }
    next_function = cur_function->next;
    cur_function->next = NULL;
    while (next_function != NULL){
        tmp = next_function->next;
        next_function->next = cur_function;
        cur_function = next_function;
        next_function = tmp;
    }
    program.functions = cur_function;
}
