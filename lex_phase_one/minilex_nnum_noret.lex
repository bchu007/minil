%{
#include <stdio.h>
#include <string.h>   
int lineNum = 1;
int charNum = 0;
%}

DIGIT	[0-9]+   
ID 	[a-z][a-z0-9]*
IDENT   [a-zA-Z][_a-zA-Z0-9]*
COM	[#][#].*[\n]

%%
	/*  Comments			*/
{COM}		lineNum++; charNum = 0;	
	/*  Reserved Words		*/
"function"	{printf("FUNCTION\n"); charNum+=8;}
"beginparams"	{printf("BEGIN_PARAMS\n");charNum+=11;}
"endparams"	{printf("END_PARAMS\n");charNum+=9;}
"beginlocals"	{printf("BEGIN_LOCALS\n");charNum+=11;}
"endlocals"	{printf("END_LOCALS\n");charNum+=9;}
"beginbody"	{printf("BEGIN_BODY\n");charNum+=9;}
"endbody"	{printf("END_BODY\n");charNum+=7;}
"integer"	{printf("INTEGER\n");charNum+=7;}
"array"		{printf("ARRAY\n");charNum+=5;}
"of"		{printf("OF\n");charNum+=2;}
"if"		{printf("IF\n");charNum+=2;}
"then"		{printf("THEN\n");charNum+=4;}
"endif"		{printf("ENDIF\n");charNum+=5;}
"else"		{printf("ELSE\n");charNum+=4;}
"while"		{printf("WHILE\n");charNum+=5;}
"do"		{printf("DO\n");charNum+=2;}
"foreach"	{printf("FOREACH\n");charNum+=7;}
"in"		{printf("IN\n");charNum+=2;}
"beginloop"	{printf("BEGINLOOP\n");charNum+=9;}
"endloop"	{printf("ENDLOOP\n");charNum+=7;}
"continue"	{printf("CONTINUE\n");charNum+=8;}
"read"		{printf("READ\n");charNum+=4;}
"write"		{printf("WRITE\n");charNum+=5;}
"and"		{printf("AND\n");charNum+=3;}
"or"		{printf("OR\n");charNum+=2;}
"not"		{printf("NOT\n");charNum+=3;}
"true"		{printf("TRUE\n");charNum+=4;}
"false"		{printf("FALSE\n");charNum+=5;}
"return"	{printf("RETURN\n");charNum+=6;}
[0-9]+[a-zA-Z_]+[a-zA-Z_0-9]* {printf("Error at line %i, column %i: identifier \"%s\" must begin with a letter\n",lineNum, charNum, yytext);charNum+=strlen(yytext);exit(1);}
[_]+[a-zA-Z_0-9]*             {printf("Error at line %i, column %i: identifier \"%s\" must begin with a letter\n",lineNum, charNum, yytext);charNum+=strlen(yytext);exit(1);}
[a-zA-Z_0-9]*[_]+             {printf("Error at line %i, column %i: identifier \"%s\" cannot end with a underscore\n",lineNum, charNum, yytext);charNum+=strlen(yytext);exit(1);}
	/* identifier			IDENT XXXX*/
{IDENT}		{printf("IDENT %s\n", yytext);charNum+=strlen(yytext);}
	/* number			NUMBER XXXX*/

{DIGIT}		{printf("NUMBER %s\n", yytext);charNum+=strlen(yytext);}

	/*0 function calls 		()*/
"("	{printf("L_PAREN\n");charNum++;}
")"	{printf("R_PAREN\n");charNum++;}
	/*1 Arrary subscripting		[]*/
"["	{printf("L_SQUARE_BRACKET\n");charNum++;}
"]"	{printf("R_SQUARE_BRACKET\n");charNum++;}	
	/*2 Unary minus			-*/
	/*""	{printf("\n");}	*/
	/*3 Multiplication		**/
"*"	{printf("MULT\n");charNum++;}
	/*  Division			/*/
"/"	{printf("DIV\n");charNum++;}
	/*  Remainder 			%*/
"%"	{printf("MOD\n");charNum++;}
	/*4 Addition			+*/
"+"	{printf("ADD\n");charNum++;}
	/*  Subtraction			-*/
"-"	{printf("SUB\n");charNum++;}
	/*5 Relational operators 	<*/
"<"	{printf("LT\n");charNum++;}
	/*  ""				<=*/
"<="	{printf("LTE\n");charNum+=2;}
	/*  "" 				>*/
">"	{printf("GT\n");charNum++;}
	/*  ""				>=*/
">="	{printf("GTE\n");charNum+=2;}
	/*  ""				==*/
"=="	{printf("EQ\n");charNum+=2;}
	/*  ""				!=*/
"<>"	{printf("NEQ\n");charNum+=2;}
	/*9 Assignment 			Right-to-left*/
":="	{printf("ASSIGN\n");charNum+=2;}

";" 	{printf("SEMICOLON\n");charNum++;}	/* Semicolon */
":" 	{printf("COLON\n");charNum++;}		/* Colon     */
","	{printf("COMMA\n");charNum++;}		/* Comma     */

[\n]    lineNum++; charNum = 0;
[ ]     {charNum++;}			/* whitespace */
[\t]	{charNum++;}
.       {printf("Error at line %i, column %i: unrecognized symbol \"%s\"\n",lineNum, charNum, yytext); exit(1);}


%%

int main(int argc, char ** argv)
{
   yylex();
}

