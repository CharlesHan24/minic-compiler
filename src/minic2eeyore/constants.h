#ifndef _CONSTANTS_H
#define _CONSTANTS_H


enum Node_Type{
    TP_COMP_UNIT,
    TP_DECL,
    TP_DEF,
    TP_INDEXES,
    TP_INIT_VAL,
    TP_FUNC_DEF,
    TP_FUNC_FPARAM,
    TP_BLOCK,
    TP_STMT,
    TP_BINARY_OP,
    TP_UNARY_OP,
    TP_FUNC_CALL,
    TP_TOKEN,
};

enum Token_Type{
    TOK_SYNT,
    TOK_DEC,
    TOK_IDENT,
    TOK_INT,
    TOK_VOID,
    TOK_RETURN,
    TOK_WHILE,
    TOK_IF,
    TOK_ELSE,
    TOK_CONTINUE,
    TOK_BREAK,
    TOK_CONST,
    TOK_NONE,
};



#endif
