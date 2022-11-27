#include <stdio.h>

int main()
{
	FILE *file;
	char ch;
	file = fopen("E:\\PRIME\\CSIT\\csita.txt", "a");
	if (file == NULL)
	{
		perror("Error: ");
		printf("File doesnot exist");
	}
	else
	{
		//		fprintf(file, "%s", "tialk");
		//		if(ferror(file)){
		//			printf("Error in reading from file");
		//		}
		//		clearerr(file);

		fseek(file, 3, 0);
		fprintf(file, "%s", "basnet");
		//		while((ch=fgetc(file)) != EOF){
		//			putchar(ch);
		//		}
	}
	fclose(file);
	return 0;
}
