#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int x1, x2, y1, y2, r1, r2;

	// first circle
	printf("Enter coordinates of first circle\n");
	printf("x: ");
	scanf("%d", &x1);
	printf("y: ");
	scanf("%d", &y1);
	printf("radius: ");
	scanf("%d", &r1);

	// second circle
	printf("Enter coordinates of second circle\n");
	printf("x: ");
	scanf("%d", &x2);
	printf("y: ");
	scanf("%d", &y2);
	printf("radius: ");
	scanf("%d", &r2);

	float L = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	int R = r1 + r2;

	if (R < L)
	{
		printf("The circles are disjoint.\n");
	}
	else if (R > L)
	{
		printf("The circles intersect each other.\n");
	}
	else
	{
		printf("The circles touch each other.\n");
	}

	return 0;
}
