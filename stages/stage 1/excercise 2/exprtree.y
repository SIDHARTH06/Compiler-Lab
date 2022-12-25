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
%type <no> expr NUM program END
%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

program : expr END	{
				FILE *target_file; 
    			target_file = fopen("a.xsm", "ab");
				$$ = $2;
				fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
                codeGen($1,target_file);
				fprintf(target_file, "\nINT 10");
				fclose(target_file);
                exit(0);
                
			}
		;

expr : expr PLUS expr		{$$ = makeOperatorNode('+',$1,$3);}
	 | expr MINUS expr  	{$$ = makeOperatorNode('-',$1,$3);}
	 | expr MUL expr	{$$ = makeOperatorNode('*',$1,$3);}
	 | expr DIV expr	{$$ = makeOperatorNode('/',$1,$3);}
	 | '(' expr ')'		{$$ = $2;}
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