#ifndef _TIGGER_GEN_H
#define _TIGGER_GEN_H

#include "eeyore_parser.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct eey_localvar{
    int is_reg;
    int is_array;
    int address;
    char reg_name[4];
}eey_localvar;

typedef struct eey_symtab{
    int* global_var[2]; // Store the id. -1: does not exist
    int* global_is_array[2];
    eey_localvar* local_var[3];  // Store the address. is_reg == -1: does not exist
    int max_localvar_id;
}eey_symtab;

typedef struct eeyore_context{
    eey_symtab symtab;
    int in_func;
}eeyore_context;

void tigger_generator(FILE* fout);

#endif