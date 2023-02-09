%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "y.tab.h"
	#include "exprtree.h"
	int numb;
    int yyerror();

%}
int yyerror();
%%
"begin"  {return BEGN;}
"end"	 {return ENDT;}
"read"	 {return READ;}
"write"	 {return WRITE;}
"if" 	 {return IF;}
"else"	 {return ELSE;}
"while"	 {return WHILE;}
"repeat" {return REPEAT;}
"until"  {return UNTIL;}
"break"  {return BREAK;}
"continue" {return CONTINUE;}
"decl"	 {return DECL;}
"int"   {return INT;}
"str"   {return STR;}
[,] 	{return *yytext;}
[{]	{return STARTC;}
[}]	{return ENDC;}
"do"     {return DO;}
[_a-zA-Z][_a-zA-Z0-9]*	{yylval.name=strdup(yytext);return ID; }
[0-9]+	{numb = atoi(yytext);yylval.number=numb;return NUM;}
\"((\\\")|[^"])*\" {yylval.name=strdup(yytext);return STR;}
"="	 {return ASSIGN;}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
"<"	{return LT;}
">"	{return GT;}
"=="	{return EQ;}
"!="	{return NE;}
"<="	{return LE;}
">="	{return GE;}
"&&"	{return AND;}
"||"	{return OR;}
"!"	{return NOT;}

[ \t\n]  { ; }
\(    { return yytext[0]; }
\)    { return yytext[0]; }
";"	{return ENDOFLINE;}
.       { printf("syntax error: %s\n",yytext); exit(1); }

%%
int yywrap(void) {
	return 1;
}