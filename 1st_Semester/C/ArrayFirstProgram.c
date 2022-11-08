#include <stdio.h>

int main()
{
	int rolls[24] = {100, 101, 102, 103, 104}, i;

	//	for(i=0; i<5; i++){
	//		printf("%d\n",rolls[i]);
	//	}

	for (i = 0; i <= 4; i++)
	{
		printf("Address of %d is %d\n", rolls[i], &rolls[i]);
	}

	return 0;
}
