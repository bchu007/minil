%{
#include "heading.h"
#include "tok.h"
int yyerror(char *s);
int yylineo = 1;
int lineNum = 1;
int charNum = 0;
%}

DIGIT	[0-9]+   
ID 	[a-z][a-z0-9]*
IDENT   [a-zA-Z][_a-zA-Z0-9]*
COM	[#][#].*[\n]

%%
	/*  Comments			*/
{COM}		{lineNum++; yylineo++; charNum = 0;}	
	/*  Reserved Words		*/
"function"	{return FUNCTION;}
"beginparams"	{return BEGIN_PARAMS;}
"endparams"	{return END_PARAMS;}
"beginlocals"	{return BEGIN_LOCALS;}
"endlocals"	{return END_LOCALS;}
"beginbody"	{return BEGIN_BODY;}
"endbody"	{return END_BODY;}
"integer"	{return INTEGER;}
"array"		{return ARRAY;}
"of"		{return OF;}
"if"		{return IF;}
"then"		{return THEN;}
"endif"		{return ENDIF;}
"else"		{return ELSE;}
"while"		{return WHILE;}
"do"		{return DO;}
"foreach"	{return FOREACH;}
"in"		{return IN;}
"beginloop"	{return BEGINLOOP;}
"endloop"	{return ENDLOOP;}
"continue"	{return CONTINUE;}
"read"		{return READ;}
"write"		{return WRITE;}
"and"		{return AND;}
"or"		{return OR;}
"not"		{return NOT;}
"true"		{return TRUE;}
"false"		{return FALSE;}
"return"	{return RETURN;}
	/*ERROR CHECKS*/
[0-9]+[a-zA-Z_]+[a-zA-Z_0-9]* {charNum+=strlen(yytext);exit(1);}
[_]+[a-zA-Z_0-9]*             {charNum+=strlen(yytext);exit(1);}
[a-zA-Z_0-9]*[_]+             {charNum+=strlen(yytext);exit(1);}
	/* identifier			IDENT XXXX*/
{IDENT}		{charNum+=strlen(yytext); yylval.op_val = new std::string(yytext); return IDENT;}
	/* number			NUMBER XXXX*/

{DIGIT}		{charNum+=strlen(yytext); yylval.int_val = atoi(yytext); return NUMBER;}

	/*0 function calls 		()*/
"("	{charNum++; return L_PAREN;}
")"	{charNum++; return R_PAREN;}
	/*1 Arrary subscripting		[]*/
"["	{charNum++; return L_SQUARE_BRACKET;}

"]"	{charNum++; return R_SQUARE_BRACKET;}	
	/*2 Unary minus			-*/
	/*""	{;}	*/
	/*3 Multiplication		**/
"*"	{charNum++; return MULT;}
	/*  Division			/*/
"/"	{charNum++; return DIV;}
	/*  Remainder 			%*/
"%"	{charNum++; return MOD;}
	/*4 Addition			+*/
"+"	{charNum++; return ADD;}
	/*  Subtraction			-*/
"-"	{charNum++; return SUB;}
	/*5 Relational operators 	<*/
"<"	{charNum++; return LT;}
	/*  ""				<=*/
"<="	{charNum++; return LTE;}
	/*  "" 				>*/
">"	{charNum++; return GT;}
	/*  ""				>=*/
">="	{charNum++; return GTE;}
	/*  ""				==*/
"=="	{charNum++; return EQ;}
	/*  ""				!=*/
"<>"	{charNum++; return NEQ;}
	/*9 Assignment 			Right-to-left*/
":="	{charNum++; return ASSIGN;}

";" 	{charNum++; return SEMICOLON;}	/* Semicolon */
":" 	{charNum++; return COLON;}		/* Colon     */
","	{charNum++; return COMMA;}		/* Comma     */

[\n]    {lineNum++; yylineo++; charNum = 0;}
[ ]     {charNum++;}			/* whitespace */
[\t]	{charNum++;}
.       {exit(1);}


%%
