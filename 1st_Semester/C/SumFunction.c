#include <stdio.h>

int sumOfNumbers()
{
	int num1, num2, sum;
	printf("Enter any two integer numbers: ");
	scanf("%d%d", &num1, &num2);
	sum = num1 + num2;
	return sum;
}

int main()
{
	int result = sumOfNumbers();
	printf("Sum is %d", result);
	return 0;
}
