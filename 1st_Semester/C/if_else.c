/*** Demonstration Of IF ELSE statement (Condition) ***/
#include <stdio.h>

int main()
{
	int age;
	printf("Enter your age : ");
	scanf("%d", &age);

	if (age <= 13)
	{
		printf("You are a child\n");
	}
	else if (age <= 19)
	{
		printf("You are a teenager\n");
	}
	else if (age <= 50)
	{
		printf("You are an Adult\n");
	}
	else if (age <= 100)
	{
		printf("You are very old\n");
	}
	else
	{
		printf("You are not a human\n");
	}
	printf("Bye Bye!");

	return 0;
}
