/***** Demonstration of increment and decrement operator *****/
#include <stdio.h>

int main()
{
	int a, b;
	printf("Enter the value of a: ");
	scanf("%d", &a);
	printf("Enter the value of b: ");
	scanf("%d", &b);

	printf("++a : %d\n", ++a);
	printf("a++ : %d\n", a++);
	printf("a : %d\n", a);
	printf("--b : %d\n", --b);
	printf("b-- : %d\n", b--);
	printf("b : %d\n", b);

	return 0;
}
