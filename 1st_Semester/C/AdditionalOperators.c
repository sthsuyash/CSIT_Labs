#include <stdio.h>

int main()
{
	int a = 6;
	float b = 4.8;
	char ch = 'a';
	printf("%d\n", a);
	printf("%d\n", &a);
	printf("%d\n", &b);
	printf("%d\n", &ch);
	printf("enter number:");
	scanf("%d", &b);
	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(b));
	printf("%d\n", sizeof(ch));

	return 0;
}
