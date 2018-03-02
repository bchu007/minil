/* Mini Calculator */
/* calc.y */

%{
#include "heading.h"
int yyerror(const char *s);
int yylex(void);

%}

%union{
  int		int_val;
  string*	op_val;
}

%error-verbose

%start program


%token	<int_val>	NUMBER 
%token	<op_val>    	IDENT
%token			FUNCTION
%token		   	BEGIN_PARAMS
%token		        END_PARAMS
%token			BEGIN_LOCALS
%token			END_LOCALS
%token			BEGIN_BODY
%token		       	END_BODY
%token		       	INTEGER 
%token		       	ARRAY
%token		       	OF
%token		       	IF
%token		       	THEN
%token		       	ENDIF
%token		       	ELSE
%token		       	WHILE
%token		       	DO
%token		       	FOREACH
%token		       	IN
%token		       	BEGINLOOP
%token	         	ENDLOOP
%token		       	CONTINUE
%token		       	READ
%token		       	WRITE
%token		       	AND
%token		       	OR
%token		       	NOT
%token		       	TRUE
%token		       	FALSE
%token		       	RETURN
%token		       	SUB
%token		       	ADD
%token		       	MULT
%token		       	DIV
%token		       	MOD
%token		       	EQ
%token		       	NEQ
%token		       	LT
%token		       	GT
%token		       	LTE
%token		       	GTE
%token		       	SEMICOLON
%token		       	COLON 
%token		       	COMMA
%token		       	L_PAREN
%token		       	R_PAREN
%token		       	L_SQUARE_BRACKET
%token		       	R_SQUARE_BRACKET
%token		       	ASSIGN



%%

program:	functions {printf("prog_start -> functions\n");}
		;

functions:	/* epsilon */ {printf("functions -> epsilon\n");}
		| function functions  {printf("functions -> function functions\n");}
		;

function:	FUNCTION ident SEMICOLON BEGIN_PARAMS declarations END_PARAMS BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements END_BODY {printf("function -> FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarations END_PARAMS BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements END_BODY\n");}
		;

ident:		IDENT {cout << "ident -> IDENT " << *($1) << endl;}
		;

declarations:	/*epsilon*/  {printf("declarations -> epsilon\n");}
		| declaration SEMICOLON declarations {printf("declarations -> declaration SEMICOLON declarations\n");}
		;

statements:	/*epsilon*/ {printf("statements -> epsilon\n");}
		| statement SEMICOLON statements {printf("statements -> statement SEMICOLON statements\n");}
		;

identifiers:	ident {printf("identifiers -> ident\n");}
		| ident COMMA identifiers {printf("identifiers -> ident COMMA identifiers\n");}
		;

declaration:	identifiers COLON INTEGER {printf("declaration -> identifiers COLON INTEGER\n");}
		| identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER {printf("declaration -> identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");}
		
		;



vars:		var {printf("vars -> var\n");}
		| var COMMA vars {printf("vars -> var COMMA vars\n");}
		; 



bool_expr:	relation_and_expr {printf("bool_exp -> relation_and_exp\n");}
		| relation_and_expr OR bool_expr {printf("bool_exp -> relation_and_exp OR bool_expr\n");}
		;

statement:	var ASSIGN expression {printf("statement -> var ASSIGN expression\n");}
		| IF bool_expr THEN statements ELSE statements ENDIF {printf("statement -> IF bool_exp THEN statements ELSE statements ENDIF\n");}
		| IF bool_expr THEN statements ENDIF {printf("statement -> IF bool_exp THEN statements ENDIF\n");}
		| WHILE bool_expr BEGINLOOP statements ENDLOOP  {printf("statement -> WHILE bool_exp BEGINLOOP statements ENDLOOP\n");}
		| DO BEGINLOOP statements ENDLOOP WHILE bool_expr {printf("statement -> DO BEGINLOOP statements ENDLOOP WHILE bool_exp\n");}
		| FOREACH ident IN ident BEGINLOOP statements ENDLOOP {printf("statements -> FOREACH IDENT IN IDENT BEGINLOOP statements ENDLOOP\n");}
		| READ vars {printf("statement -> READ vars\n");}
		| WRITE vars {printf("statement -> WRITE vars\n");}
		| CONTINUE {printf("statement -> CONTINUE\n");}
		| RETURN expression {printf("statement -> RETURN expression\n");}
		;

relation_and_expr:  relation_expr {printf("relation_and_exp -> relation_exp\n");}
		    | relation_expr AND relation_and_expr {printf("relation_and_exp -> relation_exp AND relation_exp\n");}
		    ;


relation_expr:	expression comp	expression {printf("relation_exp -> expression comp expression\n");}
		| NOT expression comp expression {printf("relation_exp -> NOT expression comp expression\n");}
		| TRUE {printf("relation_exp -> TRUE\n");}
		| NOT TRUE {printf("irelation_exp -> NOT TRUE\n");}
		| FALSE {printf("relation_exp -> FALSE\n");}
		| NOT FALSE {printf("relation_exp -> NO FALSE\n");}
		| L_PAREN bool_expr R_PAREN {printf("relation_exp -> L_PAREN bool _expr R_PAREN\n");}
		| NOT L_PAREN bool_expr R_PAREN {printf("relation_exp -> NOT L_PAREN bool _expr R_PAREN\n");}
		;
 
comp:		EQ {printf("comp -> EQ\n");}
		| NEQ {printf("comp -> NEQ\n");}
		| LT {printf("comp -> LT\n");}
		| GT {printf("comp -> GT\n");}
		| LTE {printf("comp -> LTE\n");}
		| GTE {printf("comp -> GTE\n");}
		;

expression:	multiplicative_expr {printf("expression -> multiplicative_expression\n");}
		| multiplicative_expr ADD expression {printf("expression -> multiplicative_expression ADD multiplicative_expression\n");}
		| multiplicative_expr SUB expression {printf("expression -> multiplicative_expression SUB multiplicative_expression\n");}
		;
multiplicative_expr:    term {printf("multiplicative_expression -> term\n");}
			| term MULT multiplicative_expr{printf("multiplicative_expression -> term MULT multiplicative_expression\n");}
			| term DIV  multiplicative_expr{printf("multiplicative_expression -> term DIV multiplicative_expression\n");}
			| term MOD  multiplicative_expr{printf("multiplicative_expression -> term MOD multiplicative_expression\n");}
			;

expressions:	expression {printf("expressions -> expression\n");}
		| expression COMMA expression {printf("expressions -> expression COMMA expression\n");}
		;

term:		var {printf("term -> var\n");}
		| NUMBER {printf("term -> NUMBER\n");}
		| L_PAREN expression R_PAREN {printf("term -> L_PAREN expression R_PAREN\n");}		 | SUB var {printf("term -> SUB var\n");}
		| SUB NUMBER {printf("term -> SUB NUMBER\n");}
		| SUB L_PAREN expression R_PAREN {printf("term -> SUB L_PAREN expression R_PAREN\n");}	

		| ident L_PAREN expressions R_PAREN {printf("term -> identifier L_PAREN expressions R_PAREN \n");}
		;


var:	    ident {printf("var -> ident\n");}
	    | ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET {printf("var -> ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");}
	    ;


%%

int yyerror(string s) {
    //extern int yylineno;	/* defined and maintained in lex.c */
    extern char *yytext;	/* defined and maintained in lex.c */
    extern int lineNum;    

    cerr << "ERROR: " << s << "at symbol \"" << yytext;
    cerr << "\" on line " <<  lineNum << " "<< s << endl;
    exit(1);
}
int yyerror(const char *s)
{
    return yyerror(string(s));
}


