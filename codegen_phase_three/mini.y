/* Mini Calculator */
/* calc.y */

%{
#include "heading.h"
#include <sstream>

#define SSTR( x ) static_cast< std::ostringstream & >( std::ostringstream() << std::dec << x ).str()

int yyerror(const char *s);
int yylex(void);

struct object {
    string name;
    string type;
    int size;
};


vector<object> var_table;
vector<string> func_table;
vector<string> op_table;
vector<string> ident_stack;
vector<string> param_table;
bool is_param = false;

void add_object(string n, string t = "null", int v = 1) {
    object *x = new object();
    x->name = n;
    x->type = t;
    x->size = v;
    var_table.push_back(*x); 
} 

string get_next_num() {
    static int global_temp_num = 0;
    string temp = "t" + SSTR(global_temp_num);
    global_temp_num += 1;
    return temp;
}

// adds a temp variable 
//  *params: takes in type and size
void add_temp(string t = "null", int s = 1){
    object *x = new object();
    x->name = get_next_num();
    x->type = t;
    x->size = s;
    var_table.push_back(*x);
}

string get_op() {
    if(!op_table.empty()) {
	string temp = op_table.back();
	op_table.pop_back();
	return temp;	
    }
    else {
	cout << "ERROR: no op in op table" << endl;
	exit(1);
    }
}
%}


%union{
  int		int_val;
  string*	op_val;
  char*		code;
}

%error-verbose

%start program

%type	<op_val>	ident	
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
		    is_param = false;
		}
		;

params_start:	BEGIN_PARAMS {
		    //cout<< "in params params_start" << endl;
		    is_param = true;
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
		    ident_stack.clear();
		    ident_stack.push_back(*$1);
		    if(is_param) {
			param_table.push_back("_" + *($1));
		    }
		}
		| ident COMMA identifiers {
		    ident_stack.push_back(*$1);
		}
		;


declaration:	identifiers COLON INTEGER {
		    cout<< "in declaration colon integer" << endl;
		    while(!ident_stack.empty()) {
			add_object("_" + ident_stack.back(), "int");
			ident_stack.pop_back();
		    }
		}
		| identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER {
		    cout<< "in declaration colon array" << endl;
		    while(!ident_stack.empty()) {
			add_object("_" + ident_stack.back(), "arr<int>", $5);
			ident_stack.pop_back();
		    }
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
		string id = "_" + *($1);
		op_table.push_back(id);
		
	    }
	    | ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET {
		//cout<< "in var ident[expression]" << endl;
		string id = "_" + *($1);
		op_table.push_back("[] " + id + ", " + get_op());
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


