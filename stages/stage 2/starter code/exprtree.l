%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "y.tab.h"
	#include "exprtree.h"

	int number;
    int yyerror();
	char* varname;

%}
int yyerror();
%%
"begin"  {return BEGIN;}
"end"	 {return END;}
"read"	 {return READ;}
"write"	 {return WRITE;}
[a-z]    {strcpy(varname,yytext); yylval.no = makeLeafVariableNode(varname); return ID;}
[0-9]+	{number = atoi(yytext); yylval.no = makeLeafNode(number); return NUM;}
'='		{return ASSIGN;}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
[ \t]	{}
[\n]	{}
"("	{return OPENPARANTH;}
")"	{return CLOSEPARANTH;}
";"	{return ENDOFLINE;}
.	{yyerror("unknown character\n");exit(1);}

%%
int yywrap(void) {
	return 1;
}