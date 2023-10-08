/*
 * Cpp program to implement Elgamal Algorithm
 */

#include <iostream>
#include <cmath>
// #include "./returnName.h"

using namespace std;

// Power function to return value of a ^ b mod P
long long int power(long long int a, long long int b, long long int P)
{
    if (b == 1)
        return a;
    else
        return (((long long int)pow(a, b)) % P);
}

int main()
{
    // generateHeader("Program to implement Elgamal Algorithm");
    long long int P, G, x, a, y, b, ka, kb;
    do
    {
        // Both the persons will be agreed upon the public keys G and P
        cout << "Enter two prime numbers: ";
        cin >> P >> G;

        // Alice will choose the private key a
        cout << "Enter the private key for Alice:";
        cin >> a;

        x = power(G, a, P); // gets the generated key

        // Bob will choose the private key b
        // chosen primary key
        cout << "Enter the private key for Bob:";
        cin >> b;

        y = power(G, b, P); // gets the generated key

        // Generating the secret key after the exchange
        // of keys
        ka = power(y, a, P); // Secret key for Alice
        kb = power(x, b, P); // Secret key for Bob
        cout << endl;
        cout << "Secret key for the Alice is : " << ka << endl;
        cout << "Secret key for the Bob is : " << kb << endl;

        char choice;
        cout << "Do you want to continue (y/n): ";
        cin >> choice;
        if (choice == 'n')
            break;

    } while (true);
    cin.get();
    return 0;
}