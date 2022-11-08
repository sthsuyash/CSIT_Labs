#include<stdio.h>

//= Assign
//+= Increments then assign
//-= Decrements then assign
///= Divides then assign
//*= Multiplies then assign
//%= Modulus then assign


int main(){
	int num = 7;
	num %= 3; // num = num % 20;
	printf("Result is %d",num);
	return 0;
}


