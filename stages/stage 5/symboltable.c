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
struct Gsymbol *createsymbolnode(struct gSymbolTable *gst, char *name, int type, int size, int length)
{
	struct Gsymbol *temp;
	temp = (struct Gsymbol *)malloc(sizeof(struct Gsymbol));
	temp->name = malloc(sizeof(char) * 256);
	temp->name = name;
	temp->type = type;
	temp->size = size;
	temp->binding = 0;
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
// assign binding
void assignbinding(struct gSymbolTable *gst)
{
	struct Gsymbol *temp = gst->head;
	int binding = 4096;
	while (temp != NULL)
	{
		temp->binding = binding;
		binding = binding + temp->size;
		temp = temp->next;
	}
}
// print symbol table
void printsymboltable(struct gSymbolTable *gst)
{
	struct Gsymbol *temp = gst->head;
	printf("%-20s%-20s%-20s%-20s", "NAME", "TYPE", "SIZE", "BINDING\n");
	while (temp != NULL)
	{
		printf("%-20s%-20d%-20d%-20d\n", temp->name, temp->type, temp->size, temp->binding);
		temp = temp->next;
	}
}
// symbol table functions end