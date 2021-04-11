#include "./syntax_tree.h"
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static int tree_node_id = 0;

Syntax_Tree* new_node(enum Restriction restric, enum Node_Type node_type,
    int option, enum Token_Type token_type, unsigned dec_val, char* ident_name, char* op_name){
    Syntax_Tree* node = calloc(1, sizeof(Syntax_Tree));

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
        cur_node->head_son = cur_node->tail_son = targ_node;
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
            break;
        case TP_BINARY_EXP:
            printf("BINARY_EXP ");
            break;
        case TP_UNARY_EXP:
            printf("UNARY_EXP ");
            break;
        case TP_DECL:
            printf("DECL ");
            break;
        case TP_DEF:
            printf("DEF ");
            break;
        case TP_INDEXES:
            printf("INDEXES ");
            break;
        case TP_INIT_VAL:
            printf("INIT_VAL ");
            break;
        case TP_FUNC_DEF:
            printf("FUNC_DEF ");
            break;
        case TP_FUNC_FPARAM:
            printf("FUNC_FPARAM ");
            break;
        case TP_BLOCK:
            printf("BLOCK ");
            break;
        case TP_STMT:
            printf("STMT ");
            break;
        case TP_FUNC_CALL: 
            printf("FUNC_CALL ");
            break;
        case TP_TOKEN:
            printf("TOKEN ");
            break;
        default:
            break;
    }
    printf("Option: %d, const_or_not: %d, token_type: %d, decimal_val: %u, ident_name: %s, op_name: %s ", root->option, root->restric, root->token_type, root->dec_val, root->ident_name, root->op_name);

    for (Syntax_Tree* son = root->head_son; son != NULL; son = son->next_sib){
        printf("%d ", son->node_id);
    }
    printf("\n");

    for (Syntax_Tree* son = root->head_son; son != NULL; son = son->next_sib){
        dfs_print(son);
    }
}

void print_tree(Syntax_Tree* root){
    tree_node_id = 0;
    dfs_label(root);

    dfs_print(root);
}

void forward_const_label(Syntax_Tree* root){
    Syntax_Tree* son;
    for (son = root->head_son; son != NULL; son = son->next_sib){
        if (root->restric == CONST_REST){
            son->restric = CONST_REST;
        }
        forward_const_label(son);
    }
}