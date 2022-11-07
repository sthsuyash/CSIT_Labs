#include <stdio.h>
#include <math.h>

float f(float x)
{
	return 1.0 - exp(-x / 2.0);
}

int main()
{
	int n;
	float a, b, h, ict, sum = 0.0;

	printf("\nGive lower limit of integration: ");
	scanf("%f", &a);
	printf("\nGive upper limit of integration: ");
	scanf("%f", &b);
	printf("\nGive the segment width h: ");
	scanf("%f", &h);
	
	n = (b - a) / h;
	for (int i = 1; i <= n; i++)
	{
		sum += 2 * f(a + i * h);
	}
	sum += f(a) + f(b);
	ict = sum * h / 2;
	
	printf("\nIntegration between %f and %f when h=%f is %f.", a, b, h, ict);

	return 0;
}
