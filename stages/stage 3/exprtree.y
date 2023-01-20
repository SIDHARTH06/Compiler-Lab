%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "exprtree.h"
	#include "exprtree.c"
	int yylex(void);
    int yyerror();
	regs[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	extern FILE *yyin;
	nooffreereg=16;
	int label=0;
%}
%union{
	struct tnode *no;
}

%type <no> expr STMNT SLIST INPUTSTMNT OUTPUTSTMNT program ID NUM ASSIGNSTMNT IFSTMNT WHILESTMNT IFELSESTMNT
%token READ WRITE NUM ID ENDOFLINE ASSIGN PLUS MINUS MUL DIV BEG ENOFLINE END
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE LT GT LE GE EQ NE AND OR NOT
%left AND OR NOT
%left LT GT LE GE EQ NE
%left PLUS MINUS
%left MUL DIV

%%

program : BEG SLIST END{
				inorder($2);
				FILE *target_file; 
    			target_file = fopen("ASSEMBLYCODE.xsm", "wb");
				$$ = $2;
				fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
				fprintf(target_file, "MOV SP, %d\n", 4096+(int)('z'-'a'));
                codeGen($2,target_file);
				fprintf(target_file, "INT 10");
				fclose(target_file);
                exit(0);
			}
		;
	| BEG END{
				exit(0);
			}
		;

SLIST: SLIST STMNT		{$$ = createTree(-1,INVALIDTYPE,NULL,CONNECTORNODE,$1,$2);}
	 | STMNT			{$$ = $1;}
	 ;
STMNT: INPUTSTMNT	{$$ = $1;}
	 | OUTPUTSTMNT	{$$ = $1;}
	 | ASSIGNSTMNT	 {$$ = $1;}
	 | IFSTMNT		{$$ = $1;}
	 | IFELSESTMNT	{$$ = $1;}
	 | WHILESTMNT	{$$ = $1;}
	 ;

INPUTSTMNT : READ '(' ID ')' ENDOFLINE		{$$ = createTree(-1,INVALIDTYPE,NULL,READNODE,$3,NULL);}
	 ;

OUTPUTSTMNT : WRITE '(' expr ')' ENDOFLINE	{$$ = createTree(-1,INVALIDTYPE,NULL,WRITENODE,$3,NULL);}
	 ;

ASSIGNSTMNT : ID ASSIGN expr ENDOFLINE		{$$ = createTree(-1,INVALIDTYPE,NULL,ASSIGNNODE,$1,$3);}
	 ;

IFSTMNT : IF '(' expr ')' THEN SLIST ENDIF	{$$ = createTree(-1,INVALIDTYPE,NULL,IFNODE,$3,$6);}
	 ;

IFELSESTMNT: IF '(' expr ')' THEN SLIST ELSE SLIST ENDIF	{$$ = createTree(-1,INVALIDTYPE,NULL,IFELSENODE,$3,createTree(-1,INVALIDTYPE,NULL,CONNECTORNODE,$6,$8));}
	 ;

WHILESTMNT : WHILE '(' expr ')' DO SLIST ENDWHILE	{$$ = createTree(-1,INVALIDTYPE,NULL,WHILENODE,$3,$6);}
	 ;

expr : expr PLUS expr		{$$ = createTree(-1,INTTYPE,"+",MATHOPNODE,$1,$3);}
	 | expr MINUS expr  	{$$ = createTree(-1,INTTYPE,"-",MATHOPNODE,$1,$3);}
	 | expr MUL expr	{$$ = createTree(-1,INTTYPE,"*",MATHOPNODE,$1,$3);}
	 | expr DIV expr	{$$ = createTree(-1,INTTYPE,"/",MATHOPNODE,$1,$3);}
	 | expr LT expr   	{$$=createTree(-1,BOOLTYPE,"<",LOGICOPNODE,$1,$3);}
	 | expr GT expr   	{$$=createTree(-1,BOOLTYPE,">",LOGICOPNODE,$1,$3);}
	 | expr LE expr   	{$$=createTree(-1,BOOLTYPE,"<=",LOGICOPNODE,$1,$3);}
	 | expr GE expr   	{$$=createTree(-1,BOOLTYPE,">=",LOGICOPNODE,$1,$3);}
	 | expr EQ expr   	{$$=createTree(-1,BOOLTYPE,"==",LOGICOPNODE,$1,$3);}
	 | expr NE expr   	{$$=createTree(-1,BOOLTYPE,"!=",LOGICOPNODE,$1,$3);}
	 | expr AND expr   	{$$=createTree(-1,BOOLTYPE,"&&",LOGICOPNODE,$1,$3);}
	 | expr OR expr   	{$$=createTree(-1,BOOLTYPE,"||",LOGICOPNODE,$1,$3);}
	 | NOT expr   	{$$=createTree(-1,BOOLTYPE,"!",LOGICOPNODE,$2,NULL);}
	 | '(' expr ')'		{$$ = $2;}
	 | ID			{$$ = $1;}
	 | NUM			{$$ = $1;}
	 ;
%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}


int main(int argc, char* argv[]) {
	if(argc > 1)
 	{
  		FILE *fp = fopen(argv[1], "r");
  		if(fp)
   			yyin = fp;
 	}
	yyparse();
	return 0;
}