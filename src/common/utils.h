#ifndef _UTILS_H
#define _UTILS_H

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
    TP_BINARY_EXP,
    TP_UNARY_EXP,
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

char* mystrdup(const char *str);
int is_digit(char x);

#endif
