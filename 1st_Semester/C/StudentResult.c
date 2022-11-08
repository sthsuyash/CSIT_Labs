#include <stdio.h>

int main()
{
	float marks[5], sum = 0, percentage;
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("Enter marks of subject%d", i + 1);
		scanf("%f", &marks[i]);
	}

	for (i = 0; i < 5; i++)
	{
		sum += marks[i];
	}

	percentage = sum / 5;
	printf("Your percentage is %.2f", percentage);

	if (percentage >= 80)
	{
		printf("Distinction");
	}
	else if (percentage >= 60)
	{
		printf("First Division");
	}
	else if (percentage >= 50)
	{
		printf("Second division");
	}
	else if (percentage >= 40)
	{
		printf("Passed");
	}
	else
	{
		printf("You are failed");
	}

	return 0;
}
