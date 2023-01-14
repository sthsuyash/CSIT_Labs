/* C++ Program for the implentation of Restoring Division */

#include <iostream>
#include <math.h>
using namespace std;

int a = 0, b = 0, c = 0, com[5] = {1, 0, 0, 0, 0}, s = 0;
int anum[5] = {0}, bnum[5] = {0}, anumcp[5] = {0};
int acomp[5] = {0}, bcomp[5] = {0}, rem[5] = {0}, quo[5] = {0}, res[5] = {0};

void binary()
{
    a = fabs(a);
    b = fabs(b);
    int r, r2, i, temp;

    for (i = 0; i < 5; i++)
    {
        r = a % 2;
        a = a / 2;
        r2 = b % 2;
        b = b / 2;
        anum[i] = r;
        anumcp[i] = r;
        bnum[i] = r2;

        if (r2 == 0)
            bcomp[i] = 1;
        if (r == 0)
            acomp[i] = 1;
    }
    c = 0;

    for (i = 0; i < 5; i++)
    {
        res[i] = com[i] + bcomp[i] + c;
        if (res[i] >= 2)
            c = 1;
        else
            c = 0;
        res[i] = res[i] % 2;
    }

    for (i = 4; i >= 0; i--)
        bcomp[i] = res[i];
}

void add(int num[])
{
    int i, c = 0;

    for (i = 0; i < 5; i++)
    {
        res[i] = rem[i] + num[i] + c;
        if (res[i] >= 2)
            c = 1;
        else
            c = 0;
        res[i] = res[i] % 2;
    }

    for (i = 4; i >= 0; i--)
    {
        rem[i] = res[i];
        cout << rem[i];
    }
    cout << " : ";

    for (i = 4; i >= 0; i--)
    {
        cout << anumcp[i];
    }
}

void shl()
{
    int i;
    for (i = 4; i > 0; i--)
        rem[i] = rem[i - 1];
    rem[0] = anumcp[4];

    for (i = 4; i > 0; i--)
        anumcp[i] = anumcp[i - 1];
    anumcp[0] = 0;
    cout << "\nSHIFT LEFT: ";

    for (i = 4; i >= 0; i--)
        cout << rem[i];
    cout << " : ";

    for (i = 4; i >= 0; i--)
        cout << anumcp[i];
}

int main()
{
    int i;
    cout << "RESTORING DIVISION" << endl
         << endl
         << "Enter two numbers to divide" << endl
         << "Both numbers should be less than 16" << endl
         << endl;

    do
    {
        cout << "Enter the dividend: ";
        cin >> a;
        cout << "Enter the divisor: ";
        cin >> b;
    } while (a >= 16 || b >= 16);

    cout << endl
         << "Expected Quotient: " << a / b << endl;
    cout << "Expected Remainder: " << a % b << endl;

    if (pow(a, b) < 0)
        s = 1;
    binary();

    cout << endl
         << endl
         << "Unsigned Binary Equivalents are: " << endl;

    cout << "A: ";
    for (i = 4; i >= 0; i--)
        cout << anum[i];

    cout << endl
         << "B: ";
    for (i = 4; i >= 0; i--)
        cout << bnum[i];

    cout << endl
         << "B'+1: ";
    for (i = 4; i >= 0; i--)
        cout << bcomp[i];

    cout << endl
         << endl
         << "-->";
    shl();

    for (i = 0; i < 5; i++)
    {
        cout << endl
             << "-->";
        cout << endl
             << "SUB B: ";
        add(bcomp);

        if (rem[4] == 1)
        {
            cout << endl
                 << "--> RESTORE" << endl
                 << "ADD B: ";
            anumcp[0] = 0;
            add(bnum);
        }
        else
        {
            anumcp[0] = 1;
        }
        if (i < 4)
        {
            shl();
        }
    }
    cout << endl
         << "----------------------------";
    cout << endl
         << "Sign of result: " << s;
    cout << endl
         << "Remainder: ";
    for (i = 4; i >= 0; i--)
        cout << rem[i];
    cout << endl
         << "Quotient: ";
    for (i = 4; i >= 0; i--)
        cout << anumcp[i];

    return 0;
}
