#include <stdio.h>
#include <stdlib.h>

struct abc
{
	int data;
	struct abc *next;
};

int main()
{
	int nodenum;
	printf("Enter total number of nodes in a linked list: ");
	scanf("%d", &nodenum);
	struct abc *nodes[nodenum];
	int i;

	for (i = 0; i < nodenum; i++)
	{
		nodes[i] = (struct abc *)calloc(1, sizeof(struct abc));
		nodes[i]->data = 100 + i;
		nodes[i]->next = nodes[i + 1];
		printf("Value is %d\n", nodes[i]->data);
	}
	return 0;
}
