#ifndef _EEYORE_PARSER_H
#define _EEYORE_PARSER_H

#include <stdio.h>
#include <stdlib.h>

enum eey_op_type{
    EEY_RETURN,
    EEY_EXP,
    EEY_IF_GOTO,
    EEY_GOTO,
    EEY_LABEL,
    EEY_PARAM,
    EEY_FUNC_CALL
};

enum eey_var_option{
    EEY_VAR_ARRAY,
    EEY_VAR_INT,
    EEY_VAR_CONST
};

enum eey_exp_option{
    EEY_LOAD,
    EEY_STORE,
    EEY_ASSIGN,
    EEY_ARITH,
    EEY_SG_OP
};

typedef struct eeyore_vars{
    enum eey_var_option option;
    int var_val;
    int length;
    char var_type;
    int var_id;
    char index_var_type;
    int index_var_id;
    struct eeyore_vars* next;
}eeyore_vars;

typedef struct eeyore_instruct{
    enum eey_op_type op_type;
    enum eey_exp_option option;
    eeyore_vars* vars[3];
    char* arith;
    char* func_call_name;
    char* label_name;
    struct eeyore_instruct* next;
}eeyore_instruct;

typedef struct eeyore_function{
    eeyore_vars* vars;
    eeyore_instruct* instructs;
    int param_cnt;
    int ints_of_vars;
    int max_var_id;
    char* func_name;
    struct eeyore_function* next;
}eeyore_function;

typedef struct eeyore_program{
    eeyore_vars* global_vars;
    eeyore_function* functions;
    int num_of_functions;
    int max_var_id;
    // int max_var_id[3];
}eeyore_program;



void eeyore_parser(FILE*);

#endif