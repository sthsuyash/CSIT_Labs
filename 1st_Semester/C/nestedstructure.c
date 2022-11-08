#include<stdio.h>

struct dateofbirth{
	int year;
	int month;
	int day;
};

struct address{
	int state;
	char stateName[];
	char city[];
};

struct student{
	char name[20];
	int rollno;
	struct dateofbirth dob;
	struct address addr;
};

int main(){
	struct student s;
	printf("Enter student details: ");
	printf("Enter name: ");
	gets(s.name);
	
	printf("Enter rollno: ");
	scanf("%d",&s.rollno);
	
	printf("Enter birth year: ");
	scanf("%d",&s.dob.year);
	
	printf("Enter birth month: ");
	scanf("%d",&s.dob.month);
	
	printf("Enter birth day: ");
	scanf("%d",&s.dob.day);
	
	printf("Student detail is: ");
	printf("%d \t %s \t %d \t %d \t %d",s.rollno, s.name, s.dob.year, s.dob.month, s.dob.day);
	
	return 0;
}
