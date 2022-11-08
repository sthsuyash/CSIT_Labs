#include<stdio.h>
//Postfix -> ()[]                   Associativity
//Unary -> ++, --,sizeof, &, *		Right to Left	
//Multiplicative -> *,/,%			Left to Right				
//Additive -> +,-
//Shift -> <<,>>
//Relational ->  <,>,<=,>=
//Equality -> ==, !=
//Bitwise AND -> &
//Bitwise XOR -> ^
//Bitwise OR -> |
//Logical AND -> &&
//Logical OR -> ||
//Conditional -> ?:                     Right to Left
//Assigment -> =,+=,-=,*=,/=,%=         Right to Left

int main() {
	printf("Result is %d",(20+10)*5/15);
	int num;
	
	num = 10+6;
	num = num++;
	return 0;
}




