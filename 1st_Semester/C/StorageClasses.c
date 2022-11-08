/*
Four types of storage classes.It determines scope, visibility, and lifetime of a variable.
1. automatic (local variable)
2. external (global variable)
3. static
4. register
*/
#include <stdio.h>

int num = 200; // here num is global variable

void sum(int a, int b)
{
	int result = a + b; // here result is local variable
	// printf("%d",result);
	printf("%d", num);
}

int main()
{
	printf("%d\n", num);
	sum(9, 11);
	return 0;
}
