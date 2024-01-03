/*
 * Program: GCD Calculation Program
 *
 * GCD of two numbers is the largest number that divides both of them.
 * The GCD algorithm used here is calculated using Euclid's algorithm.
 * The algorithm states that, for computing gcd(m, n), if n = 0, then gcd(m, n) = m.
 * Otherwise, gcd(m, n) = gcd(n, m % n).
 *
 * For example, consider the numbers 12 and 42.
 * gcd(12, 42) = gcd(42, 12 % 42) = gcd(42, 12) = gcd(12, 42 % 12) = gcd(12, 6) = gcd(6, 12 % 6) = gcd(6, 0) = 6.
 *
 * Time Complexity: O(logn)
 * Space Complexity: O(1)
 *
 */

#include <iostream>
// #include "../../utils/generateHeader.h"
// #include "../../utils/name.h"

using namespace std;

int gcd(int, int);

int main()
{
    // generateHeader("GCD Calculation Program");

    int num1, num2, gcdResult;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    gcdResult = gcd(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " is " << gcdResult;

    // generateName("0");
    return 0;
}

int gcd(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}