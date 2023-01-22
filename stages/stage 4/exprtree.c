int yyerror();
struct tnode* createTree(int val, int type, char* varname, int nodetype, struct tnode* l, struct tnode* r) {
	struct tnode* temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->nodetype = nodetype;
	temp->left = l;
	temp->right = r;
	temp->type=type;
	switch(temp->nodetype) 
	{
		case IFNODE:
		{
			if(temp->left->type!=BOOLTYPE)
			{
				yyerror("NO INT TYPE INSIDE IF CONDITION: TYPE ERROR\n");
				exit(1);
			}
			break;
		}
		case IFELSENODE:
		{
			if(temp->left->type!=BOOLTYPE)
			{
				yyerror("NO INT TYPE INSIDE IF CONDITION: TYPE ERROR\n");
				exit(1);
			}
			break;
		}
		case WHILENODE:
		{
			if(temp->left->type!=BOOLTYPE)
			{
				yyerror("NO INT TYPE INSIDE WHILE CONDITION: TYPE ERROR\n");
				exit(1);
			}
			break;
		}
		case LOGICOPNODE:
		{
			temp->varname = malloc(1);
			temp->varname[0] = varname[0];
			break;
		}
		case VARNODE:
		{
			temp->varname = malloc(1);
			temp->varname[0] = varname[0];
			break;
		}
		case NUMNODE:
		{
			temp->val = val;
			break;
		}
		case MATHOPNODE:
		{
			if(temp->left->type!=temp->right->type && temp->left->type!=INTTYPE)
			{
				if(temp->left->type==BOOLTYPE)
				{
					yyerror("NO BOOLEAN IN MATH OPERATIONS : TYPE ERROR\n");
					exit(1);
				}
			}
			temp->varname = malloc(1);
			temp->varname[0] = varname[0];
			break;
		}
		case DOWHILENODE:
		{
			if(temp->left->type!=BOOLTYPE)
			{
				yyerror("NO INT TYPE INSIDE DO WHILE CONDITION: TYPE ERROR\n");
				exit(1);
			}
			break;
		}
		case REPEATUNTILNODE:
		{
			if(temp->left->type!=BOOLTYPE)
			{
				yyerror("NO INT TYPE INSIDE REPEAT UNTIL CONDITION: TYPE ERROR\n");
				exit(1);
			}
			break;
		}

	}
	return temp;
}
void preorder(struct tnode* tnode) {
	if(tnode==NULL)
	{
		;
	}
	else
	{
		printf("%d ",tnode->nodetype);
		preorder(tnode->left);
		preorder(tnode->right);
	}
}
void inorder(struct tnode* tnode) {
	if(tnode==NULL)
	{
		;
	}
	else
	{
		inorder(tnode->left);
		printf("%s ",tnode->varname);
		printf("%d ",tnode->nodetype);
		inorder(tnode->right);
	}
}
register_index getReg(){
    int flag=0;
    for(int i = 0; i < 16; i++){
        if(regs[i] == 0){
            flag=1;
        }
    }
    if (flag==0){
        printf("Out of registers");
        exit(1);
    }
    for(int i = 0; i < 16; i++){
        if(regs[i] == 0){
            regs[i] = 1;
            return i;
        }
    }
	nooffreereg++;
}
register_index freeReg(){
    for(int i = 15; i >= 0; i--){
        if(regs[i] == 1){
            regs[i] = 0;
            return i;
        }
    }
	nooffreereg--;
}
int getLabel(){
	return label++;
}
register_index codeGen(struct tnode *t,FILE *target_file){
    int reg1=0,reg2=0,reg3=0;
	if(t==NULL)
	{
		;
	}
	else if(t->nodetype==LOGICOPNODE)
	{
		reg1=codeGen(t->left,target_file);
		reg2=codeGen(t->right,target_file);
		reg3=getReg();
		if(t->varname=='||')
		{
			fprintf(target_file,"OR R%d, R%d\n",reg1,reg2);
			fprintf(target_file,"MOV R%d, \n",reg3);
			fprintf(target_file,"EQ R%d, R%d\n",reg3,reg1);
		}
		else if(t->varname=='&&')
		{
			fprintf(target_file,"AND R%d, R%d\n",reg1,reg2);
			fprintf(target_file,"MOV R%d, 1\n",reg3);
			fprintf(target_file,"EQ R%d, R%d\n",reg3,reg1);
		}
		else if(t->varname=='!')
		{
			fprintf(target_file,"MOV R%d, 1\n",reg3);
			fprintf(target_file,"EQ R%d, R%d\n",reg3,reg1);
		}
		else if(t->varname='<')
		{
			fprintf(target_file,"LT R%d, R%d\n",reg1,reg2);
			fprintf(target_file,"MOV R%d, 1\n",reg3);
			fprintf(target_file,"EQ R%d, R%d\n",reg3,reg1);
		}
		else if(t->varname=='>')
		{
			fprintf(target_file,"GT R%d, R%d\n",reg1,reg2);
			fprintf(target_file,"MOV R%d, 1\n",reg3);
			fprintf(target_file,"EQ R%d, R%d\n",reg3,reg1);
		}
		else if(t->varname=='==')
		{
			fprintf(target_file,"EQ R%d, R%d\n",reg1,reg2);
			fprintf(target_file,"MOV R%d, 1\n",reg3);
			fprintf(target_file,"EQ R%d, R%d\n",reg3,reg1);
		}
		else if(t->varname=='!=')
		{
			fprintf(target_file,"NE R%d, R%d\n",reg1,reg2);
			fprintf(target_file,"MOV R%d, 1\n",reg3);
			fprintf(target_file,"EQ R%d, R%d\n",reg3,reg1);
		}
		freeReg();
		freeReg();
		return reg3;
	}

    else if(t->nodetype == ASSIGNNODE){
        reg1 = getReg();
		reg2=codeGen(t->right,target_file);
		int variableposition = (int)(t->left->varname[0] - 'a') + 4096;
		fprintf(target_file, "MOV R%d, %d\n", reg1, variableposition);
        fprintf(target_file,"MOV [R%d], R%d\n",reg1,reg2);
		freeReg();
		freeReg();
        return -1;
    }
	else if(t->nodetype==NUMNODE)
	{
		reg1=getReg();
		fprintf(target_file,"MOV R%d, %d\n",reg1,t->val);
		return reg1;
	}
	else if(t->nodetype==VARNODE)
	{
		reg1=getReg();
		int variableposition = (int)(t->varname[0]-'a') + 4096;
		fprintf(target_file,"MOV R%d, %d\n",reg1,variableposition);
		fprintf(target_file,"MOV R%d, [R%d]\n",reg1,reg1);
		return reg1;
	}
	else if(t->nodetype==READNODE)
	{
		reg1=getReg();
		int variableposition = (int)(t->varname[0]-'a') + 4096;
		fprintf(target_file, "MOV R%d, \"Read\"\n", reg1);
		fprintf(target_file, "PUSH R%d\n", reg1); //system call fn
		fprintf(target_file, "MOV R%d, -1\n", reg1);
		fprintf(target_file, "PUSH R%d\n", reg1); //arg1
		fprintf(target_file, "MOV R%d, %d\n", reg1, variableposition);
		fprintf(target_file, "PUSH R%d\n", reg1); //arg2
		fprintf(target_file, "PUSH R%d\n", reg1); //arg3
		fprintf(target_file, "PUSH R%d\n", reg1); 
		fprintf(target_file, "CALL 0\n");
		fprintf(target_file, "POP R%d\n", reg1);
		fprintf(target_file, "POP R%d\n", reg1);
		fprintf(target_file, "POP R%d\n", reg1);
		fprintf(target_file, "POP R%d\n", reg1);
		fprintf(target_file, "POP R%d\n", reg1);
		freeReg();
		return -1;
	}
	else if (t->nodetype==WRITENODE)
	{
		reg1=getReg();
		reg2=codeGen(t->left,target_file);
		fprintf(target_file, "MOV R%d, \"Write\"\n", reg1);
		fprintf(target_file, "PUSH R%d\n", reg1); //system call fn
		fprintf(target_file, "MOV R%d, -2\n", reg1);
		fprintf(target_file, "PUSH R%d\n", reg1); //arg1
		fprintf(target_file, "MOV R%d, R%d\n", reg1, reg2);
		fprintf(target_file, "PUSH R%d\n", reg1); //arg2
		fprintf(target_file, "PUSH R%d\n", reg1); //arg3
		fprintf(target_file, "PUSH R%d\n", reg1); //ret pos
		fprintf(target_file, "CALL 0\n");
		fprintf(target_file, "POP R%d\n", reg1);
		fprintf(target_file, "POP R%d\n", reg1);
		fprintf(target_file, "POP R%d\n", reg1);
		fprintf(target_file, "POP R%d\n", reg1);
		fprintf(target_file, "POP R%d\n", reg1);
		freeReg();
		freeReg();
		return -1;
	}
	else if (t->nodetype==CONNECTORNODE)
	{
		int temp_reg;
		temp_reg=codeGen(t->left,target_file);
		temp_reg=codeGen(t->right,target_file);
		return -1;
	}
    else if(t->nodetype== MATHOPNODE)
	{
        reg1 = codeGen(t->left,target_file);
        reg2 = codeGen(t->right,target_file);
        switch(t->varname[0])
		{
            case '+' :{ fprintf(target_file,"ADD R%d, R%d\n",reg1,reg2);freeReg();
                       break;}
            case '-' : { fprintf(target_file,"SUB R%d, R%d\n",reg1,reg2);freeReg();
                       break;}
            case '*' : { fprintf(target_file,"MUL R%d, R%d\n",reg1,reg2);freeReg();
                       break;}
            case '/' : { fprintf(target_file,"DIV R%d, R%d\n",reg1,reg2);freeReg();
                       break;}
        }
		
        return reg1;
    }
	else if(t->nodetype== BREAKNODE)
	{
		fprintf(target_file,"JMP L%d\n",label);
		return -1;
	}
	else if(t->nodetype==CONTINUENODE)
	{
		fprintf(target_file,"JMP L%d\n",label1);
		return -1;
	}
	else if(t->nodetype==WHILENODE)
	{
		label++;
		label1++;
		fprintf(target_file,"L%d:\n",label);
		reg1=codeGen(t->left,target_file);
		fprintf(target_file,"JZ R%d, L%d\n",reg1,label+1);
		freeReg();
		codeGen(t->right,target_file);
		fprintf(target_file,"JMP L%d\n",label);
		fprintf(target_file,"L%d:\n",label+1);
		label++;
		label1++;
		return -1;
	}
	else if(t->nodetype==IFNODE)
	{
		label++;
		reg1=codeGen(t->left,target_file);
		fprintf(target_file,"JZ R%d, L%d\n",reg1,label);
		freeReg();
		codeGen(t->right,target_file);
		fprintf(target_file,"L%d:\n",label);
		label++;
		return -1;
	}
	else if(t->nodetype==IFELSENODE)
	{
		label++;
		reg1=codeGen(t->left,target_file);
		fprintf(target_file,"JZ R%d, L%d\n",reg1,label);
		freeReg();
		codeGen(t->right->left,target_file);
		fprintf(target_file,"JMP L%d\n",label+1);
		fprintf(target_file,"L%d:\n",label);
		codeGen(t->right->right,target_file);
		fprintf(target_file,"L%d:\n",label+1);
		label++;
		label++;
		return -1;
	}
	else if(t->nodetype==DOWHILENODE)
	{
		label++;
		label1++;
		fprintf(target_file,"L%d:\n",label);
		codeGen(t->left,target_file);
		reg1=codeGen(t->right,target_file);
		fprintf(target_file,"JNZ R%d, L%d\n",reg1,label);
		freeReg();
		fprintf(target_file,"L%d:\n",label+1);
		label++;
		label1++;
		return -1;
	}
}

