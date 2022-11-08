#include<stdio.h>
//0+1+2+3+4+5= 15

int main(){
	int i, sum=0;
	for(i=1; i<=10; i++){
		sum += i;
	}
	printf("Sum is %d ",sum);
	return 0;
}
