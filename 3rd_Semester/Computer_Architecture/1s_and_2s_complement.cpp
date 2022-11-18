/*** 1s complement and 2s complement ***/

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string bin, temp, ones, twos;
    int len;

    cout << "Enter a valid binary number: ";
    cin >> bin;
    len = bin.length();
    temp = bin;

    int count = 0;
    while (count != len)
    {
        if (bin[count] != '1' && bin[count] != '0')
        {
            cout << "Invalid binary number." << endl;
            main();
        }
        count += 1;
    }

    // 1's complement
    for (int i = 0; i < len; i++)
    {
        if (bin[i] == '1')
        {
            bin[i] = '0';
        }
        else
        {
            bin[i] = '1';
        }
    }
    ones = bin;

    bin = temp;
    // 2's complement
    int carry = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (bin[i] == '1' && carry == 1)
        {
            bin[i] = '0';
        }
        else if (bin[i] == '0' && carry == 1)
        {
            bin[i] = '1';
            carry = 0;
        }
    }
    twos = bin;

    cout << "The 1s complement of the entered number is: " << ones << endl;
    cout << "The 1s complement of the entered number is: " << twos << endl;

    return 0;
}
