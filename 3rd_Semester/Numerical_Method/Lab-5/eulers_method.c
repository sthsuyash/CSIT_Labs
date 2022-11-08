/*** Euler's method to solve first order ODE ***/

#include<stdio.h>
#include<math.h>

float f(float x, float y){
	return x*x+y*y;
}

int main(){
	int i,n;
	float x, y, xp, h, dy;
	
	printf("\nInput initial value of x: ");
    scanf("%f", &x);

    printf("Input initial value of y: ");
    scanf("%f", &y);

    printf("Input x at which y is required: ");
    scanf("%f", &xp);

    printf("Input step-size h: ");
    scanf("%f", &h);

    n=(int)((xp-x)/h+0.5);
    
    for(i=1; i<=n;i++){
    	dy = h*f(x,y);
    	x+=h;
    	y+=dy;
    	printf("\n%d\t%f\t%f\n",i,x,y);
	}
	printf("Value of y at x = %f is %f.\n", x,y);
	
	return 0;
}
