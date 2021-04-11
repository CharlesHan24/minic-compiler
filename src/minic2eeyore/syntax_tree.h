#ifndef _SYNTAX_TREE_H
#define _SYNTAX_TREE_H

#include "./constants.h"



enum Restriction{
    NONCONST_REST,
    CONST_REST,
};


typedef struct Syntax_Tree{
    struct Syntax_Tree* father;
    struct Syntax_Tree* next_sib;
    struct Syntax_Tree* prev_sib;
    struct Syntax_Tree* head_son;
    struct Syntax_Tree* tail_son;
    int sons_cnt;

    enum Restriction restric;
    enum Node_Type node_type;
    enum Token_Type token_type;
    int option;
    
    int dec_val;
    char* ident_name;
    char* op_name;
    int node_id;

    char var_prefix;
    int var_id;
    int fake_id;

    int label_while_bg;
    int label_while_ed;
}Syntax_Tree;

Syntax_Tree* new_node(enum Restriction restric, enum Node_Type node_type, 
    int option, enum Token_Type token_type, unsigned dec_val, char* ident_name, char* op_name);

void insert_sons(Syntax_Tree* cur_node, Syntax_Tree* targ_node, int flag);

void print_tree(Syntax_Tree* root);

void forward_const_label(Syntax_Tree* root);

void destruct_tree_completely(Syntax_Tree* node);

#endif