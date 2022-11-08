#include <stdio.h>

int main()
{
	char name[5];
	printf("Enter your name: ");
	scanf("%s", &name);
	printf("Name is %s", name);
	//    gets(name);
	//    printf("Name is ");
	//    puts(name);
	return 0;
}
