#include <stdio.h>

int main()
{

	FILE *file;
	file = fopen("E:\\PRIME\\CSIT\\C Programming\\copydsfgadsf.txt", "r");
	if (file == NULL)
	{
		perror("Error is ");
		printf("\nFile does not exist");
	}
	else
	{
		fprintf(file, "%s", "test message");
	}
	if (ferror(file))
	{
		printf("Error while writing in file\n");
		perror("Error is ");
	}
	// clearing the error message from file stream
	clearerr(file);
	fclose(file);
	return 0;
}
