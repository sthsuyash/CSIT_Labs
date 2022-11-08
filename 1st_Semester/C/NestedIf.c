#include <stdio.h>

// Nested if
// if inside if
int main()
{
	int num1 = 500, num2 = 100;
	if (num1 >= num2)
	{
		if (num1 == num2)
		{
			printf("Number1 is equal to number2");
		}
		else
		{
			printf("Number1 is greater than number2");
		}
	}

	return 0;
}
