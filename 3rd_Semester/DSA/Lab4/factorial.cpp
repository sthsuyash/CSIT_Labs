/**** algorithm ( factorial using recursion ) ****/
#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;
    cout << "Factorial of " << n << ": " << factorial(n);
    return 0;
}
