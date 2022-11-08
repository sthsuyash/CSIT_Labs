#include <stdio.h>

int main()
{

	FILE *sourceFile;
	FILE *destinationFile;
	char character;
	sourceFile = fopen("C:\\Users\\hp\\Desktop\\Structure.txt", "r");
	destinationFile = fopen("C:\\Users\\hp\\Desktop\\StructureCopy.txt", "w");
	if (sourceFile == NULL)
	{
		printf("Source file does not exist");
	}
	else
	{
		printf("File exists, copying file content...\n");
		while ((character = fgetc(sourceFile)) != EOF)
		{
			// putchar(character);
			// writing to destination file
			fprintf(destinationFile, "%c", character);
		}
	}
	// closing file connection
	fclose(sourceFile);
	fclose(destinationFile);
	return 0;
}
