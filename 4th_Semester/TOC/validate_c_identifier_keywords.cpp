/* WAP to validate C identifiers and keywords */

#include <iostream>
#include <string.h>
#include <set>
using namespace std;

int main()
{
    char str[100];
    int i, l, flag = 0;

    cout << "Enter a string: ";
    cin >> str;
    l = strlen(str);

    // Check if first character is a letter
    if (!((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z') || str[0] == '_'))
    {
        cout << "Invalid identifier" << endl;
        return 0;
    }

    // Check if remaining characters are letters, digits or underscore
    for (i = 1; i < l; i++)
    {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9') || str[i] == '_'))
        {
            cout << "Invalid identifier" << endl;
            return 0;
        }
    }

    // Check if string is a keyword
    set<string> keywords = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
    if (keywords.find(str) != keywords.end())
    {
        cout << "Keyword" << endl;
    }
    else
    {
        cout << "Valid identifier" << endl;
    }

    return 0;
}
