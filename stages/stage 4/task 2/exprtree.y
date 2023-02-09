%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "exprtree.h"
	#include "exprtree.c"
	#include <string.h>

	int yylex(void);
    int yyerror();
	regs[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	extern FILE *yyin;
	nooffreereg=16;
	int label=0;
	struct gSymbolTable *gst;
%}
%union{
	struct tnode *no;
	char *name;
	int number;
	struct Gsymbol *Symbol;
}

%type <no> expr 
%type <no> STMNT 
%type <no> SLIST 
%type <no> INPUTSTMNT 
%type <no> OUTPUTSTMNT 
%type <no> program 
%type <no> ASSIGNSTMNT 
%type <no> IDENTIFIER
%type <no> IFSTMNT WHILESTMNT IFELSESTMNT DOWHILESTMNT BREAKSTMNT CONTINUESTMNT REPEATUNTILSTMNT

%type <number> TYPE
%type <name> ID
%type <number> NUM
%type <name> STR
%type <Symbol> IDDECL DECLSTMNT DEC VARLIST DECLARATIONS

%token READ 
%token WRITE 
%token NUM 
%token ENDOFLINE 
%token ASSIGN 
%token PLUS MINUS MUL DIV ID
%token REPEAT 
%token BREAK 
%token CONTINUE 
%token UNTIL 
%token STARTC 
%token ENDC 
%token DECL 
%token INT STR
%token BEGN ENDT
%type<number> INT

%token IF THEN ELSE WHILE DO  LT GT LE GE EQ NE AND OR NOT

%left AND OR NOT
%left LT GT LE GE EQ NE
%left PLUS MINUS
%left MUL DIV

%%

program : DECLARATIONS BEGN SLIST ENDT{
				printtree($3);
				FILE *target_file; 
    			target_file = fopen("ASSEMBLYCODE.xsm", "wb");
				$$ = $3;
				fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
				fprintf(target_file, "MOV SP, %d\n", 4096+(int)('z'-'a'));
                codeGen($3,target_file);
				fprintf(target_file, "INT 10");
				fclose(target_file);
				exit(0);
			}
		;
	| BEGN SLIST ENDT{
				exit(0);
			}
		;

DECLARATIONS: DECL STARTC DECLSTMNT ENDC {gst=(struct gSymbolTable*)malloc(sizeof(struct gSymbolTable));gst->head=$3;assignbinding(gst);printsymboltable(gst);$$=$3;}
	 | DECL STARTC ENDC {gst=(struct gSymbolTable*)malloc(sizeof(struct gSymbolTable));gst->head=NULL;$$=NULL;}
	 ;
;
DECLSTMNT: DECLSTMNT DEC {$$ = joinnode($1,$2); }
	 | DEC {$$ = $1;}
	 ;
DEC: TYPE VARLIST ENDOFLINE {struct Gsymbol* temp = $2;
                                        while(temp!=NULL){
                                            temp->type = $1;
                                            temp = temp->next;
                                        }
                                        $$ = $2;}
	 ;
VARLIST: VARLIST ',' IDDECL {$$=joinnode($1,$3);}
	 | IDDECL {$$ = $1;}
	 ;
IDDECL: ID {$$=createsymbolnode(gst,$<name>1,INVALIDTYPE,1);}
			 | ID '[' NUM ']' {$$=createsymbolnode(gst,$<name>1,INVALIDTYPE,$3);}
	 ;
TYPE: INT {$$ = INTTYPE;}
	 | STR {$$ = STRTYPE;}
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
	 | DOWHILESTMNT	{$$ = $1;}
	 | BREAKSTMNT	{$$ = $1;}
	 | CONTINUESTMNT	{$$ = $1;}
	 | REPEATUNTILSTMNT	{$$ = $1;}
	 ;

INPUTSTMNT : READ '(' ID ')' ENDOFLINE		{$$ = createTree(-1,INVALIDTYPE,NULL,READNODE,$3,NULL);}
	 ;

OUTPUTSTMNT : WRITE '(' expr ')' ENDOFLINE	{$$ = createTree(-1,INVALIDTYPE,NULL,WRITENODE,$3,NULL);}
	 ;

ASSIGNSTMNT : ID ASSIGN expr ENDOFLINE		{$$ = createTree(-1,INVALIDTYPE,NULL,ASSIGNNODE,$1,$3);}
	 ;

IFSTMNT : IF '(' expr ')' STARTC SLIST ENDC	{$$ = createTree(-1,INVALIDTYPE,NULL,IFNODE,$3,$6);}
	 ;

IFELSESTMNT: IF '(' expr ')' STARTC SLIST ENDC ELSE STARTC SLIST ENDC 	{$$ = createTree(-1,INVALIDTYPE,NULL,IFELSENODE,$3,createTree(-1,INVALIDTYPE,NULL,CONNECTORNODE,$6,$10));}
	 ;
WHILESTMNT : WHILE '(' expr ')' STARTC SLIST  ENDC	{$$ = createTree(-1,INVALIDTYPE,NULL,WHILENODE,$3,$6);}
	 ;
DOWHILESTMNT: DO  STARTC  SLIST ENDC WHILE '(' expr ')' ENDOFLINE	{$$ = createTree(-1,INVALIDTYPE,NULL,DOWHILENODE,$7,$3);}
	 ;
BREAKSTMNT: BREAK ENDOFLINE	{$$ = createTree(-1,INVALIDTYPE,NULL,BREAKNODE,NULL,NULL);}
	 ;
CONTINUESTMNT: CONTINUE ENDOFLINE	{$$ = createTree(-1,INVALIDTYPE,NULL,CONTINUENODE,NULL,NULL);}
	 ;
REPEATUNTILSTMNT: REPEAT STARTC SLIST ENDC UNTIL '(' expr ')' ENDOFLINE	{$$ = createTree(-1,INVALIDTYPE,NULL,REPEATUNTILNODE,$7,$3);}
	 ;

expr : expr PLUS expr	{$$ = createTree(-1,INTTYPE,"+",MATHOPNODE,$1,$3);}
	 | expr MINUS expr  {$$ = createTree(-1,INTTYPE,"-",MATHOPNODE,$1,$3);}
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
	 | NOT expr   		{$$=createTree(-1,BOOLTYPE,"!",LOGICOPNODE,$2,NULL);}
	 | '(' expr ')'		{$$ = $2;}
	 | IDENTIFIER	{$$=$1;}
	 | NUM			    {$$ = createTree($<number>1, INTTYPE, NULL, NUMNODE,NULL,NULL);}
     | STR              {$$ = createTree($<name>1, STRTYPE, NULL,STRNODE,NULL,NULL);}
	 ;
IDENTIFIER: ID {struct tnode* temp =createTree(-1,INVALIDTYPE,$<name>1,VARNODE,NULL,NULL);
				temp->type=findtype(gst,temp->varname);$$=temp;}
		    | ID '[' expr ']' {struct tnode* temp =createTree(-1,INVALIDTYPE,$<name>1,VARNODE,$3,NULL);
				temp->type=findtype(gst,temp->varname);
				printf("%d",evaluate($3));
				if(temp->Gentry->size<=evaluate($3))
				{
					yyerror("Array index out of bounds");
					exit(1);
				}
				$$=temp;
				}
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