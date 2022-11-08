#include <stdio.h>

int fact(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * fact(n - 1); // return 3*2*1*1
	}
}

int main()
{
	int num, factorial;
	printf("Enter number to calculate factorial: ");
	scanf("%d", &num);
	factorial = fact(num);
	printf("%d", factorial);
	return 0;
}

// 5 -> 5+4+3+2+1+0
// 5 -> 5*4*3*2*1
// 3 -> 3*2*1
