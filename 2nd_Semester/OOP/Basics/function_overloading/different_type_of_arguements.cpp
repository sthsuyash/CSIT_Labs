// Overloading Functions with different type of arguments

#include <iostream>
#include <conio.h>
using namespace std;

int mul(int a, int b)
{
    return a * b;
}
float mul(float a, float b)
{
    return a * b;
}
int main()
{
    int p = 2, q = 3;
    float x = 1.0, y = 5.5;
    cout << "Product of integers= " << mul(p, q) << endl;
    cout << "Product of reals= " << mul(x, y);
    getch();
    return 0;
}

/*
Output:
6
5.5
*/
