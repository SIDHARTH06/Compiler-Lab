#include<string.h>
int yyerror();
// symbol table functions
void printtree(struct tnode *t)
{
	if (t == NULL)
		return;
	printf("%d ", t->nodetype);
	if (t->varname != NULL && t->nodetype != STRNODE)
		printf("%s ", t->varname);
	printtree(t->left);
	printtree(t->right);
}
// create declaration tree
struct tnode *createTree(int val, int type, char *varname, int nodetype, struct tnode *l, struct tnode *r)
{
	struct tnode *temp;
	temp = (struct tnode *)malloc(sizeof(struct tnode));
	temp->nodetype = nodetype;
	temp->left = l;
	temp->right = r;
	switch (temp->nodetype)
	{
	case ASSIGNNODE:
	{
		if (!((temp->left->nodetype == PTRNODE && temp->right->nodetype == ADDRNODE) || (temp->left->nodetype == VARNODE && temp->right->nodetype == ADDRNODE)))
		{
			if (temp->left->type != temp->right->type)
			{
				yyerror("TYPE MISMATCH IN ASSIGNMENT");
				exit(1);
			}
		}
		break;
	}
	case IFNODE:
	{
		if (temp->left->type != BOOLTYPE)
		{
			yyerror("NO INT TYPE INSIDE IF CONDITION: TYPE ERROR");
			exit(1);
		}
		break;
	}
	case WHILENODE:
	{
		if (temp->left->type != BOOLTYPE)
		{
			yyerror("NO INT TYPE INSIDE WHILE CONDITION: TYPE ERROR");
			exit(1);
		}
		break;
	}
	case IFELSENODE:
	{
		if (temp->left->type != BOOLTYPE)
		{
			yyerror("NO INT TYPE INSIDE IF CONDITION: TYPE ERROR");
			exit(1);
		}
		break;
	}
	case REPEATUNTILNODE:
	{
		if (temp->right->type != BOOLTYPE)
		{
			yyerror("NO INT TYPE INSIDE WHILE CONDITION: TYPE ERROR");
			exit(1);
		}
		break;
	}
	case DOWHILENODE:
	{
		if (temp->right->type != BOOLTYPE)
		{
			yyerror("NO INT TYPE INSIDE WHILE CONDITION: TYPE ERROR");
			exit(1);
		}
		break;
	}
	case NUMNODE:
	{
		temp->val = val;
		temp->type = INTTYPE;
		break;
	}
	case VARNODE:
	{
		temp->varname = malloc(sizeof(char) * 256);
		strcpy(temp->varname, varname);
		break;
	}
	case MATHOPNODE:
	{
		temp->varname = malloc(1);
		temp->varname[0] = varname[0];
		if (temp->left->type != INTTYPE || temp->right->type != INTTYPE)
		{
			yyerror("TYPE MISMATCH IN MATH OPERATION");
			exit(1);
		}
		temp->type = INTTYPE;
		break;
	}
	case STRNODE:
	{
		temp->varname = malloc(sizeof(char) * 256);
		strcpy(temp->varname, varname);
		temp->type = STRTYPE;
		break;
	}
	case PTRNODE:
	{
		temp->type = PTRTYPE;
		break;
	}
	case ADDRNODE:
	{
		temp->type = ADDRTYPE;
		break;
	}
	case FNNODE:
	{
		temp->type = temp->left->type;
		temp->varname = malloc(sizeof(char) * 256);
		strcpy(temp->varname, varname);
		break;
	}
	}
	return temp;
}
void preorder(struct tnode *tnode)
{
	if (tnode == NULL)
	{
		;
	}
	else
	{
		printf("%d ", tnode->nodetype);
		preorder(tnode->left);
		preorder(tnode->right);
	}
}
void inorder(struct tnode *tnode)
{
	if (tnode == NULL)
	{
		;
	}
	else
	{
		inorder(tnode->left);
		printf("%s ", tnode->varname);
		printf("%d ", tnode->nodetype);
		inorder(tnode->right);
	}
}
register_index getReg()
{
	int flag = 0;
	for (int i = 0; i < 16; i++)
	{
		if (regs[i] == 0)
		{
			flag = 1;
		}
	}
	if (flag == 0)
	{
		printf("Out of registers");
		exit(1);
	}
	for (int i = 0; i < 16; i++)
	{
		if (regs[i] == 0)
		{
			regs[i] = 1;
			return i;
		}
	}
	nooffreereg++;
}
register_index freereg()
{
	for (int i = 15; i >= 0; i--)
	{
		if (regs[i] == 1)
		{
			regs[i] = 0;
			return i;
		}
	}
	nooffreereg--;
}
int getLabel()
{
	return label++;
}
register_index codeGen(struct tnode *t, FILE *target_file,struct lSymbolTable *lst)
{
	int reg1, reg2, reg3, variableposition;
	if (t == NULL)
	{
		;
	}
	else if (t->nodetype == LOGICOPNODE)
	{
		reg1 = codeGen(t->left, target_file,lst);
		reg2 = codeGen(t->right, target_file,lst);
		reg3 = getReg();
		if (t->varname == '||')
		{
			fprintf(target_file, "OR R%d, R%d\n", reg1, reg2);
			fprintf(target_file, "MOV R%d, \n", reg3);
			fprintf(target_file, "EQ R%d, R%d\n", reg3, reg1);
		}
		else if (t->varname == '&&')
		{
			fprintf(target_file, "AND R%d, R%d\n", reg1, reg2);
			fprintf(target_file, "MOV R%d, 1\n", reg3);
			fprintf(target_file, "EQ R%d, R%d\n", reg3, reg1);
		}
		else if (t->varname == '!')
		{
			fprintf(target_file, "MOV R%d, 1\n", reg3);
			fprintf(target_file, "EQ R%d, R%d\n", reg3, reg1);
		}
		else if (t->varname = '<')
		{
			fprintf(target_file, "LT R%d, R%d\n", reg1, reg2);
			fprintf(target_file, "MOV R%d, 1\n", reg3);
			fprintf(target_file, "EQ R%d, R%d\n", reg3, reg1);
		}
		else if (t->varname == '>')
		{
			fprintf(target_file, "GT R%d, R%d\n", reg1, reg2);
			fprintf(target_file, "MOV R%d, 1\n", reg3);
			fprintf(target_file, "EQ R%d, R%d\n", reg3, reg1);
		}
		else if (t->varname == '==')
		{
			fprintf(target_file, "EQ R%d, R%d\n", reg1, reg2);
			fprintf(target_file, "MOV R%d, 1\n", reg3);
			fprintf(target_file, "EQ R%d, R%d\n", reg3, reg1);
		}
		else if (t->varname == '!=')
		{
			fprintf(target_file, "NE R%d, R%d\n", reg1, reg2);
			fprintf(target_file, "MOV R%d, 1\n", reg3);
			fprintf(target_file, "EQ R%d, R%d\n", reg3, reg1);
		}
		freereg();
		freereg();
		return reg3;
	}

	else if (t->nodetype == ASSIGNNODE)
	{
		if (t->left->nodetype == PTRNODE)
		{
			reg2 = codeGen(t->left->left, target_file,lst);
			reg3 = codeGen(t->right, target_file,lst);
			fprintf(target_file, "MOV [R%d], R%d\n", reg2, reg3);
			freereg();
			freereg();
			return -1;
		}
		reg1 = getReg();
		variableposition = getbindingaddress(t->left,lst,gst);
		if (t->left->left != NULL && t->left->right == NULL)
		{
			reg2 = codeGen(t->left->left, target_file,lst);
			if (variableposition >= 4096)
			{
				fprintf(target_file, "MOV R%d, %d\n", reg1, variableposition);
				fprintf(target_file, "ADD R%d, R%d\n", reg1, reg2);
			}
			else if (variableposition < 0)
			{
				fprintf(target_file, "MOV R%d, BP\n", reg1);
				fprintf(target_file, "ADD R%d, %d\n", reg1, variableposition - 2);
				fprintf(target_file, "ADD R%d, R%d\n", reg1, reg2);
			}
			else
			{
				fprintf(target_file, "MOV R%d, BP\n", reg1);
				fprintf(target_file, "ADD R%d, %d\n", reg1, variableposition);
				fprintf(target_file, "ADD R%d, R%d\n", reg1, reg2);
			}
		}
		else if (variableposition >= 4096)
		{
			fprintf(target_file, "MOV R%d, %d\n", reg1, variableposition);
		}
		else if (variableposition < 0)
		{
			fprintf(target_file, "MOV R%d, BP\n", reg1);
			fprintf(target_file, "ADD R%d, %d\n", reg1, variableposition - 2);
		}
		else
		{
			fprintf(target_file, "MOV R%d, BP\n", reg1);
			fprintf(target_file, "ADD R%d, %d\n", reg1, variableposition);
		}
		reg2 = codeGen(t->right, target_file,lst);
		fprintf(target_file, "MOV [R%d], R%d\n", reg1, reg2);
		freereg();
		freereg();
		return -1;
	}
	else if (t->nodetype == NUMNODE)
	{
		reg1 = getReg();
		fprintf(target_file, "MOV R%d, %d\n", reg1, t->val);
		return reg1;
	}
	else if (t->nodetype == VARNODE)
	{
		reg1 = getReg();
		variableposition = getbindingaddress(t,lst,gst);

		if (t->left != NULL && t->right == NULL)
		{
			reg2 = codeGen(t->left, target_file,lst);
			if (variableposition >= 4096)
			{
				fprintf(target_file, "MOV R%d, %d\n", reg1, variableposition);
				fprintf(target_file, "ADD R%d, R%d\n", reg1, reg2);
				fprintf(target_file, "MOV R%d, [R%d]\n", reg1, reg1);
			}
			else if (variableposition < 0)
			{
				fprintf(target_file, "MOV R%d, BP\n", reg1);
				fprintf(target_file, "ADD R%d, %d\n", reg1, variableposition - 2);
				fprintf(target_file, "ADD R%d, R%d\n", reg1, reg2);
				fprintf(target_file, "MOV R%d, [R%d]\n", reg1, reg1);
			}
			else
			{
				fprintf(target_file, "MOV R%d, BP\n", reg1);
				fprintf(target_file, "ADD R%d, %d\n", reg1, variableposition);
				fprintf(target_file, "ADD R%d, R%d\n", reg1, reg2);
				fprintf(target_file, "MOV R%d, [R%d]\n", reg1, reg1);
			}
			freereg();
		}
		else if (variableposition >= 4096)
		{
			fprintf(target_file, "MOV R%d, %d\n", reg1, variableposition);
			fprintf(target_file, "MOV R%d, [R%d]\n", reg1, reg1);
		}
		else if (variableposition < 0)
		{
			fprintf(target_file, "MOV R%d, BP\n", reg1);
			fprintf(target_file, "ADD R%d, %d\n", reg1, variableposition - 2);
			fprintf(target_file, "MOV R%d, [R%d]\n", reg1, reg1);
		}
		else
		{
			fprintf(target_file, "MOV R%d, BP\n", reg1);
			fprintf(target_file, "ADD R%d, %d\n", reg1, variableposition);
			fprintf(target_file, "MOV R%d, [R%d]\n", reg1, reg1);
		}

		return reg1;
	}
	else if (t->nodetype == STRNODE)
	{
		reg1 = getReg();
		fprintf(target_file, "MOV R%d, %s\n", reg1, t->varname);
		return reg1;
	}
	else if (t->nodetype == READNODE)
	{
		for (int i = 0; i <= 16 - nooffreereg; i++)
		{
			fprintf(target_file, "PUSH R%d\n", i);
		}
		reg3 = getReg();
		reg1 = getReg();
		variableposition = getbindingaddress(t->left,lst,gst);
		if (t->left->left != NULL && t->left->right == NULL)
		{
			reg2 = codeGen(t->left->left, target_file,lst);
			if (variableposition >= 4096)
			{
				fprintf(target_file, "MOV R%d, %d\n", reg1, variableposition);
				fprintf(target_file, "ADD R%d, R%d\n", reg1, reg2);
			}
			else if (variableposition < 0)
			{
				fprintf(target_file, "MOV R%d, BP\n", reg1);
				fprintf(target_file, "ADD R%d, %d\n", reg1, variableposition - 2);
				fprintf(target_file, "ADD R%d, R%d\n", reg1, reg2);
			}
			else
			{
				fprintf(target_file, "MOV R%d, BP\n", reg1);
				fprintf(target_file, "ADD R%d, %d\n", reg1, variableposition);
				fprintf(target_file, "ADD R%d, R%d\n", reg1, reg2);
			}
			freereg();
		}
		else if (variableposition >= 4096)
		{
			fprintf(target_file, "MOV R%d, %d\n", reg1, variableposition);
		}
		else if (variableposition < 0)
		{
			fprintf(target_file, "MOV R%d, BP\n", reg1);
			fprintf(target_file, "ADD R%d, %d\n", reg1, variableposition - 2);
		}
		else
		{
			fprintf(target_file, "MOV R%d, BP\n", reg1);
			fprintf(target_file, "ADD R%d, %d\n", reg1, variableposition);
		}
		check();
		fprintf(target_file, "MOV R%d, \"Read\"\n", reg3);
		fprintf(target_file, "PUSH R%d\n", reg3); // system call fn
		fprintf(target_file, "MOV R%d, -1\n", reg3);
		fprintf(target_file, "PUSH R%d\n", reg3); // arg1
		fprintf(target_file, "MOV R%d, R%d\n", reg3, reg1);
		fprintf(target_file, "PUSH R%d\n", reg3); // arg2
		fprintf(target_file, "PUSH R%d\n", reg3); // arg3
		fprintf(target_file, "PUSH R%d\n", reg3);
		fprintf(target_file, "CALL 0\n");
		fprintf(target_file, "POP R%d\n", reg3);
		fprintf(target_file, "POP R%d\n", reg3);
		fprintf(target_file, "POP R%d\n", reg3);
		fprintf(target_file, "POP R%d\n", reg3);
		fprintf(target_file, "POP R%d\n", reg3);
		freereg();
		freereg();
		for (int i = (16 - nooffreereg); i >= 0; i--)
		{
			fprintf(target_file, "POP R%d\n", i);
		}
		return -1;
	}
	else if (t->nodetype == WRITENODE)
	{
		for (int i = 0; i <= (16 - nooffreereg); i++)
		{
			fprintf(target_file, "PUSH R%d\n", i);
		}
		if (t->left->nodetype == NUMNODE)
		{
			reg1 = getReg();
			reg2 = getReg();
			fprintf(target_file, "MOV R%d, %d\n", reg2, t->left->val);
			fprintf(target_file, "MOV R%d, \"Write\"\n", reg1);
			fprintf(target_file, "PUSH R%d\n", reg1);
			fprintf(target_file, "MOV R%d, -2\n", reg1);
			fprintf(target_file, "PUSH R%d\n", reg1);
			fprintf(target_file, "MOV R%d, R%d\n", reg1, reg2);
			fprintf(target_file, "PUSH R%d\n", reg1);
			fprintf(target_file, "PUSH R%d\n", reg1);
			fprintf(target_file, "PUSH R%d\n", reg1);
			fprintf(target_file, "CALL 0\n");
			fprintf(target_file, "POP R%d\n", reg1);
			fprintf(target_file, "POP R%d\n", reg1);
			fprintf(target_file, "POP R%d\n", reg1);
			fprintf(target_file, "POP R%d\n", reg1);
			fprintf(target_file, "POP R%d\n", reg1);
			freereg();
		}
		else if (t->left->nodetype == VARNODE)
		{
			reg3 = getReg();
			reg1 = getReg();
			variableposition = getbindingaddress(t->left,lst,gst);
			if (t->left->left != NULL && t->left->right == NULL)
			{
				reg2 = codeGen(t->left->left, target_file,lst);
				if (variableposition >= 4096)
				{
					fprintf(target_file, "MOV R%d, %d\n", reg1, variableposition);
					fprintf(target_file, "ADD R%d, R%d\n", reg1, reg2);
				}
				else if (variableposition < 0)
				{
					fprintf(target_file, "MOV R%d, BP\n", reg1);
					fprintf(target_file, "ADD R%d, %d\n", reg1, variableposition - 2);
					fprintf(target_file, "ADD R%d, R%d\n", reg1, reg2);
				}
				else
				{
					fprintf(target_file, "MOV R%d, BP\n", reg1);
					fprintf(target_file, "ADD R%d, %d\n", reg1, variableposition);
					fprintf(target_file, "ADD R%d, R%d\n", reg1, reg2);
				}
				freereg();
			}
			else if (variableposition >= 4096)
			{
				fprintf(target_file, "MOV R%d, %d\n", reg1, variableposition);
			}
			else if (variableposition < 0)
			{
				fprintf(target_file, "MOV R%d, BP\n", reg1);
				fprintf(target_file, "ADD R%d, %d\n", reg1, variableposition - 2);
			}
			else
			{
				fprintf(target_file, "MOV R%d, BP\n", reg1);
				fprintf(target_file, "ADD R%d, %d\n", reg1, variableposition);
			}

			fprintf(target_file, "MOV R%d, [R%d]\n", reg1, reg1);
			fprintf(target_file, "MOV R%d, %d\n", reg1, t->left->val);
			fprintf(target_file, "MOV R%d, \"Write\"\n", reg3);
			fprintf(target_file, "PUSH R%d\n", reg3);
			fprintf(target_file, "MOV R%d, -2\n", reg3);
			fprintf(target_file, "PUSH R%d\n", reg3);
			fprintf(target_file, "MOV R%d, R%d\n", reg3, reg1);
			fprintf(target_file, "PUSH R%d\n", reg3);
			fprintf(target_file, "PUSH R%d\n", reg3);
			fprintf(target_file, "PUSH R%d\n", reg3);
			fprintf(target_file, "CALL 0\n");
			fprintf(target_file, "POP R%d\n", reg3);
			fprintf(target_file, "POP R%d\n", reg3);
			fprintf(target_file, "POP R%d\n", reg3);
			fprintf(target_file, "POP R%d\n", reg3);
			fprintf(target_file, "POP R%d\n", reg3);
			freereg();
		}
		else
		{
			reg1 = getReg();
			reg2 = codeGen(t->left, target_file,lst);
			fprintf(target_file, "MOV R%d, %d\n", reg2, t->left->val);
			fprintf(target_file, "MOV R%d, \"Write\"\n", reg1);
			fprintf(target_file, "PUSH R%d\n", reg1);
			fprintf(target_file, "MOV R%d, -2\n", reg1);
			fprintf(target_file, "PUSH R%d\n", reg1);
			fprintf(target_file, "MOV R%d, R%d\n", reg1, reg2);
			fprintf(target_file, "PUSH R%d\n", reg1);
			fprintf(target_file, "PUSH R%d\n", reg1);
			fprintf(target_file, "PUSH R%d\n", reg1);
			fprintf(target_file, "CALL 0\n");
			fprintf(target_file, "POP R%d\n", reg1);
			fprintf(target_file, "POP R%d\n", reg1);
			fprintf(target_file, "POP R%d\n", reg1);
			fprintf(target_file, "POP R%d\n", reg1);
			fprintf(target_file, "POP R%d\n", reg1);
			freereg();
		}
		freereg();
		for (int i = (16 - nooffreereg); i >= 0; i--)
		{
			fprintf(target_file, "POP R%d\n", i);
		}
		return -1;
	}
	else if (t->nodetype == CONNECTORNODE)
	{
		int temp_reg;
		temp_reg = codeGen(t->left, target_file,lst);
		temp_reg = codeGen(t->right, target_file,lst);
		return -1;
	}
	else if (t->nodetype == MATHOPNODE)
	{
		reg1 = codeGen(t->left, target_file,lst);
		reg2 = codeGen(t->right, target_file,lst);
		switch (t->varname[0])
		{
		case '+':
		{
			fprintf(target_file, "ADD R%d, R%d\n", reg1, reg2);
			freereg();
			break;
		}
		case '-':
		{
			fprintf(target_file, "SUB R%d, R%d\n", reg1, reg2);
			freereg();
			break;
		}
		case '*':
		{
			fprintf(target_file, "MUL R%d, R%d\n", reg1, reg2);
			freereg();
			break;
		}
		case '/':
		{
			fprintf(target_file, "DIV R%d, R%d\n", reg1, reg2);
			freereg();
			break;
		}
		case 'M':
		{
			fprintf(target_file, "MOD R%d, R%d\n", reg1, reg2);
			freereg();
			break;
		}
		}
		return reg1;
	}
	else if (t->nodetype == BREAKNODE)
	{
		fprintf(target_file, "JMP L%d\n", label);
		return -1;
	}
	else if (t->nodetype == CONTINUENODE)
	{
		fprintf(target_file, "JMP L%d\n", label1);
		return -1;
	}
	else if (t->nodetype == WHILENODE)
	{
		label++;
		label1++;
		fprintf(target_file, "L%d:\n", label);
		reg1 = codeGen(t->left, target_file,lst);
		fprintf(target_file, "JZ R%d, L%d\n", reg1, label + 1);
		freereg();
		codeGen(t->right, target_file,lst);
		fprintf(target_file, "JMP L%d\n", label);
		fprintf(target_file, "L%d:\n", label + 1);
		label++;
		label1++;
		return -1;
	}
	else if (t->nodetype == IFNODE)
	{
		label++;
		reg1 = codeGen(t->left, target_file,lst);
		fprintf(target_file, "JZ R%d, L%d\n", reg1, label);
		freereg();
		codeGen(t->right, target_file,lst);
		fprintf(target_file, "L%d:\n", label);
		label++;
		return -1;
	}
	else if (t->nodetype == IFELSENODE)
	{
		label++;
		reg1 = codeGen(t->left, target_file,lst);
		fprintf(target_file, "JZ R%d, L%d\n", reg1, label);
		freereg();
		codeGen(t->right->left, target_file,lst);
		fprintf(target_file, "JMP L%d\n", label + 1);
		fprintf(target_file, "L%d:\n", label);
		codeGen(t->right->right, target_file,lst);
		fprintf(target_file, "L%d:\n", label + 1);
		label++;
		label++;
		return -1;
	}
	else if (t->nodetype == DOWHILENODE)
	{
		label++;
		label1++;
		fprintf(target_file, "L%d:\n", label);
		codeGen(t->left, target_file,lst);
		reg1 = codeGen(t->right, target_file,lst);
		fprintf(target_file, "JNZ R%d, L%d\n", reg1, label);
		freereg();
		fprintf(target_file, "L%d:\n", label + 1);
		label++;
		label1++;
		return -1;
	}
	else if (t->nodetype == STRNODE)
	{
		fprintf(target_file, "MOV R%d, \"%s\"\n", reg1, t->varname);
		return reg1;
	}
	else if (t->nodetype == PTRNODE)
	{
		reg1 = getReg();
		reg2 = codeGen(t->left, target_file,lst);
		fprintf(target_file, "MOV R%d, [R%d]\n", reg1, reg2);
		freereg();
		return reg1;
	}
	else if (t->nodetype == ADDRNODE)
	{
		reg1 = getReg();
		variableposition = getbindingaddress(t,lst,gst);
		fprintf(target_file, "MOV R%d, %d\n", reg1, variableposition);
		if (t->left->left != NULL && t->left->right == NULL)
		{
			reg2 = codeGen(t->left->left, target_file,lst);
			fprintf(target_file, "ADD R%d, R%d\n", reg1, reg2);
			freereg();
		}
		else if (t->left->left != NULL && t->left->right != NULL)
		{
			reg2 = codeGen(t->left->left, target_file,lst);
			fprintf(target_file, "MUL R%d, %d\n", reg2, t->left->Gentry->length);
			fprintf(target_file, "ADD R%d, R%d\n", reg1, reg2);
			freereg();
			reg2 = codeGen(t->left->right, target_file,lst);
			fprintf(target_file, "ADD R%d, R%d\n", reg1, reg2);
			freereg();
		}
		return reg1;
	}
	else if (t->nodetype == RETNODE)
	{
		reg1 = codeGen(t->left, target_file,lst);
		reg2 = getReg();
		fprintf(target_file, "MOV R%d, BP\n", reg2);
		fprintf(target_file, "SUB R%d, 2\n", reg2);
		fprintf(target_file, "MOV [R%d], R%d\n", reg2, reg1);
		freereg();
		freereg();
		return -1;
	}
	else if (t->nodetype == FNNODE)
	{
		for (int i = 0; i <= (16 - nooffreereg); i++)
		{
			fprintf(target_file, "PUSH R%d\n", i);
		}
		struct argstruct *temp = t->arghead;
		while (temp != NULL)
		{
			struct argstruct *temp1 = t->left;
			while (temp1!=NULL)
			{
				temp1=temp1->next;
			}
			
			fprintf(target_file, "PUSH R%d\n", reg2);
			freereg();
			temp = temp->next;
		}

		fprintf(target_file, "PUSH R0\n");
		fprintf(target_file, "CALL F%d\n", t->val);
		fprintf(target_file, "POP R0\n");

		int arglength = 0;
		temp = t->arghead;
		while (temp != NULL)
		{
			fprintf(target_file, "POP R0\n");
			arglength++;
			temp = temp->next;
		}

		for (int i = (16 - nooffreereg); i >= 0; i--)
		{
			fprintf(target_file, "POP R%d\n", i);
		}
		reg1 = getReg();
		fprintf(target_file, "MOV R%d, SP\n", reg1);
		fprintf(target_file, "ADD R%d, %d\n", reg1, arglength + (16 - nooffreereg) + 1);
		fprintf(target_file, "MOV R%d, [R%d]\n", reg1, reg1);

		return reg1;
	}
}
int getlocalorglobal(struct tnode *root)
{
	if (root->Lentry != NULL)
		return 1;
	if (root->Gentry != NULL)
		return 0;
	return -1;
}
int evaluate(struct tnode *t)
{
	int x, y;
	if (t->nodetype == NUMNODE)
		return t->val;
	else if (t->nodetype == VARNODE)
		return t->Gentry->name;
	else if (t->nodetype == ASSIGNNODE)
	{
		x = evaluate(t->right);
		t->left->Gentry->name = x;
		return x;
	}
	else if (t->nodetype == READNODE)
	{
		scanf("%d", &x);
		t->left->Gentry->name = x;
		return x;
	}
	else if (t->nodetype == WRITENODE)
	{
		x = evaluate(t->left);
		printf("%d", x);
		return x;
	}
	else if (t->nodetype == CONNECTORNODE)
	{
		x = evaluate(t->left);
		y = evaluate(t->right);
		return y;
	}
	else if (t->nodetype == MATHOPNODE)
	{
		x = evaluate(t->left);
		y = evaluate(t->right);
		switch (t->varname[0])
		{
		case '+':
			return x + y;
		case '-':
			return x - y;
		case '*':
			return x * y;
		case '/':
			return x / y;
		}
	}
	else if (t->nodetype == BREAKNODE)
	{
		return -1;
	}
	else if (t->nodetype == CONTINUENODE)
	{
		return -1;
	}
	else if (t->nodetype == WHILENODE)
	{
		while (evaluate(t->left))
		{
			if (evaluate(t->right) == -1)
				break;
		}
		return -1;
	}
	else if (t->nodetype == IFNODE)
	{
		if (evaluate(t->left))
			evaluate(t->right);
		return -1;
	}
	else if (t->nodetype == IFELSENODE)
	{
		if (evaluate(t->left))
			evaluate(t->right->left);
		else
			evaluate(t->right->right);
		return -1;
	}
	else if (t->nodetype == DOWHILENODE)
	{
		do
		{
			if (evaluate(t->left) == -1)
				break;
		} while (evaluate(t->right));
		return -1;
	}
	else if (t->nodetype == STRNODE)
	{
		return -1;
	}
	else if (t->nodetype == RETNODE)
	{
		return -1;
	}
}
int check()
{
	printf("test");
}