#include <stdio.h>
#include <string.h>

struct car
{
	char company[20];
	int model;
};

union student
{
	char name[20];
	int roll;
};

int main()
{
	struct car car1;
	// declaring union variable
	union student std;
	strcpy(car1.company, "suzuki");
	car1.model = 2020;

	std.roll = 1001;
	strcpy(std.name, "Tilak Basnet");

	printf("Company is %s and model is %d\n", car1.company, car1.model);
	printf("Student name is %s and roll num is %d", std.name, std.roll);

	return 0;
}
