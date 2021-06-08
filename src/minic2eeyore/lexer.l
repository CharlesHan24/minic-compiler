%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include <errno.h>
#include <ctype.h>
#include "y.tab.h"

extern FILE* yyin;
extern FILE* yyout;

int line_id = 1;


#define YY_INPUT(buf, result, max_size) \
    { \
    int c = getc(yyin); \
    result = (c == EOF) ? YY_NULL : (buf[0] = c, 1); \
    }


// there should be a space or \n
enum lexer_state{
    LEXER_NML,
    LEXER_SINGLE_LINE_COMMENT,
    LEXER_MULTI_LINE_COMMENT,
    LEXER_NEW_NUM,
};

enum lexer_state cur_state = LEXER_NML;

void print_error(){
    printf("Lexical error\n");
    exit(0);
}

void reset_lexer_state(){
    if (cur_state == LEXER_NEW_NUM){
        cur_state = LEXER_NML;
    }
}

int is_comment(){
    return (cur_state == LEXER_MULTI_LINE_COMMENT) || (cur_state == LEXER_SINGLE_LINE_COMMENT);
}

%}

SL_COMMENT \/\/
NEW_LINE \n|\t|\r|\v|\f
SPACE [ ]
ML_COMMENT_BGN \/\*
ML_COMMENT_END \*\/
KEYWORD if|else|return|while|int|void|break|continue|const

EXP_SYMB \+|-|\*|\/|%|==|!=|<|>|<=|>=|!|&&|(\|\|)|=
SYNT_SYMB \[|\]|\{|\}|\(|\)|;|,
DECIMAL 0x([a-f]|[0-9])+|0X([a-f]|[0-9])+|[0-9]+
VARIABLE [A-Za-z_][A-Za-z0-9_]*
OTHER_TEXT .

%option noyywrap

%%

{SL_COMMENT} {
    if (cur_state != LEXER_MULTI_LINE_COMMENT){
        cur_state = LEXER_SINGLE_LINE_COMMENT;
    }
}
{NEW_LINE} {
    line_id++;
    if (cur_state == LEXER_SINGLE_LINE_COMMENT){
        cur_state = LEXER_NML;
    }
    else if (cur_state == LEXER_NEW_NUM){
        reset_lexer_state();
    }
}
{SPACE} {
    if (cur_state == LEXER_NEW_NUM){
        reset_lexer_state();
    }
}
{ML_COMMENT_BGN} {
    if (cur_state != LEXER_SINGLE_LINE_COMMENT){
        cur_state = LEXER_MULTI_LINE_COMMENT;
    }
}
{ML_COMMENT_END} {
    if (cur_state == LEXER_MULTI_LINE_COMMENT){
        cur_state = LEXER_NML;
    }
    else if (cur_state != LEXER_SINGLE_LINE_COMMENT){
        print_error();
    }
}

{KEYWORD} {
    if (!is_comment()){
        if (cur_state == LEXER_NEW_NUM){
            print_error();
        }
        yylval.name = mystrdup(yytext);
        switch (yytext[0]){
            case 'w':{
                return WHILE;
            }
            case 'b':{
                return BREAK;
            }
            case 'e':{
                return ELSE;
            }
            case 'v':{
                return VOID;
            }
            case 'r':{
                return RETURN;
            }
            case 'c':{
                return yyleng == 8? CONTINUE: CONST;
            }
            case 'i':{
                return yyleng == 2? IF: INT;
            }
        }
    }
}
{EXP_SYMB} {
    if (!is_comment()){
        reset_lexer_state();
        yylval.name = mystrdup(yytext);
        switch (yytext[0]){
            case '+':{
                return ADDMIN_OP3;
            }
            case '-':{
                return ADDMIN_OP3;
            }
            case '*':
            case '/':
            case '%':{
                return MULDIV_OP2;
            }

            case '!':{
                return yyleng == 1? NOT_OP1: EQUAL_OP5;
            }
            case '>':
            case '<':{
                return COMP_OP4;
            }
            case '|':{
                return OR_OP7;
            }
            case '&':{
                return AND_OP6;
            }
            case '=':{
                return yyleng == 1? ASSIGN_OP8: EQUAL_OP5;
            }
        }
    }
}

{SYNT_SYMB} {
    if (!is_comment()){
        reset_lexer_state();
        yylval.name = mystrdup(yytext);
        switch (yytext[0]){
            case '[':{
                return L_SBRAC;
            }
            case ']':{
                return R_SBRAC;
            }
            case '(':{
                return L_PAR;
            }
            case ')':{
                return R_PAR;
            }
            case '{':{
                return L_CBRAC;
            }
            case '}':{
                return R_CBRAC;
            }
            case ',':{
                return COMMA;
            }
            case ';':{
                return COLON;
            }
        }
    }
}
{DECIMAL} {
    if (!is_comment()){
        long long res;
        int base;
        if ((yytext[0] == '0') && ((yytext[1] == 'x') || (yytext[1] == 'X'))){
            base = 16;
        }
        else if (yytext[0] == '0'){
            base = 8;
        }
        else{
            base = 10;
        }
        res = strtol(yytext, NULL, base);
        if ((errno == ERANGE) || (errno == EINVAL)){
            print_error();
        }
        if (res > (1l << 32)){
            print_error();
        }
        yylval.val = res;
        if (cur_state == LEXER_NML){
            cur_state = LEXER_NEW_NUM;
        }
        return DECIMAL_TOK;
    }
}

{VARIABLE} {
    if (!is_comment()){
        long cur_pos;
        cur_pos = ftell(yyin);
        cur_pos -= 1;
        fseek(yyin, cur_pos, SEEK_SET);
        char tmp;
        int meet_lpar = 0;
        while (1){
            if (fscanf(yyin, "%c", &tmp) == EOF){
                break;
            }
            
            if (tmp == '('){
                meet_lpar = 1;
                break;
            }
            if (!isspace(tmp)){
                break;
            }
        }

        if (cur_state == LEXER_NEW_NUM){
            print_error();
        }
        yylval.name = mystrdup(yytext);

        if (meet_lpar != 1){
            fseek(yyin, cur_pos + 1, SEEK_SET);
            
            return IDENT;
        }        
        yy_flush_buffer(*yy_buffer_stack);
        return IDENT_FUNC;
    }
}

{OTHER_TEXT} {
    if (!is_comment()){
        print_error();
    }
}

%%
/*
int main(){
    yylex();
    return 0;
}*/