/*
 * Cpp program to implement Diffie Hellman Key Exchange Algorithm
 */

#include <iostream>
#include <cmath>
// #include "./returnName.h"

using namespace std;

int modExp(int base, int exponent, int modulus)
{
    if (exponent == 0)
        return 1;
    int result = 1;
    base = base % modulus;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1; // Right shift exponent by 1
        base = (base * base) % modulus;
    }
    return result;
}

int main()
{
    // generateHeader("Program to implement Diffie Hellman Key Exchange Algorithm");
    int p, g, a, b;
    do
    {
        cout << "Enter a prime number (p): ";
        cin >> p;

        cout << "Enter a primitive root (g) modulo " << p << ": ";
        cin >> g;

        cout << "Enter Alice's private key (a): ";
        cin >> a;

        cout << "Enter Bob's private key (b): ";
        cin >> b;

        int A = modExp(g, a, p); // Calculate Alice's public key
        int B = modExp(g, b, p); // Calculate Bob's public key

        int s1 = modExp(B, a, p); // Calculate shared secret key for Alice
        int s2 = modExp(A, b, p); // Calculate shared secret key for Bob

        if (s1 == s2)
            cout << "Shared secret key: " << s1 << endl;
        else
            cout << "Key exchange failed!" << endl;

        char choice;
        cout << "Do you want to continue (y/n): ";
        cin >> choice;
        if (choice == 'n')
            break;

    } while (true);
    cin.get();
    return 0;
}
