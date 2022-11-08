#include <stdio.h>
#include <string.h>

int main()
{
	char str1[] = "bomb";
	char str2[] = "caterpillar";

	printf("%s\n", str1);
	printf("%s\n", str2);
	strcpy(str2, str1);
	printf("%s\n", str1);

	return 0;
}
