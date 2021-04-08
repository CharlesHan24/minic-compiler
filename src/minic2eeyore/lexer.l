%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./constants.h"
#include <errno.h>
#include "y.tab.h"

int line_no = 1;

// there should be a space or \n
enum lexer_state{
    LEXER_NML,
    LEXER_SINGLE_LINE_COMMENT,
    LEXER_MULTI_LINE_COMMENT,
    LEXER_NEW_NUM,
};

enum lexer_state cur_state = LEXER_NML;

void yyerror(){
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
NEW_LINE \n
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
        cur_state = LEXER_MULTI_LINE_COMMENT;
    }
}
{NEW_LINE} {
    line_no++;
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
        cur_state = LEXER_SINGLE_LINE_COMMENT;
    }
}
{ML_COMMENT_END} {
    if (cur_state == LEXER_MULTI_LINE_COMMENT){
        cur_state = LEXER_NML;
    }
    else if (cur_state != LEXER_SINGLE_LINE_COMMENT){
        yyerror();
    }
}

{KEYWORD} {
    if (!is_comment()){
        if (cur_state == LEXER_NEW_NUM){
            yyerror();
        }
        yylval.name = strdup(yytext);
        switch (yytext[0]){
            case 'w':{
                return WHILE;
            }
            case 'b':{
                return BREAK;
            }
            case 'E':{
                return ELSE;
            }
            case 'V':{
                return VOID;
            }
            case 'R':{
                return RETURN;
            }
            case 'C':{
                return yyleng == 8? CONTINUE: CONST;
            }
            case 'I':{
                return yyleng == 2? IF: INT;
            }
        }
    }
}
{EXP_SYMB} {
    if (!is_comment()){
        reset_lexer_state();
        yylval.name = strdup(yytext);
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
                return OR_OP6;
            }
            case '&':{
                return AND_OP7;
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
        yylval.name = strdup(yytext);
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
        else if (yytext == '0'){
            base = 8;
        }
        else{
            base = 10;
        }
        res = strtol(yytext, NULL, base);
        if ((errno == ERANGE) || (errno == EINVAL)){
            yyerror();
        }
        if (res > (1l << 32)){
            yyerror();
        }
        yylval.value = res;
        if (cur_state == LEXER_NML){
            cur_state = LEXER_NEW_NUM;
        }
        return DECIMAL_TOK;
    }
}

{VARIABLE} {
    if (!is_comment()){
        if (cur_state == LEXER_NEW_NUM){
            yyerror();
        }
        yylval.name = strdup(yytext);
        return IDENT;
    }
}

{OTHER_TEXT} {
    if (!is_comment()){
        yyerror();
    }
}

%%

int main(){
    yylex();
    return 0;
}