/* Mini Calculator */
/* calc.y */

%{
#include "heading.h"
int yyerror(const char *s);
int yylex(void);






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
%code requires {
    struct sym {
	string val;
	string type;
	sym() {}
	sym(string v, string t) : val(v), type(t = "") {}
    };
   

}

%union{
  int		int_val;
  string*	op_val;
  char*		code;
  struct sym*	sym_val;
}

%error-verbose

%start program

%type	<op_val>	ident
%type	<sym_val>	declarations
%token	<int_val>	NUMBER 
%token	<op_val>    	IDENT

%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY
%token INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO FOREACH IN BEGINLOOP ENDLOOP CONTINUE READ WRITE TRUE FALSE SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET RETURN
%left SUB ADD MULT DIV MOD
%left EQ NEQ LT GT LTE GTE
%right NOT
%left AND OR
%right ASSIGN





%%

program:	functions {} 
		;

functions:	/* epsilon */ 
		| function functions  
		;

funchead:	FUNCTION ident SEMICOLON {
		     cout << " > " <<"func " << *$2 <<  endl;
		}
		;

params_end:	END_PARAMS {
		    //cout<< "in prams params_end" << endl;
		}
		;

params_start:	BEGIN_PARAMS {
		    //cout<< "in params params_start" << endl;
		}
		;

function:	funchead params_start declarations params_end BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements END_BODY {
		    //cout<< "in function" << endl;
		}
		;

ident:		IDENT {
		    $$ = $1; 
		}
		;


identifiers:	ident {
		    cout << " > " << *$1 << endl; 	
		}
		| ident COMMA identifiers {
		    cout << " > " << *$1 << endl;
		}
		;


declaration:	identifiers COLON INTEGER {
		//cout<< "in declaration colon integer" << endl;
		
		}
		| identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER {
		//cout<< "in declaration colon array" << endl;
		}
		;



declarations:	/*epsilon*/  {   
		}
		| declaration SEMICOLON declarations {      
		    //cout<< "in declarations semicolon" << endl; 
		}
		;


vars:		var {
		    //cout<< "in vars var" << endl;
		}
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


relation_expr: relation_expr_param {
		    //cout<< "in relation_expr relation_expr_param" << endl;
		}
		| NOT relation_expr_param {
		    //cout<< "in relation_expr relation_expr_param" << endl;

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
		| AND relation_and_expr {
			
		}
		;
		    
relation_and_expr: relation_expr relation_and_expr_next {
		// starts AND 

		}

bool_expr_next:	/*epsilon*/ {
		// finished with last OR statment in bool expression

		} 
		| OR bool_expr {
		// increment number of bool expressions 

		}
		;

bool_expr:	relation_and_expr bool_expr_next {
		//cout<< "in bool_expr realation_and_expr bool_expr_next" << endl;
		// start of a bool_expr
			
		}
		; 
 
comp:		EQ {
		    //cout<< "in comp eq" << endl;
		}
		| NEQ {
		    //cout<< "in comp neq" << endl;
		}
		| LT {
		    //cout<< "in comp lt" << endl;
		}
		| GT {
		    //cout<< "in comp gt" << endl;
		}
		| LTE {
		    //cout<< "in comp lte" << endl;
		}
		| GTE {
		    //cout<< "in comp gte" << endl;
		}
		;

multiplicative_expr:    term {
			    //cout<< "in muliplicative_expr term" << endl;
			}
			| term MULT multiplicative_expr  {
			    //cout<< "in multiplicative_expr term mult" << endl;
			}
			| term DIV  multiplicative_expr {
			    //cout<< "in multiplicative_expr term div" << endl;
			}
			| term MOD  multiplicative_expr {
			    //cout<< "in multiplicative_expr term mod" << endl;
			}
			;

expression:	multiplicative_expr {
		    //cout<< "in expression multiplicative_expr" << endl;
		}
		| multiplicative_expr ADD expression {
		    //cout<< "in expression multiplicative_expr add" << endl;
		}
		| multiplicative_expr SUB expression {
		    //cout<< "in expression multiplicative_expr sub" << endl;
		}
		;

expressions:	expression {
		    //cout<< "in expressions expression" << endl;
		} 
		| expression COMMA expressions 
		;

term:		var {
		    //cout<< "in term var" << endl;

		}
		| NUMBER {
		    //cout<< "in term number" << endl;
		
		}
		| L_PAREN expression R_PAREN {
		    //cout<< "in term (expression)" << endl;

		}
		| SUB NUMBER {
		    //cout<< "in term sub number" << endl;

		}
		| SUB L_PAREN expression R_PAREN {
		    //cout<< "in term sub (expression)" << endl;

		}	
		| ident L_PAREN expressions R_PAREN {
		    //cout<< "in term ident (expression)" << endl;

		}
		;


var:	    ident {
		//cout<< "in var ident" << endl; 

	    }
	    | ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET {
		//cout<< "in var ident[expression]" << endl;
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


