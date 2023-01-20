%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "y.tab.h"
	#include "exprtree.h"
	int number;
    int yyerror();
	char varname[1];

%}
int yyerror();
%%
"begin"  {return BEG;}
"end"	 {return END;}
"read"	 {return READ;}
"write"	 {return WRITE;}
"if" 	 {return IF;}
"then"	 {return THEN;}
"else"	 {return ELSE;}
"endif"	 {return ENDIF;}
"while"	 {return WHILE;}
"endwhile" {return ENDWHILE;}
"do"     {return DO;}
[a-z]    {varname[0]=yytext[0]; yylval.no = createTree(-1,INVALIDTYPE,varname,VARNODE,NULL,NULL); return ID;}
[0-9]+	{number = atoi(yytext); yylval.no = createTree(number,INTTYPE,NULL,NUMNODE,NULL,NULL); return NUM;}
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