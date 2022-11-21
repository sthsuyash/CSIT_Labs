/* C Program for the implentation of Restoring Division
 */
#include <iostream>
#include <math.h>
using namespace std;

int getsize(int x)
{
    int c;
    if (x <= 1)
        c = 2;
    else if (x < 4)
        c = 2;
    else if (x < 8)
        c = 3;
    else if (x < 16)
        c = 4;
    else if (x < 32)
        c = 5;
    else if (x < 64)
        c = 6;
    else if (x < 128)
        c = 7;
    else if (x < 256)
        c = 8;
    else if (x < 512)
        c = 9;
    return c;
}

int main()
{
    int B, Q, Z, M, c, c1, e, f, g, h, i, j, x, y, ch, in, S, G, P;
    int a[24], b[12], b1[12], q[12], carry = 0, count = 0;
    char option;
    long num;

    do
    {
        cout << " \n\n -------------------------------------------------------\n";
        cout << "¦\t\tRESTORING PROGRAM FOR DIVISION\t\t¦\n";
        cout << " -------------------------------------------------------\n\n";

        cout << "Enter Divident\t: ";
        cin >> Q;
        y = getsize(Q);

        cout << "Enter Divisor\t: ";
        cin >> M;
        x = getsize(M);

        Z = max(x, y);

        cout << "\nTOTAL BITS CONSIDERED FOR RESULT =>  " << 2 * Z + 1;

        cout << "\nINITIALLY A IS RESET TO ZERO: ";
        for (i = 0; i < Z; i++)
        {
            a[i] = 0;
            cout << a[i];
        }

        for (i = Z; i >= 0; i--)
        {
            b1[i] = b[i] = M % 2;
            M = M / 2;
            b1[i] = 1 - b1[i];
        }
        carry = 1;
        for (i = Z; i >= 0; i--)
        {
            c1 = b1[i] ^ carry;
            carry = b1[i] && carry;
            b1[i] = c1;
        }
        for (i = 2 * Z; i > Z; i--)
        {
            a[i] = Q % 2;
            Q = Q / 2;
        }

        cout << "\n\n\tDivisor\t\t(M)\t: ";
        for (i = 0; i <= Z; i++)
            cout << b[i] << " ";

        cout << "\n\t2'C Divisor\t(M)\t: ";
        for (i = 0; i <= Z; i++)
            cout << b1[i] << " ";

        cout << "\n\tDividend\t(Q)\t: ";
        for (i = Z + 1; i <= 2 * Z; i++)
            cout << a[i] << " ";

        cout << "\n\n\tBITS CONSIDERED:[ A ] [ M ]";
        cout << "\n\t\t\t";
        for (i = 0; i <= Z; i++)
            cout << a[i] << " ";

        cout << " ";
        for (i = Z + 1; i <= 2 * Z; i++)
            cout << a[i] << " ";
        count = Z;

        do
        {
            for (i = 0; i < 2 * Z; i++)
                a[i] = a[i + 1];

            cout << "\n\nLeft Shift\t\t";
            for (i = 0; i <= Z; i++)
                cout << a[i];
            cout << " ";

            for (i = Z + 1; i < 2 * Z; i++)
                cout << a[i];

            carry = 0;
            for (i = Z; i >= 0; i--)
            {
                S = a[i] ^ (b1[i] ^ carry);
                G = a[i] && b1[i];
                P = a[i] ^ b1[i];
                carry = G || (P && carry);
                a[i] = S;
            }

            cout << "\nA< -A-M \t\t";
            for (i = 0; i <= Z; i++)
                cout << a[i];
            cout << " ";
            for (i = Z + 1; i < 2 * Z; i++)
                cout << a[i];
            ch = a[0];

            cout << "\nBIT Q: " << ch;

            switch (ch)
            {
            case 0:
                a[2 * Z] = 1;
                cout << " Q0< -1\t\t";
                for (i = 0; i <= Z; i++)
                    cout << a[i];
                cout << " ";
                for (i = Z + 1; i <= 2 * Z; i++)
                    cout << a[i] << " ";
                break;

            case 1:
                a[2 * Z] = 0;
                cout << " Q0< -0\t\t";
                for (i = 0; i <= Z; i++)
                    cout << a[i];
                cout << " ";
                for (i = Z + 1; i < 2 * Z; i++)
                    cout << a[i];
                carry = 0;
                for (i = Z; i >= 0; i--)
                {
                    S = a[i] ^ (b[i] ^ carry);
                    G = a[i] && b[i];
                    P = a[i] ^ b[i];
                    carry = G || (P && carry);
                    a[i] = S;
                }

                cout << "\nA< -A+M";
                cout << "\t\t\t";
                for (i = 0; i <= Z; i++)
                    cout << a[i];
                cout << " ";
                for (i = Z + 1; i <= 2 * Z; i++)
                    cout << a[i];
                break;
            }
            count--;
        } while (count != 0);
        num = 0;

        cout << "\n\t\t<< QUOTIENT IN BITS >> : ";
        for (i = Z + 1; i <= 2 * Z; i++)
        {
            cout << a[i] << " ";
            num = num + pow(2, 2 * Z - i) * a[i];
        }

        cout << "\n\t\tOUOTIENT IN DECIMAL: " << num;
        num = 0;

        cout << "\n\t\tREMAINDER IN BITS: ";
        for (i = 0; i <= Z; i++)
        {
            cout << a[i];
            num = num + pow(2, Z - i) * a[i];
        }

        cout << "\n\t\tREMAINDER IN DECIMAL: " << num;

        cout << "\n\tDO YOU WANT TO CONTINUE? (y/n): ";
        cin >> option;
        tolower(option);

    } while (option == 'y');

    return 0;
}

/***************** OUTPUT ***********************

¦-----------------------------------------------¦
¦ PROGRAM FOR DIVISION ¦
¦-----------------------------------------------¦

ENTER DIVIDEND : 16
ENTER DIVISOR : 3

TOTAL BITS CONSIDERED FOR RESULT => 11
INITiALLY A IS RESET TO ZERO:0 0 0 0 0 0

Divisor (M) : 0 0 0 0 1 1
2'C Divisor (M) : 1 1 1 1 0 1
Dividend (Q) : 1 0 0 0 0

BITS CONSIDERED: [ A ] [ M ]
0 0 0 0 0 0 1 0 0 0 0

Left Shift 0 0 0 0 0 1 0 0 0 0
A< -A-M 1 1 1 1 1 0 0 0 0 0
BIT Q:1 Q0< -0 1 1 1 1 1 0 0 0 0 0
A< -A+M 0 0 0 0 0 1 0 0 0 0 0

Left Shift 0 0 0 0 1 0 0 0 0 0
A< -A-M 1 1 1 1 1 1 0 0 0 0
BIT Q:1 Q0< -0 1 1 1 1 1 1 0 0 0 0
A< -A+M 0 0 0 0 1 0 0 0 0 0 0

Left Shift 0 0 0 1 0 0 0 0 0 0
A< -A-M 0 0 0 0 0 1 0 0 0 0
BIT Q:0 Q0< -1 0 0 0 0 0 1 0 0 0 0 1

Left Shift 0 0 0 0 1 0 0 0 0 1
A< -A-M 1 1 1 1 1 1 0 0 0 1
BIT Q:1 Q0< -0 1 1 1 1 1 1 0 0 0 1
A< -A+M 0 0 0 0 1 0 0 0 0 1 0

Left Shift 0 0 0 1 0 0 0 0 1 0
A< -A-M 0 0 0 0 0 1 0 0 1 0
BIT Q:0 Q0< -1 0 0 0 0 0 1 0 0 1 0 1
< < QUOTIENT IN BITS>> :0 0 1 0 1
OUOTIENT IN DECIMAL :5
< < REMAINDER IN BITS>>:0 0 0 0 0 1
REMAINDER IN DECIMAL :1 0 0 0 0 1
DO YOU WANT TO CONTINUE PRESS 0-ESC 1-CONT.:0


¦-----------------------------------------------¦
¦ PROGRAM FOR DIVISION ¦
¦-----------------------------------------------¦

ENTER DIVIDEND : 25
ENTER DIVISOR : 6

TOTAL BITS CONSIDERED FOR RESULT = > 11
INITiALLY A IS RESET TO ZERO:0 0 0 0 0 0

Divisor (M) : 0 0 0 1 1 0
2'C Divisor (M) : 1 1 1 0 1 0
Dividend (Q) : 1 1 0 0 1

BITS CONSIDERED:[ A ] [ M ]
0 0 0 0 0 0 1 1 0 0 1

Left Shift 0 0 0 0 0 1 1 0 0 1
A< -A-M 1 1 1 0 1 1 1 0 0 1
BIT Q:1 Q0< -0 1 1 1 0 1 1 1 0 0 1
A< -A+M 0 0 0 0 0 1 1 0 0 1 0

Left Shift 0 0 0 0 1 1 0 0 1 0
A< -A-M 1 1 1 1 0 1 0 0 1 0
BIT Q:1 Q0< -0 1 1 1 1 0 1 0 0 1 0
A< -A+M 0 0 0 0 1 1 0 0 1 0 0

Left Shift 0 0 0 1 1 0 0 1 0 0
A< -A-M 0 0 0 0 0 0 0 1 0 0
BIT Q:0 Q0< -1 0 0 0 0 0 0 0 1 0 0 1

Left Shift 0 0 0 0 0 0 1 0 0 1
A< -A-M 1 1 1 0 1 0 1 0 0 1
BIT Q:1 Q0< -0 1 1 1 0 1 0 1 0 0 1
A< -A+M 0 0 0 0 0 0 1 0 0 1 0

Left Shift 0 0 0 0 0 1 0 0 1 0
A< -A-M 1 1 1 0 1 1 0 0 1 0
BIT Q:1 Q0< -0 1 1 1 0 1 1 0 0 1 0
A< -A+M 0 0 0 0 0 1 0 0 1 0 0
< < QUOTIENT IN BITS>> :0 0 1 0 0
OUOTIENT IN DECIMAL :4
< < REMAINDER IN BITS>>:0 0 0 0 0 1
REMAINDER IN DECIMAL :1 0 0 0 0 1
DO YOU WANT TO CONTINUE PRESS 0-ESC 1-CONT.:0

¦-----------------------------------------------¦
¦ PROGRAM FOR DIVISION ¦
¦-----------------------------------------------¦

ENTER DIVIDEND : 19
ENTER DIVISOR : 7

TOTAL BITS CONSIDERED FOR RESULT = > 11
INITiALLY A IS RESET TO ZERO:0 0 0 0 0 0

Divisor (M) : 0 0 0 1 1 1
2'C Divisor (M) : 1 1 1 0 0 1
Dividend (Q) : 1 0 0 1 1

BITS CONSIDERED:[ A ] [ M ]
0 0 0 0 0 0 1 0 0 1 1

Left Shift 0 0 0 0 0 1 0 0 1 1
A< -A-M 1 1 1 0 1 0 0 0 1 1
BIT Q:1 Q0< -0 1 1 1 0 1 0 0 0 1 1
A < -A+M 0 0 0 0 0 1 0 0 1 1 0

Left Shift 0 0 0 0 1 0 0 1 1 0
A< -A-M 1 1 1 0 1 1 0 1 1 0
BIT Q:1 Q0< -0 1 1 1 0 1 1 0 1 1 0
A< -A+M 0 0 0 0 1 0 0 1 1 0 0

Left Shift 0 0 0 1 0 0 1 1 0 0
A< -A-M 1 1 1 1 0 1 1 1 0 0
BIT Q:1 Q0< -0 1 1 1 1 0 1 1 1 0 0
A< -A+M 0 0 0 1 0 0 1 1 0 0 0

Left Shift 0 0 1 0 0 1 1 0 0 0
A< -A-M 0 0 0 0 1 0 1 0 0 0
BIT Q:0 Q0< -1 0 0 0 0 1 0 1 0 0 0 1

Left Shift 0 0 0 1 0 1 0 0 0 1
A< -A-M 1 1 1 1 1 0 0 0 0 1
BIT Q:1 Q0< -0 1 1 1 1 1 0 0 0 0 1
A< -A+M 0 0 0 1 0 1 0 0 0 1 0
< < QUOTIENT IN BITS>> :0 0 0 1 0
OUOTIENT IN DECIMAL :2
< < REMAINDER IN BITS>>:0 0 0 1 0 1
REMAINDER IN DECIMAL :5 0 0 1 0 1
DO YOU WANT TO CONTINUE PRESS 0-ESC 1-CONT.:0
****/
