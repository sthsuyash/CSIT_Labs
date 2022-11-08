#include <stdio.h>

int main()
{

	FILE *sourceFile;
	char character;
	sourceFile = fopen("C:\\Users\\hp\\Desktop\\Structure.txt", "r");
	if (sourceFile == NULL)
	{
		printf("Source file does not exist");
	}
	else
	{
		printf("File exists, reading file content...\n");
		while ((character = fgetc(sourceFile)) != EOF)
		{
			putchar(character);
		}
	}
	// closing file connection
	fclose(sourceFile);
	return 0;
}
