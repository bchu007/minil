%{ 
#include <stdio.h>
#include <string.h>
int charNum = 0;
%}

DIGIT	[0-9]+   
ID 	[a-z][a-z0-9]*
IDENT   [a-zA-Z][_a-zA-Z0-9]*
COM	"##".*[\n]

%%
	/*  Comments			*/
{COM}		;	
	/*  Reserved Words		*/
"function"	{printf("FUNCTION\n");}
"beginparams"	{printf("BEGIN_PARAMS\n");}
"endparams"	{printf("END_PARAMS\n");}
"beginlocals"	{printf("BEGIN_LOCALS\n");}
"endlocals"	{printf("END_LOCALS\n");}
"beginbody"	{printf("BEGIN_BODY\n");}
"endbody"	{printf("END_BODY\n");}
"integer"	{printf("INTEGER\n");}
"array"		{printf("ARRAY\n");}
"of"		{printf("OF\n");}
"if"		{printf("IF\n");}
"then"		{printf("THEN\n");}
"endif"		{printf("ENDIF\n");}
"else"		{printf("ELSE\n");}
"while"		{printf("WHILE\n");}
"do"		{printf("DO\n");}
"foreach"	{printf("FOREACH\n");}
"in"		{printf("IN\n");}
"beginloop"	{printf("BEGINLOOP\n");}
"endloop"	{printf("ENDLOOP\n");}
"continue"	{printf("CONTINUE\n");}
"read"		{printf("READ\n");}
"write"		{printf("WRITE\n");}
"and"		{printf("AND\n");}
"or"		{printf("OR\n");}
"not"		{printf("NOT\n");}
"true"		{printf("TRUE\n");}
"false"		{printf("FALSE\n");}
"return"	{printf("RETURN\n");}
	/* identifier			IDENT XXXX*/
{IDENT}		{charNum = strlen(yytext); printf("IDENT %s, %i\n", yytext, charNum);}
	/* number			NUMBER XXXX*/

{DIGIT}		{charNum = strlen(yytext); printf("NUMBER %s\n", yytext);}

	/*0 function calls 		()*/
"("	{printf("L_PAREN\n");}
")"	{printf("R_PAREN\n");}
	/*1 Arrary subscripting		[]*/
"["	{printf("L_SQUARE_BRACKET\n");}
"]"	{printf("R_SQUARE_BRACKET\n");}	
	/*2 Unary minus			-*/
	/*""	{printf("\n");}	*/
	/*3 Multiplication		**/
"*"	{printf("MULT\n");}
	/*  Division			/*/
"/"	{printf("DIV\n");}
	/*  Remainder 			%*/
"%"	{printf("MOD\n");}
	/*4 Addition			+*/
"+"	{printf("ADD\n");}
	/*  Subtraction			-*/
"-"	{printf("SUB\n");}
	/*5 Relational operators 	<*/
"<"	{printf("LT\n");}
	/*  ""				<=*/
"<="	{printf("LTE\n");}
	/*  "" 				>*/
">"	{printf("GT\n");}
	/*  ""				>=*/
">="	{printf("GTE\n");}
	/*  ""				==*/
"=="	{printf("EQ\n");}
	/*  ""				!=*/
"<>"	{printf("NEQ\n");}
	/*6 Logical Not			Right-to-left*/
	/*""	{printf("\n");}*/
	/*7 Logical And			Left-to-right*/
	/*""	{printf("\n");}*/
	/*8 Logical Or			""*/
""	{printf("\n");}
	/*9 Assignment 			Right-to-left*/
":="	{printf("ASSIGN\n");}

";" 	{printf("SEMICOLON\n");}	/* Semicolon */
":" 	{printf("COLON\n");}		/* Colon     */
","	{printf("COMMA\n");}		/* Comma     */

[ \n\t]+       /*{printf("%i\n", yytext);}*/	/* whitespace */

.              {printf("Error unrecognized symbol\n"); exit(0);}


%%

int main(int argc, char ** argv)
{
   yylex();
   //printf("%x\n", charNum);
}

