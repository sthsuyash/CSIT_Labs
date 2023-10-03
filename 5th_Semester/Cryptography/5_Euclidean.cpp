#include <iostream>
// #include "./returnName.h"
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    // generateHeader("Program to Implement Euclidean Algorithm");
    do
    {
        int a, b;
        cout << "Enter the value of a: ";
        cin >> a;
        cout << "Enter the value of b: ";
        cin >> b;
        cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << endl;

        cout << "Do you want to continue? (y/n): ";
        char choice;
        cin >> choice;
        if (choice != 'y' && choice != 'Y')
            break;
        cin.ignore(); // Ignore the newline character in the input buffer
    } while (true);
    return 0;
}
