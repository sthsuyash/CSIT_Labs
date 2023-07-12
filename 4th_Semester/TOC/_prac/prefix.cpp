#include <iostream>
#include <string>

using namespace std;

void find_prefix(string str)
{
    int i, j;
    char prefix[20];
    for (i = str.length(); i >= 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            prefix[j] = str[j];
        }
        prefix[j] = '\0';
        cout << prefix << "\n";
    }
}

void find_suffix(string str)
{
    int i, j, k;
    char suffix[20];
    for (i = 0; i <= str.length(); i++)
    {
        k = i;
        for (j = 0; j < str.length(); j++)
        {
            suffix[j] = str[k];
            k++;
        }
        suffix[j] = '\0';
        cout << suffix << "\n";
    }
}

void find_substring(string str, int x, int y)
{
    char substring[20];
    int k = 0;
    for (int i = x - 1; i < y; i++)
    {
        substring[k] = str[i];
        k++;
    }
    substring[k] = '\0';
    cout << substring << "\n";
}

int main()
{
    string str;
    int i, j;

    cout << "Enter the string: ";
    cin >> str;

    cout << "Prefixes are: \n";
    find_prefix(str);

    cout << "Suffixes are: \n";
    find_suffix(str);

    cout << "Enter i and j for substring: ";
    cin >> i >> j;
    cout << "Substrings are: \n";
    find_substring(str, i, j);

    return 0;
}
