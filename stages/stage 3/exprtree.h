typedef struct tnode {
    int val;        // value of a number for NUM nodes.
    int type;       // type of variable
    char* varname;  // name of a variable for ID nodes
    int nodetype;   // information about non-leaf nodes - read/write/connector/+/* etc.
    struct tnode *left,*right;  // left and right branches
}tnode;
//create abstract syntax tree
struct tnode* createTree(int val, int type, char* varname, int nodetype, struct tnode* l, struct tnode* r);
/*To evaluate an expression tree*/
void preorder(struct tnode* tnode);

//expression types
#define BOOLTYPE 0
#define INTTYPE 1
#define INVALIDTYPE -1

//nodetype definition
#define MATHOPNODE 1
#define READNODE 2
#define WRITENODE 3
#define CONNECTORNODE 4
#define ASSIGNNODE 5
#define VARNODE 6
#define NUMNODE 7
#define IFNODE 8
#define WHILENODE 9
#define LOGICOPNODE 10

//generate code for the expression tree
#define register_index int
register_index codeGen(struct tnode* t,FILE*);
register_index getReg();
register_index freeReg();
int regs[16];
int nooffreereg;
void printtree(struct tnode* t);