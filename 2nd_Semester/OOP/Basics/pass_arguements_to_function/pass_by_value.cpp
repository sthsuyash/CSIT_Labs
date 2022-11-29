// Pass by Value

/*
In case of pass by value, copies of the arguments are passed to the function
not the variables themselves.
*/

// For example
#include <iostream>
using namespace std;

void exchange(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 5, y = 6;
    exchange(x, y);
    cout << "After function call " << endl;
    cout << "x= " << x << endl
         << "y= " << y;
    return 0;
}