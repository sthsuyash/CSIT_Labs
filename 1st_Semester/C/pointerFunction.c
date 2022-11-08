#include <stdio.h>

void swap(int *n1, int *n2)
{
	int temp;
	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

int main()
{
	int num1 = 100, num2 = 200;
	printf("Before swap\n");
	printf("num1 is %d\n", num1);
	printf("num2 is %d\n", num2);
	swap(&num1, &num2);
	printf("After swap\n");
	printf("num1 is %d\n", num1);
	printf("num2 is %d\n", num2);
	return 0;
}
