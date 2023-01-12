%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "exprtree.h"
	#include "exprtree.c"
	int yylex(void);
    int yyerror();
%}
%union{
	struct tnode *no;
}

%type <no> expr STMNT SLIST INPUTSTMNT OUTPUTSTMNT program ID NUM ASSIGNSTMNT
%token READ WRITE NUM ID ENDOFLINE ASSIGN PLUS MINUS MUL DIV BEG ENOFLINE END
%left PLUS MINUS
%left MUL DIV

%%

program : BEG SLIST END{
				$$=$2;
				preorder($2);
				exit(0);
				/*
				FILE *target_file; 
    			target_file = fopen("a.xsm", "ab");
				$$ = $2;
				fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
                codeGen($1,target_file);
				fprintf(target_file, "INT 10");
				fclose(target_file);
                exit(0);
				*/

                
			}
		;
	| BEG END{
				exit(0);
			}
		;

SLIST: SLIST STMNT		{$$ = createTree(-1,NULL,CONNECTORNODE,$1,$2);}
	 | STMNT			{$$ = $1;}
	 ;
STMNT: INPUTSTMNT	{$$ = $1;}
	 | OUTPUTSTMNT	{$$ = $1;}
	 | ASSIGNSTMNT	 {$$ = $1;}
	 ;

INPUTSTMNT : READ '(' ID ')' ENDOFLINE		{$$ = createTree(-1,NULL,READNODE,$3,NULL);}
	 ;

OUTPUTSTMNT : WRITE '(' expr ')' ENDOFLINE	{$$ = createTree(-1,NULL,WRITENODE,$3,NULL);}
	 ;

ASSIGNSTMNT : ID ASSIGN expr ENDOFLINE		{$$ = createTree(-1,NULL,ASSIGNNODE,$1,$3);}
	 ;

expr : expr PLUS expr		{$$ = createTree(-1,"+",MATHOPNODE,$3,NULL);}
	 | expr MINUS expr  	{$$ = createTree(-1,"-",MATHOPNODE,$3,NULL);}
	 | expr MUL expr	{$$ = createTree(-1,"*",MATHOPNODE,$3,NULL);}
	 | expr DIV expr	{$$ = createTree(-1,"/",MATHOPNODE,$3,NULL);}
	 | '(' expr ')'		{$$ = $2;}
	 | ID			{$$ = $1;}
	 | NUM			{$$ = $1;}
	 ;
%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}


int main(void) {
	yyparse();
	
	return 0;
}