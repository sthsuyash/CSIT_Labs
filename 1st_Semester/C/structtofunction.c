#include <stdio.h>

struct student
{
	char name[20];
	int rollno;
};

void display(struct student s)
{
	printf("Student detail is: \n");
	puts(s.name);
	printf("%d", s.rollno);
}

int main()
{
	struct student std;
	printf("Enter student details \n");

	printf("Enter name: ");
	gets(std.name);

	printf("Enter roll no ");
	scanf("%d", &std.rollno);

	display(std);

	return 0;
}
