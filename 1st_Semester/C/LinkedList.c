#include <stdio.h>
#include <stdlib.h>

struct abc
{
	int data;
	struct abc *next;
};

int main()
{
	struct abc *first;
	struct abc *second;
	struct abc *third;
	struct abc *fourth;
	struct abc *fifth;
	struct abc *newnode;
	struct abc *lastnode;

	first = (struct abc *)calloc(1, sizeof(struct abc));
	second = (struct abc *)calloc(1, sizeof(struct abc));
	third = (struct abc *)calloc(1, sizeof(struct abc));
	fourth = (struct abc *)calloc(1, sizeof(struct abc));
	fifth = (struct abc *)calloc(1, sizeof(struct abc));
	newnode = (struct abc *)calloc(1, sizeof(struct abc));
	lastnode = (struct abc *)calloc(1, sizeof(struct abc));

	// adding new node at the beginning of the linked list
	newnode->data = 1001;
	newnode->next = first;

	first->data = 100;
	first->next = second;

	second->data = 200;
	second->next = third;

	third->data = 300;
	third->next = fourth;

	fourth->data = 400;
	fourth->next = fifth;

	fifth->data = 500;
	fifth->next = lastnode;

	lastnode->data = 202;
	lastnode->next = NULL;

	// printing node details
	first = newnode;
	while (first != NULL)
	{
		printf("Value is %d\n", first->data);
		first = first->next;
	}

	return 0;
}
