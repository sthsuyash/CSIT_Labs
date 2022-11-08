/**** Demonstration of IF nested IF statement *****/
#include <stdio.h>

int main()
{
	int age;
	printf("Enter your age : ");
	scanf("%d", &age);

	if (age > 12)
	{
		if (age > 18)
		{
			if (age > 50)
			{
				printf("\nYou are old");
			}
			else
			{
				printf("\nYou are an adult");
			}
		}
		else
		{
			printf("\nYou are a teenager");
		}
	}
	else
	{
		printf("\nYou are a child");
	}
	printf("\nThank you");

	return 0;
}
