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
[a-z]    {varname[0]=yytext[0]; yylval.no = createTree(-1,varname,VARNODE,NULL,NULL); return ID;}
[0-9]+	{number = atoi(yytext); yylval.no = createTree(number,NULL,NUMNODE,NULL,NULL); return NUM;}
"="	{return ASSIGN;}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
[ \t\n]  { ; }
\(    { return yytext[0]; }
\)    { return yytext[0]; }
";"	{return ENDOFLINE;}
.       { printf("syntax error: %s\n",yytext); exit(1); }

%%
int yywrap(void) {
	return 1;
}