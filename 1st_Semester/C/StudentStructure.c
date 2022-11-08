#include <stdio.h>
#include <string.h>

struct Student
{
	int rollno;
	char name[100];
	char address[100];
	char gender[7];
	float percentage;
};

int main()
{
	struct Student std[5];
	int i;

	for (i = 0; i <= 1; i++)
	{
		printf("Enter student %d details \n", i + 1);
		printf("Enter rollno: ");
		scanf("%d", &std[i].rollno);
		getchar();

		printf("Enter name: ");
		gets(std[i].name);

		printf("Enter address: ");
		gets(std[i].address);

		printf("Enter gender: ");
		scanf("%s", std[i].gender);

		printf("Enter percentage: ");
		scanf("%f", &std[i].percentage);

		printf("\n");
		printf("\n");
	}

	for (i = 0; i <= 0; i++)
	{
		printf("Student %d details are: \n", i + 1);
		printf("%d\n", std[i].rollno);
		printf("%s\n", std[i].name);
		printf("%s\n", std[i].address);
		printf("%s\n", std[i].gender);
		printf("length %d", strlen(std[i].gender));
		printf("%f\n", std[i].percentage);
	}
	return 0;
}
