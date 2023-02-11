// cpp program for DFA for the language of string over {0,1} such that each string starts with 01

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;     // string to be checked
    char state = 0; // initial state (q0)

    cout << "Enter the string: ";
    cin >> str;

    // loop to check each character of the string for the DFA
    for (int i = 0; i < str.length(); i++)
    {
        // check if the string is over {0,1} or not
        if (str[i] != '0' && str[i] != '1')
        {
            cout << "String not accepted.\nPlease enter a string over {0,1}" << endl;
            return 0;
        }

        // dfa transition check
        if (state == 0 && str[i] == '0')
            state = 1;
        else if (state == 0 && str[i] == '1')
            state = 3;
        else if (state == 1 && str[i] == '0')
            state = 3;
        else if (state == 1 && str[i] == '1')
            state = 2;
        else if (state == 2 && str[i] == '0')
            state = 2;
        else if (state == 2 && str[i] == '1')
            state = 2;
    }

    // check if the string is accepted or not,
    // i.e. if the final state is 2 then string is accepted
    // else string is not accepted
    if (state == 2)
        cout << "String accepted";
    else
        cout << "String not accepted";

    return 0;
}
