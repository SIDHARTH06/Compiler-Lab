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
%type <no> expr STMNT SLIST INPUTSTMNT OUTPUTSTMNT program ID NUM
%token READ WRITE NUM ID ENDOFLINE ASSIGN PLUS MINUS MUL DIV BEGIN ENOFLINE END OPENPARANTH CLOSEPARANTH

%%

program : BEGIN SLIST END{
				$$=$2;
				printf("test");
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

SLIST: STMNT SLIST		{$$ = makeConnectornode($1,$2);}
	 | STMNT			{$$ = $1;}
	 ;
STMNT: INPUTSTMNT	{$$ = $1;}
	 | OUTPUTSTMNT	{$$ = $1;}
	 | ID ASSIGN expr ENDOFLINE	 {$$ = makeOperatorNode($1,$3);}
	 | expr ENDOFLINE		{$$ = $1;}
	 ;
INPUTSTMNT : READ ID ENDOFLINE		{$$ = makeReadNode($2);}
	 ;
OUTPUTSTMNT : WRITE expr ENDOFLINE	{$$ = makeWriteNode($2);}
	 ;
expr : expr PLUS expr		{$$ = makeOperatorNode(PLUS,$1,$3);}
	 | expr MINUS expr  	{$$ = makeOperatorNode(MINUS,$1,$3);}
	 | expr MUL expr	{makeOperatorNode(MUL,$1,$3);}
	 | expr DIV expr	{$$ = makeOperatorNode(DIV,$1,$3);}
	 | OPENPARANTH expr CLOSEPARANTH		{$$ = $2;}
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