// Default Arguments

/*
When declaring a function we can specify a default value for each of the parameters which are called default arguments. 
This value will be used if the corresponding argument is left blank when calling to the function.

If value for the parameter is not passed when a function is called, 
the default value is used, but if a value is specified this default value is ignored and the passed value is used instead.
*/

// For example:
// Default values in functions
#include <iostream>
#include <conio.h>
using namespace std;

int divide(int a, int b = 2)
{
    return a / b;
}

int main()
{
    cout << divide(20) << endl;
    cout << divide(20, 5) << endl;
    getch();
    return 0;
}
