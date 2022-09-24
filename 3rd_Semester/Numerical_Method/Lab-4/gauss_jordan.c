#include <stdio.h>
#include <math.h>
#define MAX 10

int main()
{
	int i, j, k, n, pivrow;
	float a[MAX][MAX], b[MAX], large, temp, factor, pivot;

	printf("Input the number of variables: ");
	scanf("%d", &n);

	printf("Input coefficients a(i,j) row-wise (one row at a line): ");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%f", &a[i][j]);
		}
	}
	printf("Enter vector b:");
	for (i = 1; i <= n; i++)
	{
		scanf("%f", &b[i]);
	}

	for (i = 1; i <= n; i++)
	{
		pivrow = i;
		large = a[i][i];

		for (k = i + 1; k <= n; k++)
		{
			if (fabs(a[k][i] > large))
			{
				large = a[k][i];
				pivrow = k;
			}
		}

		if (pivrow != i)
		{
			for (j = i; j <= n; j++)
			{
				temp = a[pivrow][j];
				a[pivrow][j] = a[i][j];
				a[i][j] = temp;
			}

			temp = b[pivrow];
			b[pivrow] = b[i];
			b[i] = temp;
		}

		pivot = a[i][i];

		for (j = 1; j <= n; j++)
		{
			a[i][j] = a[i][j] / pivot;
		}
		b[i] = b[i] / pivot;

		for (j = 1; j <= n; j++)
		{
			if (j != i)
			{
				factor = a[j][i];
				for (k = i; k <= n; k++)
				{
					a[j][k] = a[j][k] - factor * a[i][k];
				}
				b[j] = b[j] - factor * b[i];
			}
		}
	}

	printf("\nSolution vector x:\n");
	for (i = 1; i <= n; i++)
	{
		printf("%f\t", b[i]);
	}

	return 0;
}
