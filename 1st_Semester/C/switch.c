/*
	Switch statement for displaying corresponding grade for marks taken as input from keyboard

	marks  0-19  20-39  40-59  60-79  80-100
	grade  E     D       C      B      A
*/

#include <stdio.h>

int main()
{
	int marks;
	printf("Enter the marks: ");
	scanf("%d", &marks);

	marks /= 10;

	switch (marks)
	{
	case 0:
	case 1:
		printf("Grade E\n");
		break;

	case 2:
	case 3:
		printf("Grade D\n");
		break;

	case 4:
		printf("Grade D+\n");
		break;

	case 5:
		printf("Grade C\n");
		break;

	case 6:
		printf("Grade C+\n");
		break;

	case 7:
		printf("Grade B\n");
		break;

	case 8:
		printf("Grade B+\n");
		break;

	case 9:
		printf("Grade A\n");
		break;

	case 10:
		printf("Grade A+\n");
		break;

	default:
		printf("Invalid marks\n");
	}

	return 0;
}
