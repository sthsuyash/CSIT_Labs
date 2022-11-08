#include <stdio.h>

struct student
{
	char name[20];
	int rollno;
};

void display(struct student s[])
{
	int i;
	for (i = 0; i <= 1; i++)
	{
		printf("\nDetail of %d student is: \n", i + 1);
		puts(s[i].name);
		printf("%d", s[i].rollno);
	}
}
int main()
{
	struct student std[22];
	int i;
	for (i = 0; i <= 1; i++)
	{
		printf("Enter %d student details \n", i + 1);
		printf("Enter name ");
		scanf("%s", std[i].name);
		printf("Enter roll no: ");
		scanf("%d", &std[i].rollno);
	}
	display(std);
	return 0;
}
