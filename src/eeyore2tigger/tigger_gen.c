#include "tigger_gen.h"
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "utils.h"

extern eeyore_program program;
#define BUFFER_LEN 1000

static void eey_new_tab(eey_localvar* var, int is_reg, int address, char prefix, int id){
    var->is_reg = is_reg;
    var->address = address;
    var->reg_name[0] = prefix;
    sprintf(var->reg_name + 1, "%d", id);
}

static void tigger_load_var(FILE* fout, eeyore_vars* var, eeyore_context* context, const char* assigned_reg, char* result){
    if (var->option == EEY_VAR_CONST){
        sprintf(result, "%d", var->var_val);
        return;
    }
    if (context->symtab.max_localvar_id > var->var_id){
        if (context->symtab.local_var[var->var_type][var->var_id].is_reg == 1){
            sprintf(result, "%s", context->symtab.local_var[var->var_type][var->var_id].reg_name);
            return;
        }
        else if (context->symtab.local_var[var->var_type][var->var_id].is_reg == 0){
            fprintf(fout, "load %s %s\n", context->symtab.local_var[var->var_type][var->var_id].address, assigned_reg);
            sprintf(result, "%s", assigned_reg);
            return;
        }
    }
    
    // global var
    fprintf(fout, "load v%s %s\n", context->symtab.global_var[var->var_type][var->var_id], assigned_reg);
    sprintf(result, "%s", assigned_reg);
}

static int tigger_reg(FILE* fout, eeyore_vars* var, eeyore_context* context, char* result){
    if ((var->option == EEY_VAR_INT) && (context->symtab.max_localvar_id > var->var_id)){
        if (context->symtab.local_var[var->var_type][var->var_id].is_reg == 1){
            sprintf(result, "%s", context->symtab.local_var[var->var_type][var->var_id].reg_name);
            return 1;
        }
    }
    return 0;
}

static void tigger_store_var(FILE* fout, eeyore_vars* var, eeyore_context* context, const char* assigned_reg){
    if (context->symtab.max_localvar_id > var->var_id){
        if (context->symtab.local_var[var->var_type][var->var_id].is_reg == 1){
            // do nothing because it has already been in the register
            return;
        }
        else if (context->symtab.local_var[var->var_type][var->var_id].is_reg == 0){
            fprintf(fout, "store %s %s\n", assigned_reg, context->symtab.local_var[var->var_type][var->var_id].address);
            return;
        }
    }
    
    // global var
    fprintf(fout, "store %s v%s\n", assigned_reg, context->symtab.global_var[var->var_type][var->var_id]);
}

static int tigger_load_array(FILE* fout, eeyore_vars* var, eeyore_context* context, const char* assigned_reg){
    eeyore_vars tmp_var;
    char tmp_result[50];
    if (var->length == -1){
        tmp_var.option = EEY_VAR_INT;
        tmp_var.var_type = var->index_var_type;
        tmp_var.var_id = var->index_var_id;
        tigger_load_var(fout, &tmp_var, context, "s11", tmp_result);
    }
    if (context->symtab.max_localvar_id > var->var_id){
        if (context->symtab.local_var[var->var_type][var->var_id].is_reg == 0){
            if (var->length == -1){
                fprintf(fout, "%s = %s + %d\n", assigned_reg, tmp_result, context->symtab.local_var[var->var_type][var->var_id].address);
                return 1;
            }
            else{
                fprintf(fout, "load %d %s\n", context->symtab.local_var[var->var_type][var->var_id].address + (var->length >> 2), assigned_reg);
                return 0;
            }
        }
    }
    
    // global var

    fprintf(fout, "loadaddr v%s %s\n", context->symtab.global_var[var->var_type][var->var_id], assigned_reg);

    if (var->length == -1){
        fprintf(fout, "%s = %s + %s\n", assigned_reg, assigned_reg, tmp_result);
        return 1;
    }
    else{
        fprintf(fout, "%s = %s + %d\n", assigned_reg, assigned_reg, (var->length));
        return 1;
    }
}

static void tigger_store_array(FILE* fout, eeyore_vars* var, eeyore_context* context, const char* assigned_reg){
    eeyore_vars tmp_var;
    char tmp_result[50];
    if (var->length == -1){
        tmp_var.option = EEY_VAR_INT;
        tmp_var.var_type = var->index_var_type;
        tmp_var.var_id = var->index_var_id;
        tigger_load_var(fout, &tmp_var, context, "s11", tmp_result);
    }
    if (context->symtab.max_localvar_id > var->var_id){
        if (context->symtab.local_var[var->var_type][var->var_id].is_reg == 0){
            if (var->length == -1){
                fprintf(fout, "s11 = %s + %d\n", tmp_result, context->symtab.local_var[var->var_type][var->var_id].address);
                fprintf(fout, "s11[0] = %s\n", assigned_reg);
            }
            else{
                fprintf(fout, "store %s %d\n", assigned_reg, context->symtab.local_var[var->var_type][var->var_id].address + (var->length >> 2));
            }
            return;
        }
    }

    fprintf(fout, "loadaddr v%s s10\n", context->symtab.global_var[var->var_type][var->var_id]);

    if (var->length == -1){
        fprintf(fout, "s11 = s10 + %s\n", tmp_result);
        fprintf(fout, "s11[0] = %s\n", assigned_reg);
    }
    else{
        fprintf(fout, "s11 = s10 + %d\n", var->length);
        fprintf(fout, "s11[0] = %s\n", assigned_reg);
    }
}

static void tigger_gen_func(eeyore_function* function, eeyore_context* context, FILE* fout){
    for (int i = 0; i < 3; i++){
        context->symtab.local_var[i] = calloc(function->max_var_id, sizeof(eey_localvar));
        for (int j = 0; j < function->max_var_id; j++){
            context->symtab.local_var[i][j].is_reg = -1;
        }
        context->symtab.max_localvar_id = function->max_var_id;
    }
    for (int i = 0; i < function->param_cnt; i++){
        eey_new_tab(&context->symtab.local_var[2][i], 1, 0, 'a', i);
    }

    // register allocation
    int num_of_reg = 0;
    int cur_address = 0;
    int param_id = 0;
    char buffer[3][BUFFER_LEN];

    for (eeyore_vars* var = function->vars; var != NULL; var = var->next){
        if (var->option == EEY_VAR_ARRAY){
            eey_new_tab(&context->symtab.local_var[var->var_type][var->var_id], 0, cur_address >> 2, 0, 0);
            cur_address += var->length;
        }
        else if (num_of_reg == 6){
            eey_new_tab(&context->symtab.local_var[var->var_type][var->var_id], 0, cur_address >> 2, 0, 0);
            cur_address += 4;
        }
        else{
            eey_new_tab(&context->symtab.local_var[var->var_type][var->var_id], 0, 0, 't', num_of_reg);
        }
    }
    
    fprintf(fout, "f_%s [%d] [%d]\n", function->func_name, function->param_cnt, (cur_address >> 2) + num_of_reg);
    // caller saved
    for (int i = 0; i < num_of_reg; i++){
        fprintf(fout, "store t%d %d\n", i, (cur_address >> 2) + i);
    }

    for (eeyore_instruct* instruct = function->instructs; instruct != NULL; instruct = instruct->next){
        switch (instruct->op_type){
            case EEY_RETURN:{
                // restore caller saved vars
                for (int i = 0; i < num_of_reg; i++){
                    fprintf(fout, "load %d t%d\n", (cur_address >> 2) + i, i);
                }
                if (instruct->vars[0] != NULL){
                    tigger_load_var(fout, instruct->vars[0], context, "a0", buffer[0]);
                }
                fprintf(fout, "return\n");
                break;
            }
            case EEY_LABEL:{
                fprintf(fout, "%s\n", instruct->label_name);
                break;
            }
            case EEY_GOTO:{
                fprintf(fout, "goto %s\n", instruct->label_name);
                break;
            }
            case EEY_IF_GOTO:{
                tigger_load_var(fout, instruct->vars[0], context, "s0", buffer[0]);
                tigger_load_var(fout, instruct->vars[1], context, "s0", buffer[1]);
                fprintf(fout, "if %s %s %s goto %s\n", buffer[0], instruct->arith, buffer[1], instruct->label_name);
                break;
            }
            case EEY_PARAM:{
                sprintf(buffer[1], "a%d", param_id++);
                tigger_load_var(fout, instruct->vars[0], context, buffer[1], buffer[0]);
                if (strcmp(buffer[0], buffer[1]) != 0){
                    fprintf(fout, "%s = %s\n", buffer[1], buffer[0]);
                }
                break;
            }
            case EEY_FUNC_CALL:{
                param_id = 0;
                fprintf(fout, "call %s\n", instruct->func_call_name);
                break;
            }
            case EEY_EXP:{
                if (instruct->option == EEY_ASSIGN){
                    tigger_load_var(fout, instruct->vars[1], context, "s0", buffer[0]);
                    if (!tigger_reg(fout, instruct->vars[0], context, buffer[1])){
                        sprintf(buffer[1], "s2");
                    }
                    fprintf(fout, "%s = %s\n", buffer[1], buffer[0]);
                    tigger_store_var(fout, instruct->vars[0], context, buffer[1]);
                }
                else if (instruct->option == EEY_SG_OP){
                    tigger_load_var(fout, instruct->vars[1], context, "s0", buffer[0]);
                    if (!tigger_reg(fout, instruct->vars[0], context, buffer[1])){
                        sprintf(buffer[1], "s2");
                    }
                    fprintf(fout, "%s = %s%s\n", buffer[1], instruct->arith, buffer[0]);
                    tigger_store_var(fout, instruct->vars[0], context, buffer[1]);
                }
                else if (instruct->option == EEY_ARITH){
                    tigger_load_var(fout, instruct->vars[1], context, "s0", buffer[0]);
                    tigger_load_var(fout, instruct->vars[2], context, "s1", buffer[1]);
                    
                    if (is_digit(buffer[0][0])){
                        fprintf(fout, "s0 = %s\n", buffer[0]);
                        sprintf(buffer[0], "s0");
                    }

                    if (!tigger_reg(fout, instruct->vars[0], context, buffer[2])){
                        sprintf(buffer[2], "s2");
                    }

                    fprintf(fout, "%s = %s %s %s\n", buffer[2], buffer[0], instruct->arith, buffer[1]);
                    tigger_store_var(fout, instruct->vars[0], context, buffer[2]);
                }
                else if (instruct->option == EEY_LOAD){
                    if (!tigger_reg(fout, instruct->vars[0], context, buffer[1])){
                        sprintf(buffer[1], "s2");
                    }
                    int res = tigger_load_array(fout, instruct->vars[1], context, "s1");
                    if (res){
                        fprintf(fout, "%s = s1[0]\n", buffer[1]);
                    }
                    else{
                        fprintf(fout, "%s = s1\n", buffer[1]);
                    }
                    tigger_store_var(fout, instruct->vars[0], context, buffer[2]);
                }
                else{
                    tigger_load_var(fout, instruct->vars[1], context, "s0", buffer[0]);
                    if (is_digit(buffer[0][0])){
                        fprintf(fout, "s0 = %s\n", buffer[0]);
                        sprintf(buffer[0], "s0");
                    }
                    tigger_store_array(fout, instruct->vars[0], context, "s0");
                }
            }
        }
    }

    fprintf(fout, "end f_%s\n", function->func_name);
}

void tigger_generator(FILE* fout){
    int global_id = 0;
    eeyore_context context;

    for (int i = 0; i < 2; i++){
        context.symtab.global_var[i] = calloc(program.max_var_id, 4);
        for (int j = 0; j < program.max_var_id; j++){
            context.symtab.global_var[i][j] = -1;
        }
    }

    for (eeyore_vars* var = program.global_vars; var != NULL; var = var->next){
        if (var->option == EEY_VAR_ARRAY){
            fprintf(fout, "v%d = malloc %d\n", global_id, var->length);
        }
        else{
            fprintf(fout, "v%d = 0\n", global_id);
        }
        context.symtab.global_var[var->var_type][var->var_id] = global_id;
        global_id++;
    }

    for (eeyore_function* function = program.functions; function != NULL; function = function->next){
        tigger_gen_func(function, &context, fout);
    }
}