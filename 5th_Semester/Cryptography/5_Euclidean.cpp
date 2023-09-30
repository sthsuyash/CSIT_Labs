/*
 * C++ program to Implement Euclidean Algorithm
 */

#include <bits/stdc++.h>
#include "./returnName.h"
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    generateHeader("Program to Implement Euclidean Algorithm");
    int a, b;

    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;

    cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << endl;

    cin.get();
    return 0;
}
