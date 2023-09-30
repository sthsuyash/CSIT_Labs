#include <iostream>
#include "./returnName.h"
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
    generateHeader("Program to compute the multiplicative inverse of a modulo n using Extended Euclidean Algorithm");
    int a, n;
    string display_op;

    cout << "Enter an integer a: ";
    cin >> a;

    cout << "Enter a positive integer n (modulus): ";
    cin >> n;

    int inverse = multiplicativeInverse(a, n);
    inverse == -1 ? display_op = "Multiplicative inverse does not exist." : display_op = "Multiplicative inverse of " + to_string(a) + " modulo " + to_string(n) + " is " + to_string(inverse);
    cout << display_op << endl;

    cin.get();
    return 0;
}
