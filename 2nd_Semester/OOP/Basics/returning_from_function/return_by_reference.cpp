// Return by Reference

/*
In case of return by reference, a reference to the variable (variable itself) is passed back to the user.
*/

// For example:
#include <iostream>
#include <conio.h>
using namespace std;

int &min(int &x, int &y)
{ //&min to return reference variable
    if (x < y)
        return x;
    else
        return y;
}

int main()
{
    int a, b;
    cout << "Enter two numbers: " << endl;
    cin >> a >> b;
    min(a, b) = 0;
    cout << "a= " << a << endl
         << "b= " << b;
    getch();
    return 0;
}
