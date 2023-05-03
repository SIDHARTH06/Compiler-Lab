
#include <string.h>
struct Gsymbol *joinnode(struct Gsymbol *head, struct Gsymbol *node)
{
	struct Gsymbol *temp = head;
	if (head == NULL)
	{
		head = node;
		return head;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = node;
	return head;
}
// create and initialize global symbol table
// lookup function
struct Gsymbol *lookup(struct gSymbolTable *gst, char *name)
{
	// check for segmentation fault error
	if(gst == NULL)
		return NULL;
	struct Gsymbol *temp;
	temp = gst->head;
	while (temp != NULL)
	{
		if (strcmp(temp->name, name) == 0)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}
// install function
struct Gsymbol *createsymbolnode(struct gSymbolTable *gst, char *name, int type, int size, int length, int binding, struct paramstruct *paramstruct, struct lSymbolTable *lsth, int flabel)
{
	struct Gsymbol *temp;
	temp = (struct Gsymbol *)malloc(sizeof(struct Gsymbol));
	temp->name = malloc(sizeof(char) * 256);
	temp->name = name;
	temp->type = type;
	temp->size = size;
	temp->binding = binding;
	temp->next = NULL;
	temp->length = length;
	temp->paramlist = paramstruct;
	temp->lsth = lsth;
	temp->flabel = flabel;
	return temp;
}
struct Lsymbol *createlocalsymbolnode(char *name, int type, int size, int length, int binding)
{
	struct Lsymbol *temp;
	temp = (struct Lsymbol *)malloc(sizeof(struct Lsymbol));
	temp->name = malloc(sizeof(char) * 256);
	temp->name = name;
	temp->type = type;
	temp->size = size;
	temp->binding = binding;
	temp->next = NULL;
	temp->length = length;
	return temp;
}

// findtype function
int findtype(struct gSymbolTable *gst, char *name)
{
	// check for segmentation fault
	struct Gsymbol *temp = gst->head;
	while (temp != NULL)
	{
		if (strcmp(temp->name, name) == 0)
		{
			return temp->type;
		}
		temp = temp->next;
	}
	return -1;
}
// print symbol table
void printglobalsymboltable(struct gSymbolTable *gst)
{
	struct Gsymbol *temp = gst->head;
	printf("%-20s%-20s%-20s%-20s", "NAME", "TYPE", "SIZE", "BINDING\n");
	while (temp != NULL)
	{
		printf("%-20s%-20d%-20d%-20d\n", temp->name, temp->type, temp->size, temp->binding);
		temp = temp->next;
	}
}
void printlocalsymboltable(struct lSymbolTable *lst)
{
	struct Lsymbol *temp = lst->head;
	printf("%-20s%-20s%-20s%-20s", "NAME", "TYPE", "SIZE", "BINDING\n");
	while (temp != NULL)
	{
		printf("%-20s%-20d%-20d%-20d\n", temp->name, temp->type, temp->size, temp->binding);
		temp = temp->next;
	}
}
// functions for local symbol table
//  create and initialize local symbol table

// lookup function
struct Lsymbol *llookup(struct lSymbolTable *lst, char *name)
{
	// check for segmentation fault error
	struct Lsymbol *temp;
	temp = lst->head;
	while (temp != NULL)
	{
		if (strcmp(temp->name, name) == 0)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}
// findtype function
int lfindtype(struct lSymbolTable *lst, char *name)
{
	// check for segmentation fault
	struct Lsymbol *temp = lst->head;
	while (temp != NULL)
	{
		if (strcmp(temp->name, name) == 0)
		{
			return temp->type;
		}
		temp = temp->next;
	}
	return -1;
}
// print symbol table
void lprintsymboltable(struct lSymbolTable *lst)
{
	struct Lsymbol *temp = lst->head;
	printf("%-20s%-20s%-20s%-20s", "NAME", "TYPE", "SIZE", "BINDING\n");
	while (temp != NULL)
	{
		printf("%-20s%-20d%-20d%-20d\n", temp->name, temp->type, temp->size, temp->binding);
		temp = temp->next;
	}
}
// find duplicate elemets in symbol table given head of symbol table as argument
int lfindduplicate(struct lSymbolTable *lst)
{
	struct Lsymbol *temp = lst->head;
	struct Lsymbol *temp2 = lst->head;
	while (temp != NULL)
	{
		temp2 = temp->next;
		while (temp2 != NULL)
		{
			if (strcmp(temp->name, temp2->name) == 0)
			{
				return 1;
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return 0;
}

// symbol table functions
struct paramstruct *createparamnode(char *name, int type, int size, int length)
{
	struct paramstruct *temp;
	temp = (struct paramstruct *)malloc(sizeof(struct paramstruct));
	temp->name = malloc(sizeof(char) * 256);
	temp->name = name;
	temp->type = type;
	temp->size = size;
	temp->binding = 0;
	temp->next = NULL;
	temp->length = length;
	return temp;
}
// join param node
struct paramstruct *joinparamnode(struct paramstruct *head, struct paramstruct *newnode)
{
	struct paramstruct *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
	return head;
}

struct Lsymbol* joinnodel(struct Lsymbol *lsth, struct Lsymbol *newnode)
{
	struct Lsymbol *temp = lsth;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
	return lsth;
}

// add arg to lst
void addargtolst(struct lSymbolTable *lst, struct paramstruct *arg)
{
	struct Lsymbol *temp = lst->head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = createlocalsymbolnode(arg->name, arg->type, arg->size, arg->length, arg->binding);
}

// symbol table functions end

// arg functions
struct argstruct *createargnode(struct tnode *arg)
{
	struct argstruct *temp;
	temp = (struct argstruct *)malloc(sizeof(struct argstruct));
	temp->arg = arg;
	temp->next = NULL;
	return temp;
}
// join arg node
struct argstruct *joinargnode(struct argstruct *head, struct argstruct *newnode)
{
	struct argstruct *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
	return head;
}
void freelst(struct lSymbolTable *lst)
{
	/*struct Lsymbol *temp = lst->head;
	struct Lsymbol *temp2;
	while (temp != NULL)
	{
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}*/
}
// arg functions end
void freeGST(struct gSymbolTable *gst)
{
	struct Gsymbol *temp = gst->head;
	struct Gsymbol *temp2;
	while (temp != NULL)
	{
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
}
int findduplicate(struct gSymbolTable *gst)
{
	struct Gsymbol *temp = gst->head;
	struct Gsymbol *temp2 = gst->head;
	while (temp != NULL)
	{
		temp2 = temp->next;
		while (temp2 != NULL)
		{
			if (strcmp(temp->name, temp2->name) == 0)
			{
				return 1;
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return 0;
}
int findlocalduplicate(struct lSymbolTable *lst)
{
	struct Lsymbol *temp = lst->head;
	struct Lsymbol *temp2 = lst->head;
	while (temp != NULL)
	{
		temp2 = temp->next;
		while (temp2 != NULL)
		{
			if (strcmp(temp->name, temp2->name) == 0)
			{
				return 1;
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return 0;
}
int assignbinding(struct gSymbolTable *gst,int gm)
{
	struct Gsymbol *temp = gst->head;
    while (temp != NULL){
        if (temp->flabel == -1){
        temp->binding = gm;
        gm += temp->size;
        }
        temp = temp->next;
    }
}
int assignbindinglocal(struct lSymbolTable *lst)
{
	struct Lsymbol *temp = lst->head;
	int binding = 1;
	while (temp != NULL)
	{
		temp->binding = binding;
		binding = binding + temp->size;
		temp = temp->next;
	}
}
int getbindingaddress(struct tnode *t,struct lSymbolTable* lst, struct gSymbolTable* gst )
{
	struct Lsymbol *temp = llookup(lst,t->varname);
	if (temp == NULL)
	{
		if(lookup(gst,t->varname) == NULL){
			printf("Error: variable %s not declared\n", t->varname);
			exit(1);
		}
		else
		{
			return llookup(lst,t->varname)->binding;
		}
	}
	return temp->binding;
}
void printlst(struct lSymbolTable *lst)
{
	struct Lsymbol *temp = lst->head;
	printf("Name\t\tType\t\tSize\t\tBinding\n");
	while (temp != NULL)
	{
		printf("%-20s%-20d%-20d%-20d\n", temp->name, temp->type, temp->size, temp->binding);
		temp = temp->next;
	}
}
void printgst(struct gSymbolTable *gst)
{
	struct Gsymbol *temp = gst->head;
	printf("Name\t\tType\t\tSize\t\tBinding\n");
	while (temp != NULL)
	{
		printf("%-20s%-20d%-20d%-20d\n", temp->name, temp->type, temp->size, temp->binding);
		temp = temp->next;
	}
}
void printarg(struct argstruct *arg)
{
	struct argstruct *temp = arg;
	while (temp != NULL)
	{
		printf("%s\n", temp->arg->varname);
		temp = temp->next;
	}
}
void printparam(struct paramstruct *param)
{
	struct paramstruct *temp = param;
	while (temp != NULL)
	{
		printf("%s\n", temp->name);
		temp = temp->next;
	}
}
int checkargissameasparam(struct tnode* t)
{
	check();
	//check length of arg and param
	int arglen=0;
	int paramlen=0;
	struct argstruct* temp2=t->arglist;
	while(temp2!=NULL)
	{
		if(temp2->arg!=NULL)
		arglen++;
		temp2=temp2->next;
	}
	struct paramstruct* temp3=t->paramlist;
	while(temp3!=NULL)
	{
		paramlen++;
		temp3=temp3->next;
	}
	if(arglen!=paramlen)
	{
		printf("Error: number of arguments mismatch in function %s\n", t->varname);
		exit(1);
	}
	
}

