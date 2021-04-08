%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./constants.h"
#include <errno.h>
#include "./syntax_tree.h"
#include "./name_hash.h"
%}

%token <name> IF ELSE WHILE CONTINUE BREAK RETURN INT VOID CONST
%token <name> L_PAR R_PAR L_SBRAC R_SBRAC L_CBRAC R_CBRAC COMMA COLON   // ( ) [ ] { } , ;
%token <value> DECIMAL_TOK
%token <name> IDENT 

%left <name> NOT_OP1   // !
%left <name> ADDMIN_OP2   // + -
%left <name> MULDIV_OP3   // * / %
%left <name> COMP_OP4     // < > <= >= 
%left <name> EQUAL_OP5    // != =
%left <name> OR_OP6     // ||
%left <name> AND_OP7    // &&
%right <name> ASSIGN_OP8     // =


%type <node> COMP_UNIT DECL CONST_INDEXES VAR_INDEXES CONST_DECL CONST_DEFS CONST_DEF INDEX_DEF \
    CONST_INIT_LIST CONST_INIT_VAL VAR_DECL VAR_DEFS INIT_LIST INIT_VAL FUNC_DEF FUNC_TYPE \
    FUNC_FPARAMS FUNC_FPARAM BLOCK BLOCK_ITEMS BLOCK_ITEM STMT EXP COND LVAL PRIMARY_EXP \
    NUMBER UNARY_EXP UNARY_OP FUNC_RPARAMS MUL_EXP ADD_EXP REL_EXP EQ_EXP LAND_EXP LOR_EXP CONST_EXP \

%%
COMP_UNIT:  DECL 
        {
            $$ = new_node(NONCONST_REST, TP_COMP_UNIT, 0, 0, 0, NULL, NULL);
            insert_sons($$, $1, 0);
        }
    |       FUNC_DEF
        {
            $$ = new_node(NONCONST_REST, TP_COMP_UNIT, 0, 0, 0, NULL, NULL);
            insert_sons($$, $1, 0);
        }
    |       DECL | COMP_UNIT
        {
            $$ = $2;
            insert_sons($$, $1, 0);
        }
    |       FUNC_DEF | COMP_UNIT
        {
            $$ = $2;
            insert_sons($$, $1, 0);
        }


