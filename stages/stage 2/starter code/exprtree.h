typedef struct tnode {
    int val;        // value of a number for NUM nodes.
    int type;       // type of variable
    char* varname;  // name of a variable for ID nodes
    int nodetype;   // information about non-leaf nodes - read/write/connector/+/* etc.
    struct tnode *left,*right;  // left and right branches
    char op;        // value of the operator for the non-leaf nodes
}tnode;
/*Make a leaf tnode and set the value of val field*/
struct tnode* makeLeafNode(int n);
/*Make a tnode with opertor, left and right branches set*/
struct tnode* makeLeafVariableNode(char* c);
struct tnode* makeOperatorNode(int nodetype,struct tnode *l,struct tnode *r);
struct tnode* makeConnectornode(struct tnode *l,struct tnode *r);
struct tnode* makeReadNode(struct tnode *l);
struct tnode* makeWriteNode(struct tnode *l);
struct tnode* makeAssignmentNode(struct tnode *l,struct tnode *r);
void preorder();
//nodetype definition
#define CONNECTOR 1;
//generate code for the expression tree
int getReg();
int freeReg();
int codeGen(struct tnode *t,FILE*);
#define register_index int;