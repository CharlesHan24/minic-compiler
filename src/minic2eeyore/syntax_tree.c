#include "./syntax_tree.h"
#include <malloc.h>
#include <string.h>

int tree_node_cnt = 0;

Syntax_Tree* new_node(enum Restriction restric, enum Node_Type node_type, enum Token_Type token_type, 
    int option, unsigned dec_val, char* ident_name, char* synt_name){
    Syntax_Tree* node = malloc(sizeof(Syntax_Tree));

    node->restric = restric;
    node->node_type = node_type;
    node->token_type = token_type;
    node->option = option;
    node->dec_val = dec_val;
    if (ident_name != NULL){
        int len = strlen(ident_name);
        node->ident_name = malloc(len + 1);
        memcpy(node->ident_name, ident_name, len);
    }
    else{
        node->ident_name = NULL;
    }
    if (synt_name != NULL){
        int len = strlen(synt_name);
        node->synt_name = malloc(len + 1);
        memcpy(node->synt_name, synt_name, len);
    }
    else{
        node->synt_name = NULL;
    }

    node->head_son = node->tail_son = NULL;
    node->next_sib = node->prev_sib = NULL;
    node->sons_cnt = 0;
    return node;
}

void insert_sons(Syntax_Tree* cur_node, Syntax_Tree* targ_node, int flag){
    targ_node->father = cur_node;
    if (cur_node->sons_cnt == 0){
        cur_node->sons_cnt = 1;
        cur_node->head_son = cur_node->tail_son = NULL;
        return;
    }
    if (flag == 1){    // insert to tail
        cur_node->tail_son->next_sib = targ_node;
        targ_node->prev_sib = cur_node->tail_son;
        cur_node->tail_son = targ_node;
        cur_node->sons_cnt++;
    }
    else{
        cur_node->head_son->prev_sib = targ_node;
        targ_node->next_sib = cur_node->head_son;
        cur_node->head_son = targ_node;
        cur_node->sons_cnt++;
    }
}

void destruct_tree_completely(Syntax_Tree* node){
    if (node->ident_name != NULL){
        free(node->ident_name);
    }
    if (node->synt_name != NULL){
        free(node->synt_name);
    }
    Syntax_Tree* sons;
    Syntax_Tree* nxt_sons;
    for (sons = node->head_son; sons != NULL; sons = nxt_sons){
        nxt_sons = sons->next_sib;
        destruct_tree_completely(sons);
    }

    free(node);
}