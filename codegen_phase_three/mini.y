/* Mini Calculator */
/* calc.y */

%{
#include "heading.h"
#include <vector>
int yyerror(const char *s);
int yylex(void);


string get_back(vector<string> s) {
    string temp;
    temp = s.back();
    s.pop_back();
    return temp;
}

int get_back(vector<int> i) {
    int temp;
    temp = i.back();
    i.pop_back();
    return temp;
}

void clear(int &x) {
    x = 0;
}
    
vector<string> ident_list;

int declarations_cnt;
int identifiers_cnt;
vector<int> numDeclarations_list;
vector<string> declarations_list;
vector<int> numIdentifiers_list;
vector<string> identifiers_list;


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
%type	<int_val>	INTEGER


%%

program:	functions {} 
		;

functions:	/* epsilon */ 
		| function functions  
		;

funchead:	FUNCTION ident SEMICOLON { cout << "func " << identlist.back() << endl; identlist.pop_back(); }
		;

params:		BEGIN_PARAMS declarations END_PARAMS {inparams = true;}
		;

function:	funchead params BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements END_BODY 
		{ for(int i = 0; i <  identlist.size(); ++i) {cout << identlist.at(i) << " "; } }
		;

ident:		IDENT {
		    // stores identifiers in ident list
		    ident_list.push_back(*($1));
		    }
		;

statements:	/*epsilon*/ 
		| statement SEMICOLON statements 
		;

identifiers:	ident  {
		    // pushes back the number of identifiers into list
		    numIdentifiers_list.push_back(identifiers_cnt + 1);
		    // clears counter 
		    clear(identifiers_cnt);
		    }
		| ident COMMA identifiers {
		    // increments number of idents in identifiers
		    identifiers_cnt++;
		    }
		;


declaration:	identifiers COLON INTEGER {
		    // for all identifiers 
		    for(int i = 0; i < numDeclerations_list.back();
		    }
		| identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER 
		    
		;



declarations:	/*epsilon*/  {   
		    // pushes back the number of declerations into list;
		    numDeclarations_list.push_back(declarations_cnt); 
		    // clears counter
		    clear(declerations_cnt);
		    }
		| declaration SEMICOLON declarations {      
		    //increments the number of declerations
		    declarations_cnt++; 
		    }
		;


vars:		var 
		| var COMMA vars 
		; 



bool_expr:	relation_and_expr 
		| relation_and_expr OR bool_expr 
		;

statement:	var ASSIGN expression 
		| IF bool_expr THEN statements ELSE statements ENDIF { }
		| IF bool_expr THEN statements ENDIF 
		| WHILE bool_expr BEGINLOOP statements ENDLOOP  
		| DO BEGINLOOP statements ENDLOOP WHILE bool_expr 
		| FOREACH ident IN ident BEGINLOOP statements ENDLOOP 
		| READ vars 
		| WRITE vars 
		| CONTINUE 
		| RETURN expression 
		;

relation_and_expr:  relation_expr 
		    | relation_expr AND relation_and_expr 
		    ;


relation_expr:	expression comp	expression 
		| NOT expression comp expression 
		| TRUE 
		| NOT TRUE 
		| FALSE 
		| NOT FALSE 
		| L_PAREN bool_expr R_PAREN 
		| NOT L_PAREN bool_expr R_PAREN 
		;
 
comp:		EQ 
		| NEQ 
		| LT 
		| GT 
		| LTE 
		| GTE 
		;
multiplicative_expr:    term 
			| term MULT multiplicative_expr 
			| term DIV  multiplicative_expr
			| term MOD  multiplicative_expr
			;

expression:	multiplicative_expr 
		| multiplicative_expr ADD expression {}
		| multiplicative_expr SUB expression 
		;

expressions:	expression {paramnum++; }
		| expression COMMA expression {cout << "
		;

term:		var 
		| NUMBER 
		| L_PAREN expression R_PAREN 
		| SUB NUMBER 
		| SUB L_PAREN expression R_PAREN 	

		| ident L_PAREN expressions R_PAREN { cout << "call " << identlist.back()<< endl; identlist.pop_back();}//function call
		;


var:	    ident
	    | ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET 
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


