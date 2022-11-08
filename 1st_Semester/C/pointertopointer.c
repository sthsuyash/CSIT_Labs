#include <stdio.h>

int main()
{
	int var, *ptr, **pptr;
	var = 6;

	ptr = &var;
	pptr = &ptr;

	printf("Value of var is %d\n", var);
	printf("Value of ptr is %d\n", *ptr);
	printf("Value of ptr is %d\n", **pptr);

	return 0;
}
