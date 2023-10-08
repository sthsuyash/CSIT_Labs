/*
 * Cpp program to implement RSA Algorithm
 */

#include <iostream>
#include <math.h>
// #include "./returnName.h"

using namespace std;

// to find gcd
int gcd(int a, int h)
{
    int temp;
    while (1)
    {
        temp = a % h;
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    }
}

int main()
{
    // 2 random prime numbers
    double p, q;
    char choice;
    do
    {
        cout << "Enter two prime numbers: ";
        cin >> p >> q;

        double n = p * q;
        double count;
        double totient = (p - 1) * (q - 1);

        // public key - e stands for encrypt
        double e = 2;

        // for checking co-prime which satisfies e>1
        while (e < totient)
        {
            count = gcd(e, totient);
            if (count == 1)
                break;
            else
                e++;
        }

        // private key - d stands for decrypt
        double d;
        // k can be any arbitrary value
        double k = 2;

        // choosing d such that it satisfies d*e = 1 + k * totient
        d = (1 + (k * totient)) / e;
        double msg;
        cout << "Enter Message to be encrypted(integer): ";
        cin >> msg;

        double c = pow(msg, e);
        double m = pow(c, d);
        c = fmod(c, n);
        m = fmod(m, n);

        // cout << "Message data = " << msg
        cout << "p = " << p << endl;
        cout << "q = " << q << endl;
        cout << "n = pq = " << n << endl;
        cout << "totient = " << totient << endl;
        cout << "e = " << e << endl;
        cout << "d = " << d << endl;
        cout << "Encrypted data = " << c << endl;
        cout << "Original Message sent = " << m << endl;

        cout << "Do you want to continue? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 0;
}