/* WAP to simulate a NFA that accepts string starting with 10 over the alphabet (0, 1) */

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

    // Check if string starts with 10
    if (str[0] == '1' && str[1] == '0')
    {
        cout << "String starts with 10" << endl;
    }
    else
    {
        cout << "String does not start with 10" << endl;
    }

    return 0;
}
