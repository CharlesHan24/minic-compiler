#include "./syntax_tree.h"
#include <malloc.h>
#include <string.h>

static int tree_node_id = 0;

Syntax_Tree* new_node(enum Restriction restric, enum Node_Type node_type,
    int option, enum Token_Type token_type, unsigned dec_val, char* ident_name, char* op_name){
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
    if (op_name != NULL){
        int len = strlen(op_name);
        node->op_name = malloc(len + 1);
        memcpy(node->op_name, op_name, len);
    }
    else{
        node->op_name = NULL;
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
    if (node->op_name != NULL){
        free(node->op_name);
    }
    Syntax_Tree* sons;
    Syntax_Tree* nxt_sons;
    for (sons = node->head_son; sons != NULL; sons = nxt_sons){
        nxt_sons = sons->next_sib;
        destruct_tree_completely(sons);
    }

    free(node);
}

static void dfs_label(Syntax_Tree* root){
    tree_node_id++;
    root->node_id = tree_node_id;
    for (Syntax_Tree* son = root->head_son; son != NULL; son = son->next_sib){
        dfs_label(son);
    }
}

static void dfs_print(Syntax_Tree* root){
    printf("ID: %d, Type: ", root->node_id);
    switch (root->node_type){
        case TP_COMP_UNIT:
            printf("COMP_UNIT ");
        case TP_BINARY_OP:
            printf("BINARY_OP ");
        case TP_UNARY_OP:
            printf("UNARY_OP");
        case TP_DECL:
            printf("DECL ");
        case TP_DEF:
            printf("DEF ");
        case TP_INDEXES:
            printf("INDEXES ");
        case TP_INIT_VAL:
            printf("INIT_VAL ");
        case TP_FUNC_DEF:
            printf("FUNC_DEF ");
        case TP_FUNC_FPARAM:
            printf("FUNC_FPARAM ");
        case TP_BLOCK:
            printf("BLOCK ");
        case TP_STMT:
            printf("STMT ");
        case TP_FUNC_CALL: 
            printf("FUNC_CALL ");
        case TP_TOKEN:
            printf("TOKEN");
        default:;
    }
    printf("Option: %d, const_or_not: %d, token_type: %d, ident_name: %s, op_name, %s", root->option, root->restric, root->token_type, root->ident_name, root->op_name);

    for (Syntax_Tree* son = root->head_son; son != NULL; son = son->next_sib){
        dfs_print(son);
    }
}

void print_tree(Syntax_Tree* root){
    tree_node_id = 0;
    dfs_label(root);

    dfs_print(root);
}