#include <stdio.h>
#include <string.h>
int main()
{

	//	char name[100] = "prime";
	//	char college[] = {'p','r','i','m','e','c','o','l','l','e','g','e','\0'};
	//	puts(college);
	//	printf("%d",strlen(college));

	char fname[10], lname[10];
	printf("Enter first name: ");
	gets(fname);
	puts(lname);
	strcpy(lname, fname);
	puts(lname);

	//	printf("Enter last name: ");
	//	gets(lname);
	// printf("%d",strcmp(fname, lname));

	//	strcat(fname, lname);
	//	puts(fname);
	//	puts(lname);
	return 0;
}
