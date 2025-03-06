/*** Heun's MEthod to solve first order ODE ***/

#include <stdio.h>
#include <math.h>

float f(float x, float y)
{
	return y - x * x + 1;
}

int main()
{
	int n, i;
	float x, y, xp, h, m1, m2;

	printf("Input initial values of x: ");
	scanf("%f", &x);

	printf("Input initial values of y: ");
	scanf("%f", &y);

	printf("Input x at which y is required: ");
	scanf("%f", &xp);

	printf("Input step-size h: ");
	scanf("%f", &h);

	n = (int)((xp - x) / h + 0.5);

	for (i = 1; i <= n; i++)
	{
		m1 = f(x, y);
		m2 = f(x + h, y + m1 * h);
		x += h;
		y = y + 0.5 * h * (m1 + m2);
		printf("\n%d\t%f\t%f\n.", i, x, y);
	}
	printf("\nValue of y at x = %f is %f\n.", xp, y);

	return 0;
}
