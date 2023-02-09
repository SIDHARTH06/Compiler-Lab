//syntax tree node structure
typedef struct tnode {
    int val;        // value of a number for NUM nodes.
    int type;       // type of variable
    char* varname;  // name of a variable for ID nodes
    int nodetype;   // information about non-leaf nodes - read/write/connector/+/* etc.
    struct tnode *left,*right;  // left and right branches
    struct Gsymbol *Gentry; //pointer to a global symbol table entry
}tnode;
//global symbol table
typedef struct Gsymbol {
    char* name; //name of the variable
    int type; //type of the variable
    int size; //size of the array
    int binding; //stores the static memory address allocated to the variable
    int length;
    struct Gsymbol *next; //pointer to next symbol table entry
}Gsymbol;
typedef struct gSymbolTable {
    struct Gsymbol* head;
}gSymbolTable;
gSymbolTable* gst;
//type of variable
#define BOOLTYPE 0
#define INTTYPE 1
#define STRINGTYPE 2
#define INVALIDTYPE -1

struct Gsymbol* joinnode(struct Gsymbol* head,struct Gsymbol* node);
//lookup function
struct Gsymbol* lookup(struct  gSymbolTable* gst,char* name);
//create abstract syntax tree
struct tnode* createTree(int val, int type, char* varname, int nodetype, struct tnode* l, struct tnode* r);
/*To evaluate an expression tree*/
void preorder(struct tnode* tnode);

//expression types
#define BOOLTYPE 0
#define INTTYPE 1
#define STRTYPE 2
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
#define IFELSENODE 11
#define BREAKNODE 12
#define CONTINUENODE 13
#define REPEATUNTILNODE 14
#define DOWHILENODE 15
#define TYPENODE 16
#define BOOLNODE 18
#define STRNODE 19

//create symbol table

//generate code for the expression tree
#define register_index int
register_index codeGen(struct tnode* t,FILE*);
register_index getReg();
register_index freeReg();
int regs[16];
int nooffreereg;
int label;
int label1;
int typeglob;
void printtree(struct tnode* t);
void assignbinding(struct  gSymbolTable* gst);
int findtype(struct  gSymbolTable* gst,char* name);
int evaluate(struct tnode* t);
int getval(char* name);
void setval(char* name,int val);