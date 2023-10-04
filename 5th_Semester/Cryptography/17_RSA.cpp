/*
 * Cpp program to demonstrate RSA algorithm
 */

#include <iostream>
#include <cmath>
#include "./returnName.h"
#include "./name.h"

using namespace std;

int gcd(int, int);
long long modExp(long long, long long, long long);

int main()
{
    generateHeader("Program to demonstrate RSA algorithm");
    int choice;
    double p, q, n, phi, d, e, message, c;
    while (true)
    {
        cout << "RSA Menu:" << endl;
        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        // Encryption
        case 1:
            cout << "Enter two prime numbers (p and q): ";
            cin >> p >> q;
            n = p * q;
            phi = (p - 1) * (q - 1);
            cout << "Enter a public key (e): ";
            cin >> e;

            // Verify that e and phi(n) are coprime
            if (gcd(e, phi) != 1)
            {
                cout << "Error: e and phi(n) are not coprime. Please choose a different e." << endl;
                continue;
            }

            cout << "Enter the plaintext message: ";
            cin >> message;
            c = modExp(message, e, n);
            cout << "Encrypted message: " << c << endl;
            break;

        case 2:
            // Decryption
            cout << "Enter two prime numbers (p and q): ";
            cin >> p >> q;
            n = p * q;
            phi = (p - 1) * (q - 1);
            cout << "Enter the private key (d): ";
            cin >> d;

            cout << "Enter the ciphertext message: ";
            cin >> c;

            message = modExp(c, d, n);

            cout << "Decrypted message: " << message << endl;
            break;

        case 3:
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    };
    generateName(17); //
    return 0;
}

// Find gcd
int gcd(int a, int b)
{
    int t;
    while (1)
    {
        t = a % b;
        if (t == 0)
            return b;
        a = b;
        b = t;
    }
}

// Function to calculate modular exponentiation
long long modExp(long long base, long long exponent, long long mod)
{
    if (exponent == 0)
        return 1;
    long long result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}
