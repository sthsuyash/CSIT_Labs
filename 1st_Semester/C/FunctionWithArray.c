#include <stdio.h>

float calculateTotal(float marks[])
{
	int i;
	float total = 0;
	for (i = 0; i <= 4; i++)
	{
		total += marks[i];
	}
	return total;
}

int main()
{
	float marks[] = {98.2, 45.6, 80.3, 77, 47.9}, obtainedTotal;
	obtainedTotal = calculateTotal(marks);
	printf("%f", obtainedTotal);
	return 0;
}
