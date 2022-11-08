#include <stdio.h>
#include <string.h>

char *fullName(char *fname, char *lname)
{
	return strcat(fname, lname);
}

int main()
{
	char fname[] = "Ram ";
	char lname[] = "Karki";
	puts(fullName(fname, lname));
	return 0;
}
