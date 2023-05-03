%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "astfunctions.h"
	#include "astfunctions.c"
	#include <string.h>
	#include "symboltable.c">

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
%type <name> STRNG
%type <number> NUM
%type <name> STR
%type <Symbol> IDDECL DECLSTMNT DEC VARLIST DECLARATIONS

%token STRNG
%token ADDRESS
%token READ 
%token WRITE 
%token NUM 
%token ENDOFLINE 
%token ASSIGN 
%token PLUS MINUS MUL DIV ID MOD
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
%left MOD

%%

program : DECLARATIONS BEGN SLIST ENDT
{
				printf("printing the AST: \n");
				printtree($3);
				FILE *target_file; 
    			target_file = fopen("ASSEMBLYCODE.xsm", "wb");
				$$ = $3;
				//entry point
				fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
				fprintf(target_file, "MOV SP, %d\n", 4096+(int)('z'-'a'));

                codeGen($3,target_file);

				//exit syscall
				fprintf(target_file, "MOV R0,\"Exit\"\n");
        		fprintf(target_file, "PUSH R0\n");
        		fprintf(target_file, "PUSH R0\n");
        		fprintf(target_file, "PUSH R0\n");
        		fprintf(target_file, "PUSH R0\n");
        		fprintf(target_file, "PUSH R0\n");
        		fprintf(target_file, "CALL 0");
				exit(0);
}
		;
	| BEGN SLIST ENDT{
				
				exit(0);
			}
	| BEGN ENDT{
				exit(0);
			}
	;

DECLARATIONS: DECL STARTC DECLSTMNT ENDC 
	{

	 	gst=(struct gSymbolTable*)malloc(sizeof(struct gSymbolTable));
	 	gst->head=$3;assignbinding(gst);
		if(findduplicate(gst))
		{
			yyerror("Duplicate declaration");
			exit(1);
		}

	 	//printsymboltable(gst);
	 	$$=$3;
	}
	| DECL STARTC ENDC 
	{
		gst=(struct gSymbolTable*)malloc(sizeof(struct gSymbolTable));
		gst->head=NULL;
		$$=NULL;
	}
	;
DECLSTMNT: DECLSTMNT DEC 
	{
		$$ = joinnode($1,$2);
	}
	| DEC 
	{
		$$ = $1;
	}
	;
DEC: TYPE VARLIST ENDOFLINE 
	{
		struct Gsymbol* temp = $2;
        while(temp!=NULL)
		{
            temp->type = $1;
            temp = temp->next;
        }
        $$ = $2;
	}
	;
VARLIST: VARLIST ',' IDDECL 
	{
		$$=joinnode($1,$3);
	}
	| IDDECL 
	{
		$$ = $1;
	}
	;
IDDECL: ID 
	{
		$$=createsymbolnode(gst,$<name>1,INVALIDTYPE,1,1);
	}
	| ID '[' NUM ']' 
	{
		$$=createsymbolnode(gst,$<name>1,INVALIDTYPE,$<number>3,$<number>3);
	}
	| ID '[' NUM ']' '[' NUM ']'	
	{
		$$ = createsymbolnode(gst,$<name>1,INVALIDTYPE,($<number>3*$<number>6),$<number>3);
	}
	| MUL ID 
	{
		$$=createsymbolnode(gst,$<name>2,INVALIDTYPE,1,0);
	}
	;
TYPE: INT 
	{
		$$ = INTTYPE;
	}
	| STR 
	{
		$$ = STRTYPE;
	}
	;

SLIST: SLIST STMNT		
	{
		$$ = createTree(-1,INVALIDTYPE,NULL,CONNECTORNODE,$1,$2);
	}
	| STMNT			
	{
		$$ = $1;
	}
	;


STMNT: INPUTSTMNT	
	{
		$$ = $1;
	}
	| OUTPUTSTMNT	
	{
		$$ = $1;
	}
	| ASSIGNSTMNT	 
	{
		$$ = $1;
	}
	| IFSTMNT		
	{
		$$ = $1;
	}
	| IFELSESTMNT	
	{
		$$ = $1;
	}
	| WHILESTMNT	
	{
		$$ = $1;
	}
	| DOWHILESTMNT	
	{
		$$ = $1;
	}
	| BREAKSTMNT	
	{
		$$ = $1;
	}
	| CONTINUESTMNT	
	{
		$$ = $1;
	}
	| REPEATUNTILSTMNT	
	{
		$$ = $1;
	}
	;

INPUTSTMNT : READ '(' IDENTIFIER ')' ENDOFLINE		
	{
		$$ = createTree(-1,INVALIDTYPE,NULL,READNODE,$3,NULL);
	}
	;

OUTPUTSTMNT : WRITE '(' expr ')' ENDOFLINE	
	{
		$$ = createTree(-1,INVALIDTYPE,NULL,WRITENODE,$3,NULL);
	}
	;

ASSIGNSTMNT : IDENTIFIER ASSIGN expr ENDOFLINE		
	{
		$$ = createTree(-1,INVALIDTYPE,NULL,ASSIGNNODE,$1,$3);
	}
	| IDENTIFIER ASSIGN ADDRESS IDENTIFIER ENDOFLINE	
	{
		struct tnode *temp = createTree(-1, INVALIDTYPE, NULL, ADDRNODE, $4,NULL);
            $$ = createTree(-1, INVALIDTYPE, NULL, ASSIGNNODE, $1,temp);
	}
	;

IFSTMNT : IF '(' expr ')' STARTC SLIST ENDC	
	{
		$$ = createTree(-1,INVALIDTYPE,NULL,IFNODE,$3,$6);
	}
	;

IFELSESTMNT: IF '(' expr ')' STARTC SLIST ENDC ELSE STARTC SLIST ENDC 	
	{
		$$ = createTree(-1,INVALIDTYPE,NULL,IFELSENODE,$3,createTree(-1,INVALIDTYPE,NULL,CONNECTORNODE,$6,$10));
	}
	;
WHILESTMNT : WHILE '(' expr ')' STARTC SLIST  ENDC	
	{
		$$ = createTree(-1,INVALIDTYPE,NULL,WHILENODE,$3,$6);
	}
	;
DOWHILESTMNT: DO  STARTC  SLIST ENDC WHILE '(' expr ')' ENDOFLINE	
	{
		$$ = createTree(-1,INVALIDTYPE,NULL,DOWHILENODE,$7,$3);
	}
	;
BREAKSTMNT: BREAK ENDOFLINE	
	{
		$$ = createTree(-1,INVALIDTYPE,NULL,BREAKNODE,NULL,NULL);
	}
	;
CONTINUESTMNT: CONTINUE ENDOFLINE	
	{
		$$ = createTree(-1,INVALIDTYPE,NULL,CONTINUENODE,NULL,NULL);
	}
	;
REPEATUNTILSTMNT: REPEAT STARTC SLIST ENDC UNTIL '(' expr ')' ENDOFLINE	
	{
		$$ = createTree(-1,INVALIDTYPE,NULL,REPEATUNTILNODE,$7,$3);
	}
	;

expr : expr PLUS expr	{$$ = createTree(-1,INTTYPE,"+",MATHOPNODE,$1,$3);}
	 | expr MINUS expr  {$$ = createTree(-1,INTTYPE,"-",MATHOPNODE,$1,$3);}
	 | expr MUL expr	{$$ = createTree(-1,INTTYPE,"*",MATHOPNODE,$1,$3);}
	 | expr DIV expr	{$$ = createTree(-1,INTTYPE,"/",MATHOPNODE,$1,$3);}
	 | expr MOD expr	{$$ = createTree(-1,INTTYPE,"M",MATHOPNODE,$1,$3);}
	 | expr LT expr   	{$$ = createTree(-1,BOOLTYPE,"<",LOGICOPNODE,$1,$3);}
	 | expr GT expr   	{$$ = createTree(-1,BOOLTYPE,">",LOGICOPNODE,$1,$3);}
	 | expr LE expr   	{$$ = createTree(-1,BOOLTYPE,"<=",LOGICOPNODE,$1,$3);}
	 | expr GE expr   	{$$ = createTree(-1,BOOLTYPE,">=",LOGICOPNODE,$1,$3);}
	 | expr EQ expr   	{$$ = createTree(-1,BOOLTYPE,"==",LOGICOPNODE,$1,$3);}
	 | expr NE expr   	{$$ = createTree(-1,BOOLTYPE,"!=",LOGICOPNODE,$1,$3);}
	 | expr AND expr   	{$$ = createTree(-1,BOOLTYPE,"&&",LOGICOPNODE,$1,$3);}
	 | expr OR expr   	{$$ = createTree(-1,BOOLTYPE,"||",LOGICOPNODE,$1,$3);}
	 | NOT expr   		{$$ = createTree(-1,BOOLTYPE,"!",LOGICOPNODE,$2,NULL);}
	 | '(' expr ')'		{$$ = $2;}
	 | IDENTIFIER		{$$ = $1;}
	 | NUM			    {$$ = createTree($<number>1, INTTYPE, NULL, NUMNODE,NULL,NULL);}
     | STRNG              {$$ = createTree(-1, STRTYPE, $<name>1,STRNODE,NULL,NULL);}
	 ;


IDENTIFIER: ID 
	{
		struct tnode* temp =createTree(-1,INVALIDTYPE,$<name>1,VARNODE,NULL,NULL);
		temp->type=findtype(gst,temp->varname);
		$$=temp;
	}
	| ID '[' expr ']'
	{
		struct tnode* temp =createTree(-1,INVALIDTYPE,$<name>1,VARNODE,$3,NULL);
		temp->type=findtype(gst,temp->varname);
		if($3->nodetype==NUMNODE && temp->Gentry->size<=evaluate($3))
		{
			yyerror("Array index out of bounds");
			exit(1);
		}
		$$=temp;
	}
	;
	| ID '[' expr ']' '[' expr ']'  
	{ 
		struct tnode* temp = createTree(-1, INVALIDTYPE, $<name>1,VARNODE,$3,$6);
        findtype(gst,temp);
        if(temp->Gentry->size <= (evaluate($3)*evaluate($6))) 
			yyerror("Array index out of bounds"); // need to check for out of bounds
		printf("temp :%s",temp->varname);
    	$$ = temp;
	}
            ;
	| MUL ID 
	{
		struct tnode* temp =createTree(-1,INVALIDTYPE,$<name>2,VARNODE,NULL,NULL);
		temp->type=findtype(gst,temp->varname);
		struct tnode* temp1 =createTree(-1,temp->type,NULL,PTRNODE,temp,NULL);
		$$=temp1;
	}

%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}


int main(int argc, char* argv[]) 
{
	if(argc > 1)
 	{
  		FILE *fp = fopen(argv[1], "r");
  		if(fp)
   			yyin = fp;
 	}
	yyparse();
	return 0;
}