#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	char* data[30];
	struct node* next;
}linkNode_t;

int main()
{
	linkNode_t a = { "yang" , NULL};
	linkNode_t b = { "li" , NULL};
	linkNode_t c = { "liu" , NULL};
	linkNode_t d = { "wang" , NULL};

	a.next = &b;
	b.next = &c;
	c.next = &d;

	linkNode_t* head = &a;

	while (head->next != NULL)
	{
		printf("%s\n", head->data);
		head = head->next;
	}

	return 0;
}