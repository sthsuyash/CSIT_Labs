#include<stdio.h>
#include<math.h>

float f(float x){
	return exp(-x*x);
}

int main(){
	int n,m;
	float a,b,h,sum=0.0, ics, x;
	printf("\nGive lower limit of integration: ");
	scanf("%f",&a);
	printf("\nGive upper limit of integration: ");
	scanf("%f", &b);
	do{
		printf("\nGive number of segments n (divisible by 3): ");
		scanf("%d", &n);
	}while(n%3!=0);
	
	h=(b-a)/n;
	m=n/3;
	
	for(int i=1; i<=m;i++){
		x=a+(3*i-2)*h;
		sum+=3*(f(x)+f(x+h));
		if(i!=m){
			sum+=2*f(x+2*h);
		}
		sum+=f(a)+f(b);
		ics=sum*3*h/8.0;
		printf("\nIntegration between %f and %f when h=%f is %f.", a,b,h,ics);
	}
	
	return 0;
}
