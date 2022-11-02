/**** algorithm ( gcd using recursion ) ****/
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}

int main()
{
    int a, b;

    cout << "Enter a non-negative integer: ";
    cin >> a;
    cout << "Enter another non-negative integer: ";
    cin >> b;
    cout << "G.C.D (" << a << ", " << b << "): " << gcd(a, b);

    return 0;
}
