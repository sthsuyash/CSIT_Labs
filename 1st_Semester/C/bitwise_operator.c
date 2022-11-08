/*** Demonstration Of Bitwise operator ***/
#include <stdio.h>
#include <conio.h>
int main()
{
	int a, b;
	printf("Enter the value of a: ");
	scanf("%d", &a);
	printf("Enter the value of b: ");
	scanf("%d", &b);

	printf("a & b : %d\n", a & b);	 // Bitwise AND
	printf("a | b : %d\n", a | b);	 // Bitwise OR
	printf("a : %d\n", a);			 // COMPLEMENT
	printf("a << 1 : %d\n", a << 1); // Left Shift
	printf("b >> 1 : %d\n", b >> 1); // Bitwise OR

	return 0;
}
