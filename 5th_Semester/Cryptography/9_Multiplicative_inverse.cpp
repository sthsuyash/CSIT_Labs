#include <iostream>
// #include "./returnName.h"
using namespace std;

// Function to compute the multiplicative inverse of a modulo n using Extended Euclidean Algorithm
int multiplicativeInverse(int a, int n)
{
    int x = 0, y = 1;
    int lastX = 1, lastY = 0;
    int temp;

    while (n != 0)
    {
        int quotient = a / n;
        int remainder = a % n;

        a = n;
        n = remainder;

        temp = x;
        x = lastX - quotient * x;
        lastX = temp;

        temp = y;
        y = lastY - quotient * y;
        lastY = temp;
    }

    // Ensure that the result is positive
    return lastX < 0 ? lastX += a : lastX;
}

int main()
{
    // generateHeader("Program to compute the multiplicative inverse of a modulo n using Extended Euclidean Algorithm");
    do
    {
        int a, n;
        string display_op;

        cout << "Enter an integer a: ";
        cin >> a;

        cout << "Enter a positive integer n (modulus): ";
        cin >> n;

        int inverse = multiplicativeInverse(a, n);
        if (inverse == -1)
            cout << "Multiplicative inverse does not exist.";
        else
            cout << "Multiplicative inverse of " << a << " modulo " << n << " is " << inverse;
        char choice;
        cout << endl
             << "Do you want to continue? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y')
            break;
        cin.ignore();
    } while (true);
    return 0;
}
