/*** 1s complement ***/
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
    // 1's complement
    for (int i = 0; i < len; i++)
    {
        if (bin[i] == '1')
            bin[i] = '0';
        else
            bin[i] = '1';
    }
    cout << "1's complement: " << bin << endl;
    return 0;
}
