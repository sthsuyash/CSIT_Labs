// WAP in C that takes a string as input from keyboars=d and counts total vowels in it
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char *str, ch; // if input is apple. then ch=a, ch=b...
	int vowel_count = 0;

	printf("Enter a string: ");
	gets(str);

	for (int i = 0; i < strlen(str); i++)
	{
		ch = *(str + i);
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			vowel_count++;
	}

	printf("Total vowels: %d\n", vowel_count);

	return 0;
}
