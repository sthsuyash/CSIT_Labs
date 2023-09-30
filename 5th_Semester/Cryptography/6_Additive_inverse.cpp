/*
 * C++ program to find additive inverse of A under modulo M
 */

#include <bits/stdc++.h>
#include "./returnName.h"
using namespace std;

int gcd(int, int);
int modInverse(int, int);
int power(int, unsigned int, unsigned int);

int main()
{
    generateHeader("Program to find additive inverse of A under modulo M");
    int a, m;

    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of m: ";
    cin >> m;

    if (modInverse(a, m) == -1)
        cout << "Additive Inverse doesn't exist" << endl;
    else
        cout << "Additive Inverse of " << a << " under modulo " << m << " is " << modInverse(a, m) << endl;

    cin.get();
    return 0;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Function to find the additive inverse of A under modulo M
int modInverse(int a, int m)
{
    int returnVal;
    // Inverse doesn't exist
    // or a and m are relatively prime, then modulo inverse is a^(m-2) mode m
    gcd(a, m) != 1 ? returnVal = -1 : returnVal = power(a, m - 2, m);
    return returnVal;
}

// To compute x^y under modulo m
int power(int x, unsigned int y, unsigned int m)
{
    if (y == 0)
        return 1;
    int p = power(x, y / 2, m) % m;
    p = (p * p) % m;
    return (y % 2 == 0) ? p : (x * p) % m;
}
