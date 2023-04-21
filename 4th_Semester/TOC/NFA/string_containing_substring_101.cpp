/* WAP to simulate a NFA that accepts string containing substring 101 over the alphabet (0, 1) */

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

    // Check if string contains substring 101
    for (i = 0; i < l; i++)
    {
        if (str[i] == '1')
        {
            if (str[i + 1] == '0')
            {
                if (str[i + 2] == '1')
                {
                    flag = 1;
                    break;
                }
            }
        }
    }

    if (flag == 1)
    {
        cout << "String contains substring 101" << endl;
    }
    else
    {
        cout << "String does not contain substring 101" << endl;
    }

    return 0;
}
