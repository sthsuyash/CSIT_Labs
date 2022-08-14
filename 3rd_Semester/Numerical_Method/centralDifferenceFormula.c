#include<stdio.h>
#include<math.h>

float f(float x){
	return x*x*exp(sqrt(x))*sin(x);
}

int main(){
	float a, h, fd1, fd2;
	char q;
	do{
		printf("\nEnter the point at which derivatives are required: ");
		scanf("%f",&a);
		printf("Enter the value of h: ");
		scanf("%f", &h);
		fd1=(f(a+h)-f(a-h))/(2*h);
		fd2=(f(a+h)-2*f(a)-f(a-h))/(h*h);
		printf("\nThe first and second derivative at x=%f are %f and %f respectively.",a,fd1,fd2);
		scanf("%c", &q);
		
	}while(q=='y');
	
	return 0;
}
