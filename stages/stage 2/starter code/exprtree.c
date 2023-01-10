struct tnode* makeReadNode(struct tnode *l){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = (char*)malloc(sizeof(char));
    temp->left = l;
    temp->right = NULL;
    temp->val = 0;
    temp->type = 0;
    temp->varname = NULL;
    *(temp->op) = READ;
    return temp;
}
struct tnode* makeAssignmentNode(struct tnode *l,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = (char*)malloc(sizeof(char));
    temp->left = l;
    temp->right = r;
    temp->val = 0;
    temp->type = 0;
    temp->varname = NULL;
    *(temp->op) = '=';
    return temp;
}
struct tnode* makeWriteNode(struct tnode *l){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = (char*)malloc(sizeof(char));
    temp->left = l;
    temp->right = NULL;
    temp->val = 0;
    temp->type = 0;
    temp->varname = NULL;
    *(temp->op) = WRITE;
    return temp;
}
struct tnode* makeLeafVariableNode(char* c){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = NULL;
    temp->left = NULL;
    temp->right = NULL;
    temp->val = 0;
    temp->type = 0;
    temp->varname = c;
    return temp;
}
struct tnode* makeLeafNode(int n){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = NULL;
    temp->left = NULL;
    temp->right = NULL;
    temp->val = n;
    temp->type = 0;
    temp->varname = NULL;
    return temp;
}
struct tnode* makeOperatorNode(int nodetype,struct tnode *l,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = (char*)malloc(sizeof(char));
    temp->left = l;
    temp->right = r;
    temp->val = 0;
    temp->type = 0;
    temp->varname = NULL;
    switch(nodetype){
        case '+' : *(temp->op) = '+';
                   break;
        case '-' : *(temp->op) = '-';
                   break;
        case '*' : *(temp->op) = '*';
                   break;
        case '/' : *(temp->op) = '/';
                   break;
    }
    return temp;
}
struct tnode* makeConnectorNode(struct tnode *l,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = (char*)malloc(sizeof(char));
    temp->left = l;
    temp->right = r;
    temp->val = 0;
    temp->type = 0;
    temp->varname = NULL;
    *(temp->op) = CONNECTOR;
    return temp;
}
void preorder(struct tnode *t){
    if(t == NULL){
        return;
    }
    if(t->op == NULL){
        if(t->varname == NULL){
            printf("%d ",t->val);
        }
        else{
            printf("%s ",t->varname);
        }
    }
    else{
        printf("%c ",*(t->op));
    }
    preorder(t->left);
    preorder(t->right);
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
}
register_index freeReg(){
    for(int i = 15; i >= 0; i--){
        if(regs[i] == 1){
            regs[i] = 0;
            return i;
        }
    }
}
register_index codeGen(struct tnode *t,FILE *target_file){
    int reg1,reg2;
    if(t->op == NULL){
        reg1 = getReg();
        fprintf(target_file,"MOV R%d, %d\n",reg1,t->val);
        return reg1;
    }
    else{
        reg1 = codeGen(t->left,target_file);
        reg2 = codeGen(t->right,target_file);
        switch(*(t->op)){
            case '+' : fprintf(target_file,"ADD R%d, R%d\n",reg1,reg2);
                       break;
            case '-' : fprintf(target_file,"SUB R%d, R%d\n",reg1,reg2);
                       break;
            case '*' : fprintf(target_file,"MUL R%d, R%d\n",reg1,reg2);
                       break;
            case '/' : fprintf(target_file,"DIV R%d, R%d\n",reg1,reg2);
                       break;
        }
        freeReg();
        return reg1;
    }
    fclose(target_file);
}

