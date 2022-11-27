/*
File Handling
creating a new file
opening an existing file
reading data from existing file
writing data to a file
closing the file

File mode -> Description
r -> opens a text file in read mode
w -> opens a text file in write mode
a -> append
r+ -> read and write mode
w+ -> read and write mode
a+ -> read and append mode
rb -> opens a binary file in read mode
wb-> opens a binary file in write mode
ab -> opens a binary file in append mode
rb+ -> opens a binary file in read and write mode
wb+ -> opens a binary file in read and write mode
ab+ -> opens a binary file in read and append mode
*/

#include <stdio.h>

int main()
{
	FILE *file;
	char text[100];
	file = fopen("E:\\PRIME\\CSIT\\csita.txt", "r");
	if (file == NULL)
	{
		printf("File not created");
	}
	else
	{
		printf("File created");

		printf("Enter text to write in file: ");
		gets(text);

		// writing to file
		fprintf(file, "%s", text);
	}
	fclose(file);
	return 0;
}
