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

struct op {
    string val;
    string type;
};

vector<object> var_table;
vector<string> func_table;
vector<op> op_table;
vector<string> ident_stack;
vector<string> param_table;
vector<string> buff;
string last_temp_name;
bool is_param = false;
bool is_local = false;

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
    last_temp_name = x->name;
    x->type = t;
    x->size = s;
    var_table.push_back(*x);
}

string check_op_type(){
    return op_table.back().type;

} 

void add_op(string v, string t = "int") {
    op *x = new op();
    x->val = v;
    x->type = t;
    op_table.push_back(*x);

}

string get_op_val() {
    if(!op_table.empty()) {
	string temp = op_table.back().val;
	op_table.pop_back();
	return temp;	
    }
    else {
	cout << "ERROR: no op in op table" << endl;
	exit(1);
    }
}

void write(string s) {
    buff.push_back(s);
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
begin_locals:	BEGIN_LOCALS {
		    cout<< "in begin_locals" << endl;
		    is_local = true;
		}
		;

end_locals:	END_LOCALS {
		    cout<< "in end_locals" << endl;
		    is_local = false;
		}
		;

function:	funchead params_start declarations params_end begin_locals declarations end_locals BEGIN_BODY statements END_BODY {
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


read_vars:	var {
		    cout<< "in read_vars var" << endl;
		    write(".< " + get_op_val());
		}
		| var COMMA read_vars {
		    cout<< "in read_vars var comma" << endl;
		    write(".< " + get_op_val());
		}
		; 

write_vars:	var {
		    cout<< "in write_vars var" << endl;
		    //write(
		}
		| var COMMA write_vars {
		    cout<< "in write_vars var comma" << endl;
		
		}
		; 





statements:	/*epsilon*/ 
		| statement SEMICOLON statements 
		;

statement:	var ASSIGN expression {
		    cout<< "in statment var assign expression" << endl;

		    

		} 
		| IF bool_expr THEN statements ELSE statements ENDIF {
		    // If / Else if statement
		    cout<< "in statement if then else" << endl;
		}
		| IF bool_expr THEN statements ENDIF {
		    // If statement 
		    cout<< "in statement if then" << endl;
		}
		| WHILE bool_expr BEGINLOOP statements ENDLOOP {
		    // while loop   
		    cout<< "in statement while loop" << endl;
		} 
		| DO BEGINLOOP statements ENDLOOP WHILE bool_expr {
		    // Do while loop
		    cout<< "in statement do while loop" << endl;
		}
		| FOREACH ident IN ident BEGINLOOP statements ENDLOOP {
		    // for each?
		    cout<< "in statement foreach loop" << endl;
		}
		| READ read_vars {
		    // read vars
		    cout<< "in statement read vars" << endl;		
    		}
		| WRITE write_vars {
		    // write vars
		    cout<< "in statement write vars" << endl;
		}
		| CONTINUE {
		    // continue
		    cout<< "in statement continue" << endl;
		}
		| RETURN expression {
		    // return expression   
		    cout<< "in statement return expression" << endl;
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
		    cout<< "in comp eq" << endl;
		}
		| NEQ {
		    cout<< "in comp neq" << endl;
		}
		| LT {
		    cout<< "in comp lt" << endl;
		}
		| GT {
		    cout<< "in comp gt" << endl;
		}
		| LTE {
		    cout<< "in comp lte" << endl;
		}
		| GTE {
		    cout<< "in comp gte" << endl;
		}
		;

multiplicative_expr:    term {
			    cout<< "in muliplicative_expr term" << endl;
			}
			| term MULT multiplicative_expr  {
			    cout<< "in multiplicative_expr term mult" << endl;
			    add_temp("int");
			    string op2 = get_op_val();
			    string op1 = get_op_val();
			    write("* " + last_temp_name + ", " + op1 + ", " + op2);
			    add_op(last_temp_name);
		    	}
			| term DIV  multiplicative_expr {
			    cout<< "in multiplicative_expr term div" << endl;
			    add_temp("int");
			    string op2 = get_op_val();
			    string op1 = get_op_val();
			    write("/ " + last_temp_name + ", " + op1 + ", " + op2);
			    add_op(last_temp_name);
			}
			| term MOD  multiplicative_expr {
			    cout<< "in multiplicative_expr term mod" << endl;
			    add_temp("int");
			    string op2 = get_op_val();
			    string op1 = get_op_val();
			    write("% " + last_temp_name + ", " + op1 + ", " + op2);
			    add_op(last_temp_name);
			}
			;

expression:	multiplicative_expr {
		    cout<< "in expression multiplicative_expr" << endl;
		}
		| multiplicative_expr ADD expression {
		    cout<< "in expression multiplicative_expr add" << endl;
		    add_temp("int");
		    string op2 = get_op_val();
		    string op1 = get_op_val();
		    write("+ " + last_temp_name + ", " + op1 + ", " + op2);
		    add_op(last_temp_name);
		}
		| multiplicative_expr SUB expression {
		    cout<< "in expression multiplicative_expr sub" << endl;
		    add_temp("int");
		    string op2 = get_op_val();
		    string op1 = get_op_val();
		    write("- " + last_temp_name + ", " + op1 + ", " + op2);
		    add_op(last_temp_name);
		}
		;

expressions:	expression {
		    cout<< "in expressions expression" << endl;

		} 
		| expression COMMA expressions {
		    cout<< "in expressions expression comma expression" << endl;

		} 
		;

term:		var {
		    cout<< "in term var" << endl;
		    
		    add_temp("int");
		    if(check_op_type() == "int") {
			write("= " + last_temp_name + ", " + get_op_val());
		    }
		    else {
			write("=[] " + last_temp_name + ". " + get_op_val());
		    }
		    add_op(last_temp_name);
		    cout << " > " << buff.back() << endl;

		}
		| NUMBER {
		    cout<< "in term number" << endl;
		    add_op(SSTR($1));		    
		}
		| L_PAREN expression R_PAREN {
		    cout<< "in term (expression)" << endl;
		    
		}
		| SUB NUMBER {
		    add_op(SSTR($2 * -1));
		    cout<< "in term sub number" << endl;

		}
		| SUB L_PAREN expression R_PAREN {
		    cout<< "in term sub (expression)" << endl;
		    add_temp("int");
		    write("- " + last_temp_name + ", 0, " + get_op_val());
		    add_op(last_temp_name);
		}	
		| ident L_PAREN expressions R_PAREN { //FUNCTIONS
		    cout<< "in term ident (expression)" << endl;
		    add_temp("int");
		    //TODO:check if id exists 
		    write("call " + *($1) + ", " + last_temp_name);
		    add_op(last_temp_name);
		    
		}
		;


var:	    ident {
		//cout<< "in var ident" << endl; 
		string id = "_" + *($1);
		//TODO: check if id exists already
		add_op(id);
		cout << " <-- " << id << endl;
		
	    }
	    | ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET {
		//cout<< "in var ident[expression]" << endl;
		string id = "_" + *($1);
		//TODO: check if id exists already
		add_op( id + ", " + get_op_val(), "arr<int>");
		cout << " <--  []" << id << endl;
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


