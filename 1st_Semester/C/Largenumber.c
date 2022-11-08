#include <stdio.h>

int findlargest(int num1, int num2)
{
	if (num1 > num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}

int main()
{
	int result = findlargest(12, 9);
	printf("Maximum number is %d", result);
	return 0;
}
