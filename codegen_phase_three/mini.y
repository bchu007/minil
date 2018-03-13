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

funchead:	FUNCTION ident SEMICOLON {
		     cout << "func " << get_back(ident_list)  << endl;
		}
		;

params:		BEGIN_PARAMS declarations END_PARAMS {
		}
		;

function:	funchead params BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements END_BODY {
		    for(int i = 0; i <  ident_list.size(); ++i) { 
		    }
		}
		;

ident:		IDENT {
		    // stores identifiers in ident list
		    ident_list.push_back(*($1));
		    cout << "test IDENT -> " << *($1) << endl;
		}
		;


identifiers:	ident {
		    // pushes back the number of identifiers into list
		    cout << "final " << identifiers_cnt + 1 << endl;
		    numIdentifiers_list.push_back(identifiers_cnt + 1);
		    
		    //cout << endl;
		    		    
	
		}
		| ident COMMA identifiers {
		    // increments number of idents in identifiers
		        identifiers_cnt++;
			numIdentifiers_list.back() += 1;
			cout << "his" << identifiers_cnt <<   endl;
		}
		;


declaration:	identifiers COLON INTEGER {
		    // gets the number of identifiers in this declaration
		    int numidents = get_back(numIdentifiers_list);
		    
		    // prints out all identifiers of integer declaration
		    for(int i = numidents; i > 0; --i) {
		        cout << ". " << ident_list.end()[-1 * i]  << endl;
		    }
		    // clears counter 
		    clear(identifiers_cnt);
		}
		| identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER {
		    // gets the number of identifiers in this declaration
		    int numidents = get_back(numIdentifiers_list);
		    
		    //prints out all identifiers of integer array declaration
		    for(int i = numidents; i > 0; --i) {
			cout << ".[] " << ident_list.end()[-1 * i] <<  ", " << $5 << endl;
		    }
		    //clears counter
		    clear(identifiers_cnt);
		    
		}
		;



declarations:	/*epsilon*/  {   
		    // pushes back the number of declerations into list;
		    numDeclarations_list.push_back(declarations_cnt); 
		    
		    // clears counter
		    clear(declarations_cnt);
		    }
		| declaration SEMICOLON declarations {      
		    //increments the number of declerations
		    declarations_cnt++; 
		    }
		;


vars:		var 
		| var COMMA vars {
		
		}
		; 




statements:	/*epsilon*/ 
		| statement SEMICOLON statements 
		;

statement:	var ASSIGN expression 
		| IF bool_expr THEN statements ELSE statements ENDIF {
		    // If / Else if statement
		}
		| IF bool_expr THEN statements ENDIF {
		    // If statement 
		}
		| WHILE bool_expr BEGINLOOP statements ENDLOOP {
		    // while loop   
		} 
		| DO BEGINLOOP statements ENDLOOP WHILE bool_expr {
		    // Do while loop
		}
		| FOREACH ident IN ident BEGINLOOP statements ENDLOOP {
		    // for each?
		}
		| READ vars {
		    // read vars
		}
		| WRITE vars {
		    // write vars
		}
		| CONTINUE {
		    // continue
		}
		| RETURN expression {
		    // return expression   
		} 
		;


relation_expr: relation_expr_param_not {
		// checks that relation_expr doesn't begin with NOT
		}
		| NOT relation_expr_param_not {
		// checks that relation_expr does begin with NOT

		}
		;

relation_expr_param: relation_expr_not {
		// checks if relation_expr_not lacks surrounding parens
		}
		| L_PAREN relation_expr_not R_PAREN {
		// check if relation_expr_not contains parens

		}
		;

relation_expr_not: expression comp expression {
		// checks if realtion_expr is true or false based on e1 and e2
		// create temp variable (dest) to store the comparison
		}
		| TRUE {
		// sets relation_expr to be true

		}
		| FALSE {
		// sets relation_expr to be false

		} 
		;


relation_and_expr_next: /*epsilon*/ {
    
		}
		| AND realtion_and_expr_next {
			
		}
		;
		    
relation_and_expr: relation_expr relation_and_expr_next {
		// starts AND 

		}

bool_expr_next:	/*epsilon*/ {
		// finished with last OR statment in bool expression

		} 
		| OR bool_expr_next {
		// increment number of bool expressions 

		}
		;

bool_expr:	relation_and_expr bool_expr_next {
		// start of a bool_expr
			
		}
		; 
 
comp:		EQ {
		
		}
		| NEQ {
		
		}
		| LT {
		
		}
		| GT {
		
		}
		| LTE {
		
		}
		| GTE {
		
		}
		;

multiplicative_expr:    term 
			| term MULT multiplicative_expr 
			| term DIV  multiplicative_expr
			| term MOD  multiplicative_expr
			;

expression:	multiplicative_expr {
		    // Last multiplicative expression 
		}
		| multiplicative_expr ADD expression {
		    // Add arithmetic Operator Statement (+ dest, src1, src2)
		}
		| multiplicative_expr SUB expression {
		    // Sub arithmetic Operator Statement (- dest, src1, src2)
		}
		;

expressions:	expression {
		    // function calls parameters
		} 
		| expression COMMA expressions 
		;

term:		var {

		}
		| NUMBER {

		}
		| L_PAREN expression R_PAREN {

		}
		| SUB NUMBER {

		}
		| SUB L_PAREN expression R_PAREN {
		    
		}	
		| ident L_PAREN expressions R_PAREN {

		}
		;


var:	    ident {

	    }
	    | ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET {

	    }
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


