#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string bin;
    int len;

    cout << "Enter a valid binary number: ";
    cin >> bin;
    len = bin.length();

    for (int i = 0; i < len; i++)
    {
        if (bin[i] == '1')
            bin[i] = '0';
        else
            bin[i] = '1';
    }

    int carry = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (bin[i] == '1' && carry == 1)
            bin[i] = '0';
        else if (bin[i] == '0' && carry == 1)
        {
            bin[i] = '1';
            carry = 0;
        }
    }
    cout << "2's complement: " << bin << endl;
    return 0;
}
