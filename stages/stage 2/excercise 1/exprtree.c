struct tnode* createTree(int val, char* varname, int nodetype, struct tnode* l, struct tnode* r) {
	struct tnode* temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->nodetype = nodetype;
	temp->left = l;
	temp->right = r;
	switch(temp->nodetype) 
	{
		case MATHOPNODE:
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
	}
	return temp;
}
void preorder(struct tnode* ast)
{
	if(ast == NULL)
		return;
	preorder(ast->left);
	printf("%d ", ast->nodetype);
	switch(ast->nodetype) {
		case VARNODE:
			printf("%s ", ast->varname);
			break;
		case NUMNODE:
			printf("%d ",ast->val);
			break;
	}
	
	preorder(ast->right);
}