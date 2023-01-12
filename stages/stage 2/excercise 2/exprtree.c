struct tnode* createTree(int val, char* varname, int nodetype, struct tnode* l, struct tnode* r) {
	struct tnode* temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->nodetype = nodetype;
	temp->left = l;
	temp->right = r;
	switch(temp->nodetype) 
	{
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
			temp->varname = malloc(1);
			temp->varname[0] = varname[0];
			break;
		}
	}
	return temp;
}
void inorder(struct tnode* ast)
{
	if(ast==NULL)
	{
		return;
	}
	inorder(ast->left);
	switch(ast->nodetype)
	{
		case NUMNODE:
		{
			printf("%d ",ast->val);
			break;
		}
		case VARNODE:
		{
			printf("%c ",ast->varname[0]);
			break;
		}
		case MATHOPNODE:
		{
			printf("%c ",ast->varname[0]);
			break;
		}
		case CONNECTORNODE:
		{
			printf("O");
			break;
		}
		case READNODE:
		{
			printf("R");
			break;
		}
		case WRITENODE:
		{
			printf("W");
			break;
		}
		case ASSIGNNODE:
		{
			printf("=");
			break;
		}
	}
	inorder(ast->right);
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
register_index codeGen(struct tnode *t,FILE *target_file){
    int reg1=0,reg2=0,reg3=0;
	if(t==NULL)
	{
		;
	}
    else if(t->nodetype == ASSIGNNODE){
        reg1 = getReg();
		reg2=codeGen(t->right,target_file);
		int variableposition = (int)(t->left->varname[0] - 'a') + 4096;
		fprintf(target_file, "MOV R%d, %d\n", reg1, variableposition);
        fprintf(target_file,"MOV [R%d], %d\n",reg1,reg2);
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
}

