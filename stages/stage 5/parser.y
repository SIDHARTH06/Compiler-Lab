%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "astfunctions.h"
	#include "astfunctions.c"
	#include <string.h>
	#include "symboltable.c"

	int yylex();
    int yyerror();
	regs[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	extern FILE *yyin;
	nooffreereg=16;
	int label=0;
	struct gSymbolTable *gst;
	struct lSymbolTable *lst;
	int gm=4096;
	int flabel=0;
	int cb=0;
	FILE* target_file;
%}
%union{
	struct tnode *no;
	char *name;
	int number;
	struct Gsymbol *Symbol;
	struct Lsymbol *Lsymbol;
	struct paramstruct* paramlist;
	struct arglist* arglist;
}

%type <no> expr 
%type <no> STMNT 
%type <no> SLIST 
%type <no> INPUTSTMNT 
%type <no> OUTPUTSTMNT 
%type <no> program 
%type <no> ASSIGNSTMNT 
%type <no> IDENTIFIER
%type <no> FNCALLSTMNT
%type <no> RETURNSTMNT
%type <no> IFSTMNT WHILESTMNT IFELSESTMNT DOWHILESTMNT BREAKSTMNT CONTINUESTMNT REPEATUNTILSTMNT


%type <number> TYPE
%type <name> ID
%type <name> STRNG
%type <number> NUM
%type <number> STR
%type <Symbol> IDDECL DEC VARLIST
%type <Lsymbol>  LDECLSTMNT LDECLARATIONS LVARLIST LIDDECL
%type <arglist> ARGMNTLIST
%type <Symbol> GDECLBLOCK FDEFBLOCK MAINBLOCK FDEF GDEC FDECNAME
%type <paramlist> PARAMLIST

%token STRNG
%token ADDRESS
%token READ 
%token WRITE 
%token NUM 
%token ENDOFLINE 
%token ASSIGN LDECH ELDECH
%token PLUS MINUS MUL DIV ID MOD
%token REPEAT 
%token BREAK 
%token CONTINUE 
%token UNTIL 
%token STARTC 
%token ENDC 
%token INT STR
%token BEGN ENDT
%token MAIN
%token RETURN
%token DECL
%type<number> INT

%token IF THEN ELSE WHILE DO  LT GT LE GE EQ NE AND OR NOT

%left AND OR NOT
%left LT GT LE GE EQ NE
%left PLUS MINUS
%left MUL DIV
%left MOD
%%

program : GDECLBLOCK FDEFBLOCK MAINBLOCK
	{
		printf("Parsing Complete\n");
		fclose(target_file);
	}
	;
	| GDECLBLOCK MAINBLOCK
	{
		printf("Parsing Complete\n");
		fclose(target_file);
	}
	| MAINBLOCK
	{
		printf("test");
		printf("Parsing Complete\n");		
		fclose(target_file);
	}
	;
GDECLBLOCK: DECL STARTC GDEC ENDC
{
	printf("test");
	$$=$3;
	gst = ( struct gSymbolTable* ) malloc(sizeof(struct gSymbolTable));
    gst->head = $3;
    assignbinding(gst,gm);
	printglobalsymboltable(gst);
	if (findduplicate(gst))
	{
		yyerror("Duplicate Declaration\n");
		exit(1);
	}
    target_file = fopen("ASSEMBLYCODE.xsm", "w");
    fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
    fprintf(target_file, "MOV SP, %d\n", 4095);
    fprintf(target_file, "MOV BP, %d\n", 4096);
    fprintf(target_file, "PUSH R0\n");
     while( gm-- > 4096){
        fprintf(target_file, "PUSH R0\n");
    }


    fprintf(target_file, "CALL MAIN\n");


    fprintf(target_file, "MOV R0,\"Exit\"\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "CALL 0\n");
}
;
GDEC: GDEC DEC 
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
	struct Gsymbol* temp=$2;
	while(temp!=NULL)
	{
		temp->type=$1;
		temp=temp->next;
	}
	$$=$2;
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
		$$=createsymbolnode(gst,$<name>1,INVALIDTYPE,1,1,-1,NULL,NULL,-1);
	}
	| ID '[' NUM ']' 
	{
		$$=createsymbolnode(gst,$<name>1,INVALIDTYPE,$<number>3,$<number>3,-1,NULL,NULL,-1);
	}
	| ID '[' NUM ']' '[' NUM ']'	
	{
		$$ = createsymbolnode(gst,$<name>1,INVALIDTYPE,($<number>3*$<number>6),$<number>3,-1,NULL,NULL,-1);
	}
	| MUL ID 
	{
		$$=createsymbolnode(gst,$<name>2,INVALIDTYPE,1,0,-1,NULL,NULL,-1);
	}
	| FDECNAME
	{
		$$=$1;
	}
	;

FDECNAME: ID '(' PARAMLIST ')'
{
	$$=createsymbolnode(gst,$<name>1,INVALIDTYPE,0,0,-1,$3,NULL,flabel++);
}
| ID '(' ')'
{
	$$=createsymbolnode(gst,$<name>1,INVALIDTYPE,0,0,-1,NULL,NULL,flabel++);
}
;


PARAMLIST: PARAMLIST ',' TYPE ID
{
	$$=joinparamnode($1,createparamnode($<name>4,$3,1,1));
}
| TYPE ID
{
	$$=createparamnode($<name>2,$1,1,1);
}
;

FDEFBLOCK: FDEFBLOCK FDEF
	{
		$$=$1;
	}
	| FDEF
	{
		$$=$1;
	}
;
FDEF: TYPE ID '(' PARAMLIST ')' STARTC LDECH LDECLARATIONS ELDECH SLIST ENDC
{
	printf("test");
	struct Gsymbol *temp = lookup(gst,$<name>2);
	temp->paramlist=$4;
	struct lSymbolTable *lst = (struct lSymbolTable*)malloc(sizeof(struct lSymbolTable));
	lst->head=$8;
	printlocalsymboltable(lst);
	temp->lsth=lst->head;
	temp->flabel=flabel;
	fprintf(target_file, "F%d:\n ",flabel);
	flabel++;
	$$=NULL;
	if(temp==NULL)
	{
		printf("Function %s not declared\n",$<name>2);
		exit(1);
	}
	else
	{

		if(temp->type!=$1)
			{
				printf("Function %s return type mismatch\n",$<name>2);
				exit(1);
			}
			else
			{
				if(temp->paramlist==NULL && $4==NULL)
				{
					addargtolst(temp->lsth,temp->paramlist);
					//create activation record
                    fprintf(target_file , "PUSH BP\n");
                    fprintf(target_file , "MOV BP, SP\n");
                    //push reg on stack for lst
					temp = $8;
					while(temp!=NULL)
					{
						fprintf(target_file, "PUSH R0\n");
						temp=temp->next;
					}
					codeGen($10,target_file,lst);
                    //pop reg for lst
					temp = $8;
					while(temp!=NULL)
					{
						fprintf(target_file, "POP R0\n");
						temp=temp->next;
					}
					fprintf(target_file, "MOV BP, [SP]\n");
                    fprintf(target_file, "POP R0\n");
                    fprintf(target_file, "RET\n");
                    free($8);
				}
				else if(temp->paramlist==NULL && $4!=NULL)
				{
					printf("Function %s parameter mismatch\n",$<name>2);
					exit(1);
				}
				else if(temp->paramlist!=NULL && $4==NULL)
				{
					printf("Function %s parameter mismatch\n",$<name>2);
					exit(1);
				}
				else
				{
					struct paramstruct *temp1 = temp->paramlist;
					struct Lsymbol *temp2 = $4;
					while(temp1!=NULL && temp2!=NULL)
					{
						if(temp1->type!=temp2->type)
						{
							printf("Function %s parameter mismatch\n",$<name>2);
							exit(1);
						}
						temp1=temp1->next;
						temp2=temp2->next;
					}
					if(temp1!=NULL || temp2!=NULL)
					{
						printf("Function %s parameter mismatch\n",$<name>2);
						exit(1);
					}
					else
					{
						addargtolst(lst,temp->paramlist);
						//create activation record
                    	fprintf(target_file , "PUSH BP\n");
                    	fprintf(target_file , "MOV BP, SP\n");
                    	//push reg on stack for lst
						temp = $8;
						while(temp!=NULL)
						{
							fprintf(target_file, "PUSH R0\n");
							temp=temp->next;
						}
						assignbindinglocal(lst);
						codeGen($10,target_file,lst);
                    	//pop reg for lst
						temp = $8;
						while(temp!=NULL)
						{
							fprintf(target_file, "POP R0\n");
							temp=temp->next;
						}
						fprintf(target_file, "MOV BP, [SP]\n");
                    	fprintf(target_file, "POP R0\n");
                    	fprintf(target_file, "RET\n");
                    	freelst($8);
					}
				}
			}
		}
	}
;
FDEF: TYPE ID '(' ')' STARTC LDECH LDECLARATIONS ELDECH SLIST ENDC
{
	struct Gsymbol *temp = lookup(gst,$<name>2);
	temp->paramlist=NULL;
	struct lSymbolTable *lst = (struct lSymbolTable*)malloc(sizeof(struct lSymbolTable));
	lst->head=$7;
	printlocalsymboltable(lst);
	temp->lsth=lst->head;
	temp->flabel=flabel;
	fprintf(target_file, "F%d:\n ",flabel);
	flabel++;
	$$=NULL;
	if(temp==NULL)
	{
		printf("Function %s not declared\n",$<name>2);
		exit(1);
	}
	else
	{

		if(temp->type!=$1)
			{
				printf("Function %s return type mismatch\n",$<name>2);
				exit(1);
			}
			else
			{
				if(temp->paramlist==NULL)
				{
					addargtolst(temp->lsth,temp->paramlist);
					//create activation record
                    fprintf(target_file , "PUSH BP\n");
                    fprintf(target_file , "MOV BP, SP\n");
                    //push reg on stack for lst
					temp = $7;
					while(temp!=NULL)
					{
						fprintf(target_file, "PUSH R0\n");
						temp=temp->next;
					}
					codeGen($9,target_file,lst);
                    //pop reg for lst
					temp = $7;
					while(temp!=NULL)
					{
						fprintf(target_file, "POP R0\n");
						temp=temp->next;
					}
					fprintf(target_file, "MOV BP, [SP]\n");
                    fprintf(target_file, "POP R0\n");
                    fprintf(target_file, "RET\n");
                    free($7);
				}
				else
				{
					printf("Function %s parameter mismatch\n",$<name>2);
					exit(1);
				}
			}
	}
				
}
;
MAINBLOCK: MAIN '(' ')' STARTC LDECH LDECLARATIONS ELDECH SLIST ENDC
{
	check();
	if(gst==NULL)
	{
		target_file = fopen("ASSEMBLYCODE.xsm", "w");
    fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
    fprintf(target_file, "MOV SP, %d\n", 4095);
    fprintf(target_file, "MOV BP, %d\n", 4096);
    fprintf(target_file, "PUSH R0\n");
     while( gm-- > 4096){
        fprintf(target_file, "PUSH R0\n");
    }


    fprintf(target_file, "CALL MAIN\n");


    fprintf(target_file, "MOV R0,\"Exit\"\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "CALL 0\n");
	}
	
	if(target_file==NULL)	
	{
		target_file = fopen("ASSEMBLYCODE.xsm", "a");
	}
    int cb = 1;
	struct lSymbolTable *lst = (struct lSymbolTable*)malloc(sizeof(struct lSymbolTable));
	lst->head=$6;
	printlocalsymboltable(lst);
    struct Lsymbol* temp1 = (struct Lsymbol*)malloc(sizeof(struct Lsymbol));
	temp1 = $6;
	if (temp1 == NULL){
		cb = 1;
	}
	else{
    while (temp1!=NULL){
		if(temp1->binding==0)
			break;
        temp1 = temp1->next;
    }
    while (temp1 != NULL){
        temp1->binding = cb;
        cb += 1;
        temp1 = temp1->next;
    }
	}
	fprintf(target_file,  "MAIN:\n");
    fprintf(target_file , "PUSH BP\n");
    fprintf(target_file , "MOV BP, SP\n");
	temp1=$8;
    while (temp1 != NULL)
    {
        fprintf(target_file, "PUSH R0\n");
        temp1 = temp1->next;
    }
    codeGen($8,target_file,lst);
    temp1 = lst->head;
    while (temp1 != NULL)
    {
        fprintf(target_file, "POP R0\n");
        temp1 = temp1->next;
    }

    fprintf(target_file, "MOV BP, [SP]\n");
    fprintf(target_file, "POP R0\n");
	fprintf(target_file, "RET\n");
    freelst(lst);
}
;


LDECLARATIONS: LDECLARATIONS LDECLSTMNT
	{
		struct Lsymbol *temp = $1;
		$$ = joinnodel($1,$2);
	}
	| LDECLSTMNT
	{
		$$ = $1;
	}
;

LDECLSTMNT: TYPE LVARLIST ENDOFLINE 
	{
		printf("test");
		struct Lsymbol* temp = $2;
        while(temp!=NULL)
		{
            temp->type = $1;
            temp = temp->next;
        }
		$$ = $2;
	}
	;
LVARLIST: LVARLIST ',' LIDDECL
	{
		printf("test");
		$$=joinnodel($1,$3);
	}
	| LIDDECL
	{
		printf("test");
		$$=$1;
	}
	;
LIDDECL: ID 
	{
		printf("test");
		$$=createlocalsymbolnode($<name>1,INVALIDTYPE,1,1,0);
	}
	| ID '[' NUM ']' 
	{
		$$=createlocalsymbolnode($<name>1,INVALIDTYPE,$<number>3,$<number>3,0);
	}
	| ID '[' NUM ']' '[' NUM ']'	
	{
		$$ = createlocalsymbolnode($<name>1,INVALIDTYPE,($<number>3*$<number>6),$<number>3,0);
	}
	| MUL ID 
	{
		$$=createlocalsymbolnode($<name>2,INVALIDTYPE,1,0,0);
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


//please do not change --------------------------------------------------------------

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
	| FNCALLSTMNT ENDOFLINE	
	{
		$$ = $1;
	}
	| RETURNSTMNT	
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
RETURNSTMNT: RETURN expr ENDOFLINE	
	{
		$$ = createTree(-1,INVALIDTYPE,NULL,RETNODE,$2,NULL);
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
	 | FNCALLSTMNT 	 {$$ = $1;}
	 ;


ARGMNTLIST : ARGMNTLIST ',' expr
	{
		check();
		$$=joinargnode($1,$3);
	}
	| expr
	{
		$$ = createargnode($1);
	}
	;

FNCALLSTMNT : ID '(' ARGMNTLIST ')'
{
	struct tnode *temp = createTree(-1,INVALIDTYPE,$<name>1,FNNODE,$3,NULL);
	temp->paramlist=lookup(gst,temp->varname)->paramlist;
	temp->arglist=$3;
	check();
	if(checkargissameasparam(temp)==0)
	{
		yyerror("Arguments do not match with parameters");
		exit(1);
	}
	$$=temp;
}
;
IDENTIFIER: ID 
	{
		struct tnode* temp =createTree(-1,INVALIDTYPE,$<name>1,VARNODE,NULL,NULL);
		//temp->type=findtype(gst,temp->varname);
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
;
%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}


int main(int argc, char* argv[]) 
{
	if(argc > 1)
 	{
  		FILE *target_file = fopen(argv[1], "r");
  		if(target_file)
   			yyin = target_file;
 	}
	yyparse();
	return 0;
}