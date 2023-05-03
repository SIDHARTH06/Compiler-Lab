// syntax tree node structure
typedef struct tnode
{
    int val;                    // value of a number for NUM nodes.
    int type;                   // type of variable
    char *varname;              // name of a variable for ID nodes
    int nodetype;               // information about non-leaf nodes - read/write/connector/+/* etc.
    struct tnode *left, *right; // left and right branches
    struct Gsymbol *Gentry;     // pointer to a global symbol table entry
    struct lSymbol *Lentry;     // pointer to a local symbol table entry
    struct argstruct *arglist;
    struct tnode *arg;
    struct paramstruct *paramlist;
    int flabel;
    struct argstruct *arghead;
} tnode;
// structure for global symbol table
typedef struct paramstruct
{
    char *name;  // name of the variable
    int type;    // type of the variable
    int size;    // size of the array
    int binding; // stores the static memory address allocated to the variable
    int length;
    struct paramstruct *next; // pointer to next symbol table entry
} paramstruct;
typedef struct argstruct
{
    struct tnode *arg;
    struct argstruct *next;
} argstruct;
// global symbol table
typedef struct Gsymbol
{
    char *name;  // name of the variable
    int type;    // type of the variable
    int size;    // size of the array
    int binding; // stores the static memory address allocated to the variable
    int length;
    int flabel;
    struct tnode *fbinding;
    struct paramstruct *paramlist;
    struct lSymbolTable *lsth;
    struct Gsymbol *next; // pointer to next symbol table entry
    struct paramstruct *paramhead;
    struct argstruct *arghead;
} Gsymbol;


typedef struct gSymbolTable
{
    struct Gsymbol *head;
} gSymbolTable;
gSymbolTable *gst;


//structure for local symbol table

typedef struct Lsymbol
{
    char *name;  // name of the variable
    int type;    // type of the variable
    int size;    // size of the array
    int binding; // stores the static memory address allocated to the variable
    int length;
    struct Lsymbol *next; // pointer to next symbol table entry
} Lsymbol;
int yylex();
void freeGST(struct gSymbolTable *gst);
typedef struct lSymbolTable
{
    struct Lsymbol *head;
} lSymbolTable;
lSymbolTable *lst;

// functions for global symbol table
int assignbinding(struct gSymbolTable *gst,int gm);
void addargtolst(struct lSymbolTable *lst, struct paramstruct *arg);

struct argstruct* createargnode(struct tnode* arg);


int findtype(struct gSymbolTable *gst, char *name);
int evaluate(struct tnode *t);
int getval(char *name);
void setval(char *name, int val);

//functions for local symbol table
int assignbindinglocal(struct lSymbolTable *lst);
int findtypelocal(struct lSymbolTable *lst, char *name);
int getvallocal(char *name);
void setvallocal(char *name, int val);


// type of variable
#define BOOLTYPE 0
#define INTTYPE 1
#define STRINGTYPE 2
#define INVALIDTYPE -1
#define PTRTYPE 3


struct Lsymbol *llookup(struct lSymbolTable *lst, char *name);
struct Lsymbol* joinnodel(struct Lsymbol *lst, struct Lsymbol *newnode);
struct paramstruct* joinparamnode(struct paramstruct *head, struct paramstruct *newnode);
struct argstruct* joinargnode(struct argstruct *head, struct argstruct *newnode);

struct Gsymbol *joinnode(struct Gsymbol *head, struct Gsymbol *node);
// lookup function
struct Gsymbol *lookup(struct gSymbolTable *gst, char *name);
// create abstract syntax tree
struct tnode *createTree(int val, int type, char *varname, int nodetype, struct tnode *l, struct tnode *r);
/*To evaluate an expression tree*/
void preorder(struct tnode *tnode);

void printtree(struct tnode *t);
void freelst(struct lSymbolTable *lst);
// expression types
#define BOOLTYPE 0
#define INTTYPE 1
#define STRTYPE 2
#define INVALIDTYPE -1
#define PTRTYPE 3
#define ADDRTYPE 4
#define VOIDTYPE 5

// nodetype definition
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
#define PTRNODE 20
#define ADDRNODE 21
#define FNNODE 23
#define RETNODE 27
#define MAINNODE 28

// create symbol table

// generate code for the expression tree
#define register_index int
register_index codeGen(struct tnode *t, FILE *,struct lSymbolTable* lst);
register_index getReg();
register_index freeReg();

int checkargissameasparam(struct tnode* t);
int regs[16];
int nooffreereg;
int label;
int label1;
int typeglob;
int findduplicate(struct gSymbolTable *gst);
int getbindingaddress(struct tnode *t,struct lSymbolTable* lst,struct gSymbolTable* gst);
int check();