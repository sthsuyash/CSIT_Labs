/****** Demonstration of relational/ comparision operator ( gives only true or false) ****/
#include <stdio.h>

int main()
{
	int a, b;
	printf("Enter the value of a: ");
	scanf("%d", &a);
	printf("Enter the value of b: ");
	scanf("%d", &b);

	printf("a < b: %d\n", a < b);
	printf("b > a: %d\n", b > a);
	printf("a == b : %d\n", a == b);
	printf("a != b : %d\n", a != b);

	return 0;
}
