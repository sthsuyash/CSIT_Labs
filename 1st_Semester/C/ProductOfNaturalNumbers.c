#include <stdio.h>

int main()
{
	int i, product = 1;
	for (i = 1; i <= 10; i++)
	{
		product *= i;
	}
	printf("%d", product);
	return 0;
}
