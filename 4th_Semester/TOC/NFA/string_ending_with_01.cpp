/* WAP to simulate a NFA that accepts string ending with 01 over the alphabet (0, 1) */

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str[100];
    int i, l, flag = 0;

    cout << "Enter a string: ";
    cin >> str;
    l = strlen(str);

    // Check if string ends with 01
    if (str[l - 1] == '1' && str[l - 2] == '0')
    {
        cout << "String ends with 01" << endl;
    }
    else
    {
        cout << "String does not end with 01" << endl;
    }

    return 0;
}
