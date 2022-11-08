#include <stdio.h>

int main()
{
	char gender;
	printf("Enter gender");
	//	scanf("%c",&gender);
	//	printf("Your gender is %c",gender);
	gender = getchar();
	printf("Your gender is ");
	putchar(gender);
	
	return 0;
}
