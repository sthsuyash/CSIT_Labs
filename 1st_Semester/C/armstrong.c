// check armstrong
#include <stdio.h>
#define cube(x) x *x *x

int main()
{
	int num, temp, sum = 0;
	printf("Enter a number: ");
	scanf("%d", &num);
	int n = num;

	while (num != 0)
	{
		temp = num % 10;
		sum += cube(temp);
		num /= 10;
	}
	if (sum == n)
	{
		printf("%d is an armstrong number", n);
	}
	else
	{
		printf("%d is not an armstrong number", n);
	}
	return 0;
}
