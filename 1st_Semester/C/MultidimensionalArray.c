#include <stdio.h>

/*
2 dimensional array:
 int a[][4] -> here 3 is row and 4 is column
		col1	col2	col3	col4
 row1	100		101		102 	103
 row2	104		105		106 	107
 row3	108		109		110 	111


		  col1		   col2		  col3		col4
 row1	a[0][0]		a[0][1]		a[0][2] 	a[0][3]
 row2	a[1][0]		a[1][1]		a[1][2] 	a[1][3]
 row3	a[2][0]		a[2][1]		a[2][2] 	a[2][3]

multi dimensional array initialization:
Total elements = rows*columns
int a[3][4] = {1, 2, 3, 4, 5 ,6 ,7,8, 9, 10,11,12};

int a[3][4] = {{1, 2, 3, 4}, {5 ,6 ,7,8}, {9, 10,11,12}};


*/

int main()
{
	//	int a[3][4] = {1, 2, 3, 4, 5 ,6 ,7, 8, 9 ,10, 11, 12}, i, j;
	int a[3][4], i, j;
	printf("Enter 12 integer numbers ");

	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 3; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	for (i = 0; i <= 2; i++)
	{ // row
		for (j = 0; j <= 3; j++)
		{ // column
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
