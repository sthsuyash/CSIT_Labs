/* WAP to find prefix, suffix and substring from given string */

#include <iostream>
#include <string.h>
#include <set>
using namespace std;

int main()
{
    char str[100], prefix[100], suffix[100], substring[100];
    int i, j, k, l, m, n, o, p;

    cout << "Enter a string: ";
    cin >> str;
    l = strlen(str);

    cout << "Prefix: ";
    for (i = 0; i < l; i++)
    {
        for (j = 0; j <= i; j++)
        {
            prefix[j] = str[j];
        }
        prefix[j] = '\0';
        cout << prefix << " ";
    }
    cout << endl;

    cout << "Suffix: ";
    for (k = 0; k < l; k++)
    {
        for (m = k; m < l; m++)
        {
            suffix[m - k] = str[m];
        }
        suffix[m - k] = '\0';
        cout << suffix << " ";
    }
    cout << endl;

    cout << "Substring: ";
    set<string> unique_substrings; // Use a set to keep track of unique substrings
    for (n = 0; n < l; n++)
    {
        for (o = n; o < l; o++)
        {
            // Extract substring using string.substr() function
            string sub = string(str).substr(n, o - n + 1); // (start, length) of substring
            // Check if substring has already been generated
            if (unique_substrings.find(sub) == unique_substrings.end())
            {
                unique_substrings.insert(sub);
                cout << sub << " ";
            }
        }
    }
    cout << endl;

    return 0;
}