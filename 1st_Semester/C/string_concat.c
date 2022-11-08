#include <stdio.h>
#include <string.h>

int main()
{
	char str1[] = "red";
	char str2[] = "apple";

	strcat(str1, str2);
	printf("%s", str1);

	return 0;
}
