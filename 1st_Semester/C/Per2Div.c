#include <stdio.h>

char *pertodiv(float percentage)
{
	if (percentage >= 80)
	{
		return "Distinction";
	}
	else if (percentage >= 60)
	{
		return "First";
	}
	else if (percentage >= 50)
	{
		return "Second";
	}
	else if (percentage >= 40)
	{
		return "Passed";
	}
	else
	{
		return "Failed";
	}
}

int main()
{
	float percentage;
	char division;
	printf("Enter your percentage: ");
	scanf("%f", &percentage);
	puts(pertodiv(percentage));
	return 0;
}
