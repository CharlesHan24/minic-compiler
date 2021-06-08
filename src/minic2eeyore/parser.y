%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "utils.h"
#include <errno.h>
#include "syntax_tree.h"
#include "name_hash.h"
#include "gen_eey.h"

//int yydebug = 1;
extern FILE* yyin;
extern FILE* yyout;

extern int yylex();
extern int line_id;

Syntax_Tree* tree_root;


void yyerror(char* s){
    fprintf(stderr, "Error at line #%d: %s\n", line_id, s);
    exit(0);
}

%}
//%define parse.error verbose

%union {
	unsigned val;
	char* name;
	struct Syntax_Tree* node;
};

%token <name> IF ELSE WHILE CONTINUE BREAK RETURN INT VOID CONST
%token <name> L_PAR R_PAR L_SBRAC R_SBRAC L_CBRAC R_CBRAC COMMA COLON   // ( ) [ ] { } , ;
%token <val> DECIMAL_TOK
%token <name> IDENT IDENT_FUNC

%left <name> NOT_OP1   // !
%left <name> MULDIV_OP2   // + -
%left <name> ADDMIN_OP3   // * / %
%left <name> COMP_OP4     // < > <= >= 
%left <name> EQUAL_OP5    // != =
%left <name> AND_OP6     // &&
%left <name> OR_OP7    // ||
%right <name> ASSIGN_OP8     // =


%type <node> COMP_UNIT DECL CONST_INDEXES VAR_INDEXES CONST_DECL CONST_DEFS CONST_DEF CONST_INIT_LIST
%type <node> CONST_INIT_VAL VAR_DECL VAR_DEFS VAR_DEF INIT_LIST INIT_VAL FUNC_DEF FUNC_TYPE 
%type <node> FUNC_FPARAMS FUNC_FPARAM BLOCK BLOCK_ITEMS BLOCK_ITEM STMT EXP COND LVAL PRIMARY_EXP
%type <node> UNARY_EXP UNARY_OP FUNC_RPARAMS MUL_EXP ADD_EXP REL_EXP EQ_EXP LAND_EXP LOR_EXP CONST_EXP 
%type <node> INTEGER IDENTIFIER IDENTIFIER_FUNC

%%
COMP_UNIT:  DECL 
        {
            $$ = new_node(NONCONST_REST, TP_COMP_UNIT, 0, 0, 0, NULL, NULL);
            tree_root = $$;
            insert_sons($$, $1, 0);
        }
    |       FUNC_DEF
        {
            $$ = new_node(NONCONST_REST, TP_COMP_UNIT, 0, 0, 0, NULL, NULL);
            tree_root = $$;
            insert_sons($$, $1, 0);
        }
    |       DECL COMP_UNIT
        {
            $$ = $2;
            tree_root = $$;
            insert_sons($$, $1, 0);
        }
    |       FUNC_DEF COMP_UNIT
        {
            $$ = $2;
            tree_root = $$;
            insert_sons($$, $1, 0);
        }
;
DECL:       CONST_DECL {$$ = $1;}
    |       VAR_DECL   {$$ = $1;}
;
CONST_INDEXES: L_SBRAC CONST_EXP R_SBRAC
        {
            $$ = new_node(CONST_REST, TP_INDEXES, 0, 0, 0, NULL, NULL);
            insert_sons($$, $2, 0);
        }
    |          L_SBRAC CONST_EXP R_SBRAC CONST_INDEXES
        {
            $$ = $4;
            insert_sons($$, $2, 0);
        }
;
VAR_INDEXES: L_SBRAC EXP R_SBRAC
        {
            $$ = new_node(NONCONST_REST, TP_INDEXES, 0, 0, 0, NULL, NULL);
            insert_sons($$, $2, 0);
        }
    |          L_SBRAC EXP R_SBRAC VAR_INDEXES
        {
            $$ = $4;
            insert_sons($$, $2, 0);
        }
;
CONST_DECL:  CONST INT CONST_DEFS COLON {$$ = $3;};
CONST_DEFS:  CONST_DEF
        {
            $$ = new_node(CONST_REST, TP_DECL, 0, 0, 0, NULL, NULL);
            insert_sons($$, $1, 0);
        }
    |        CONST_DEF COMMA CONST_DEFS
        {
            $$ = $3;
            insert_sons($$, $1, 0);
        }
;
CONST_DEF: IDENTIFIER ASSIGN_OP8 CONST_INIT_VAL
        {
            $$ = new_node(CONST_REST, TP_DEF, 1, 0, 0, NULL, $2);
            insert_sons($$, $3, 0);
            insert_sons($$, $1, 0);
        }
    |      IDENTIFIER CONST_INDEXES ASSIGN_OP8 CONST_INIT_VAL
        {
            $$ = new_node(CONST_REST, TP_DEF, 3, 0, 0, NULL, $3);
            insert_sons($$, $4, 0);
            insert_sons($$, $2, 0);
            insert_sons($$, $1, 0);
        }
;
CONST_INIT_VAL: CONST_EXP
        {
            $$ = new_node(CONST_REST, TP_INIT_VAL, 0, 0, 0, NULL, NULL);
            insert_sons($$, $1, 0);
        }
    |         L_CBRAC R_CBRAC
        {
            $$ = new_node(CONST_REST, TP_INIT_VAL, 1, 0, 0, NULL, NULL);
        }
    |         L_CBRAC CONST_INIT_LIST R_CBRAC
        {
            $$ = $2;
        }
;
CONST_INIT_LIST:  CONST_INIT_VAL
        {
            $$ = new_node(CONST_REST, TP_INIT_VAL, 1, 0, 0, NULL, NULL);
            insert_sons($$, $1, 0);
        }
    |            CONST_INIT_VAL COMMA CONST_INIT_LIST
        {
            $$ = $3;
            insert_sons($$, $1, 0);
        }
;
VAR_DECL: INT VAR_DEFS COLON {$$ = $2;}
;
VAR_DEFS:  VAR_DEF
        {
            $$ = new_node(NONCONST_REST, TP_DECL, 0, 0, 0, NULL, NULL);
            insert_sons($$, $1, 0);
        }
    |      VAR_DEF COMMA VAR_DEFS
        {
            $$ = $3;
            insert_sons($$, $1, 0);
        }
;
VAR_DEF: IDENTIFIER ASSIGN_OP8 INIT_VAL
        {
            $$ = new_node(NONCONST_REST, TP_DEF, 1, 0, 0, NULL, $2);
            insert_sons($$, $3, 0);
            insert_sons($$, $1, 0);
        }
    |      IDENTIFIER CONST_INDEXES ASSIGN_OP8 INIT_VAL
        {
            $$ = new_node(NONCONST_REST, TP_DEF, 3, 0, 0, NULL, $3);
            insert_sons($$, $4, 0);
            insert_sons($$, $2, 0);
            insert_sons($$, $1, 0);
        }
    |    IDENTIFIER
        {
            $$ = new_node(NONCONST_REST, TP_DEF, 0, 0, 0, NULL, NULL);
            insert_sons($$, $1, 0);
        }
    |      IDENTIFIER CONST_INDEXES
        {
            $$ = new_node(NONCONST_REST, TP_DEF, 2, 0, 0, NULL, NULL);
            insert_sons($$, $2, 0);
            insert_sons($$, $1, 0);
        }
;
INIT_VAL: EXP
        {
            $$ = new_node(NONCONST_REST, TP_INIT_VAL, 0, 0, 0, NULL, NULL);
            insert_sons($$, $1, 0);
        }
    |         L_CBRAC R_CBRAC
        {
            $$ = new_node(NONCONST_REST, TP_INIT_VAL, 1, 0, 0, NULL, NULL);
        }
    |         L_CBRAC INIT_LIST R_CBRAC
        {
            $$ = $2;
        }
;
INIT_LIST:  INIT_VAL
        {
            $$ = new_node(NONCONST_REST, TP_INIT_VAL, 1, 0, 0, NULL, NULL);
            insert_sons($$, $1, 0);
        }
    |            INIT_VAL COMMA INIT_LIST
        {
            $$ = $3;
            insert_sons($$, $1, 0);
        }
;
FUNC_DEF:   FUNC_TYPE IDENTIFIER_FUNC R_PAR BLOCK
        {
            $$ = new_node(NONCONST_REST, TP_FUNC_DEF, 0, 0, 0, NULL, NULL);
            insert_sons($$, $4, 0);
            insert_sons($$, $2, 0);
            insert_sons($$, $1, 0);
        }
    |       FUNC_TYPE IDENTIFIER_FUNC FUNC_FPARAMS R_PAR BLOCK
        {
            $$ = new_node(NONCONST_REST, TP_FUNC_DEF, 1, 0, 0, NULL, NULL);
            insert_sons($$, $5, 0);
            insert_sons($$, $3, 0);
            insert_sons($$, $2, 0);
            insert_sons($$, $1, 0);
        }
;
FUNC_TYPE:   INT
        {
            $$ = new_node(NONCONST_REST, TP_TOKEN, 0, TOK_INT, 0, NULL, NULL);
        }
    |        VOID
        {
            $$ = new_node(NONCONST_REST, TP_TOKEN, 0, TOK_VOID, 0, NULL, NULL);
        }
;
FUNC_FPARAMS: FUNC_FPARAM
        {
            $$ = new_node(NONCONST_REST, TP_FUNC_FPARAM, 0, 0, 0, NULL, NULL);
            insert_sons($$, $1, 0);
        }
    |        FUNC_FPARAM COMMA FUNC_FPARAMS
        {
            $$ = $3;
            insert_sons($$, $1, 0);
        }
;
FUNC_FPARAM:  INT IDENTIFIER
        {
            $$ = new_node(NONCONST_REST, TP_DEF, 4, 0, 0, NULL, NULL);
            insert_sons($$, $2, 0);
        }
    |         INT IDENTIFIER L_SBRAC R_SBRAC
        {
            $$ = new_node(NONCONST_REST, TP_DEF, 6, 0, 0, NULL, NULL);
            Syntax_Tree* tmp_node = new_node(NONCONST_REST, TP_INDEXES, 1, 0, 0, NULL, NULL);
            insert_sons($$, tmp_node, 0);
            insert_sons($$, $2, 0);
        }
    |         INT IDENTIFIER CONST_INDEXES
        {
            $$ = new_node(NONCONST_REST, TP_DEF, 6, 0, 0, NULL, NULL);
            insert_sons($$, $3, 0);
            insert_sons($$, $2, 0);
        }
    |         INT IDENTIFIER L_SBRAC R_SBRAC CONST_INDEXES
        {
            $$ = new_node(NONCONST_REST, TP_DEF, 6, 0, 0, NULL, NULL);
            $5->option = 1;
            insert_sons($$, $5, 0);
            insert_sons($$, $2, 0);
        }
;
BLOCK:     L_CBRAC BLOCK_ITEMS R_CBRAC
        {
            $$ = $2;
        }
;
BLOCK_ITEMS:   BLOCK_ITEM
        {
            $$ = new_node(NONCONST_REST, TP_BLOCK, 0, 0, 0, NULL, NULL);
            insert_sons($$, $1, 0);
        }
    |          BLOCK_ITEM BLOCK_ITEMS
        {
            $$ = $2;
            insert_sons($$, $1, 0);
        }
;
BLOCK_ITEM:     DECL {$$ = $1;}
    |           STMT {$$ = $1;}
;
STMT:    COLON
        {
            $$ = new_node(NONCONST_REST, TP_TOKEN, 0, TOK_NONE, 0, NULL, NULL);
        }
    |    LVAL ASSIGN_OP8 EXP COLON
        {
            $$ = new_node(NONCONST_REST, TP_STMT, 0, 0, 0, NULL, $2);
            insert_sons($$, $3, 0);
            insert_sons($$, $1, 0);
        }
    |   EXP COLON
        {
            $$ = new_node(NONCONST_REST, TP_STMT, 1, 0, 0, NULL, NULL);
            insert_sons($$, $1, 0);
        }
    |   BLOCK
        {
            $$ = new_node(NONCONST_REST, TP_STMT, 2, 0, 0, NULL, NULL);
            insert_sons($$, $1, 0);
        }
    |   IF L_PAR COND R_PAR STMT
        {
            $$ = new_node(NONCONST_REST, TP_STMT, 3, 0, 0, NULL, NULL);
            insert_sons($$, $5, 0);
            insert_sons($$, $3, 0);
        }
    |   IF L_PAR COND R_PAR STMT ELSE STMT
        {
            $$ = new_node(NONCONST_REST, TP_STMT, 4, 0, 0, NULL, NULL);
            insert_sons($$, $7, 0);
            insert_sons($$, $5, 0);
            insert_sons($$, $3, 0);
        }
    |   WHILE L_PAR COND R_PAR STMT
        {
            $$ = new_node(NONCONST_REST, TP_STMT, 5, 0, 0, NULL, NULL);
            insert_sons($$, $5, 0);
            insert_sons($$, $3, 0);
        }
    |   BREAK COLON
        {
            $$ = new_node(NONCONST_REST, TP_STMT, 6, 0, 0, NULL, NULL);
        }
    |   CONTINUE COLON
        {
            $$ = new_node(NONCONST_REST, TP_STMT, 7, 0, 0, NULL, NULL);
        }
    |   RETURN COLON
        {
            $$ = new_node(NONCONST_REST, TP_STMT, 8, 0, 0, NULL, NULL);
        }
    |   RETURN EXP COLON
        {
            $$ = new_node(NONCONST_REST, TP_STMT, 9, 0, 0, NULL, NULL);
            insert_sons($$, $2, 0);
        }
;
CONST_EXP: EXP {$$ = $1;}
;
EXP:      ADD_EXP {$$ = $1;}
;
ADD_EXP:   MUL_EXP {$$ = $1;}
    |      ADD_EXP ADDMIN_OP3 MUL_EXP
        {
            $$ = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, $2);
            insert_sons($$, $3, 0);
            insert_sons($$, $1, 0);
        }
;
MUL_EXP:   UNARY_EXP {$$ = $1;}
    |      MUL_EXP MULDIV_OP2 UNARY_EXP
        {
            $$ = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, $2);
            insert_sons($$, $3, 0);
            insert_sons($$, $1, 0);
        }
;
UNARY_EXP: PRIMARY_EXP {$$ = $1;}
    |      IDENTIFIER_FUNC R_PAR 
        {
            $$ = new_node(NONCONST_REST, TP_FUNC_CALL, 0, 0, 0, NULL, NULL);
            insert_sons($$, $1, 0);
        }
    |      IDENTIFIER_FUNC FUNC_RPARAMS R_PAR
        {
            $$ = $2;
            insert_sons($$, $1, 0);
        }
    |      UNARY_OP UNARY_EXP
        {
            $$ = new_node(NONCONST_REST, TP_UNARY_EXP, 0, 0, 0, NULL, $1->op_name);
            insert_sons($$, $2, 0);
        }
;
UNARY_OP: ADDMIN_OP3
        {
            // tmp
            $$ = new_node(0, 0, 0, 0, 0, NULL, $1);
        }
    |   NOT_OP1
        {
            $$ = new_node(0, 0, 0, 0, 0, NULL, $1);
        }
;
FUNC_RPARAMS: EXP
        {
            $$ = new_node(NONCONST_REST, TP_FUNC_CALL, 0, 0, 0, NULL, NULL);
            insert_sons($$, $1, 0);
        }
    |        EXP COMMA FUNC_RPARAMS
        {
            $$ = $3;
            insert_sons($$, $1, 0);
        }
;
PRIMARY_EXP: L_PAR EXP R_PAR {$$ = $2;}
    |        LVAL            {$$ = $1;}
    |        INTEGER         {$$ = $1;}
;
LVAL:       IDENTIFIER VAR_INDEXES
        {
            // option #2: indexing
            $$ = new_node(NONCONST_REST, TP_UNARY_EXP, 1, 0, 0, NULL, NULL);
            insert_sons($$, $2, 0);
            insert_sons($$, $1, 0);
        }
    |
            IDENTIFIER
        {
            $$ = $1;
        }
;
REL_EXP:     ADD_EXP {$$ = $1;}
    |       REL_EXP COMP_OP4 ADD_EXP
        {
            $$ = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, $2);
            insert_sons($$, $3, 0);
            insert_sons($$, $1, 0);
        }
;
EQ_EXP:      REL_EXP   {$$ = $1;}
    |        EQ_EXP EQUAL_OP5 REL_EXP
        {
            $$ = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, $2);
            insert_sons($$, $3, 0);
            insert_sons($$, $1, 0);
        }
;
COND: LOR_EXP {$$ = $1;}
;
LAND_EXP:   EQ_EXP {$$ = $1;}
    |      LAND_EXP AND_OP6   EQ_EXP
        {
            $$ = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, $2);
            insert_sons($$, $3, 0);
            insert_sons($$, $1, 0);
        }
;
LOR_EXP:    LAND_EXP {$$ = $1;}
    |      LOR_EXP   OR_OP7   LAND_EXP
        {
            $$ = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, $2);
            insert_sons($$, $3, 0);
            insert_sons($$, $1, 0);
        }
;
INTEGER:    DECIMAL_TOK
        {
            if ($1 == 444){
                $1++;
                $1--;
            }
            $$ = new_node(NONCONST_REST, TP_TOKEN, 0, TOK_DEC, $1, NULL, NULL);
        }
;
IDENTIFIER:    IDENT
        {
            $$ = new_node(NONCONST_REST, TP_TOKEN, 0, TOK_IDENT, 0, $1, NULL);
        }
;
IDENTIFIER_FUNC:    IDENT_FUNC
        {
            $$ = new_node(NONCONST_REST, TP_TOKEN, 0, TOK_IDENT, 0, $1, NULL);
        }
;

%%
void minic2eeyore(FILE* inp_file, FILE* oup_file){
    yyin = inp_file;

    tree_root = NULL;
    yyparse();

    generate_eeyore(tree_root, oup_file);

    destruct_tree_completely(tree_root);
}