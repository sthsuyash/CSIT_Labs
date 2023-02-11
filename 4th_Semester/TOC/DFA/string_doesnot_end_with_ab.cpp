// cpp program for DFA accepting the string over {a,b} such that string does not end with ab.

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
        // check if the string is over {a,b} or not
        if (str[i] != 'a' && str[i] != 'b')
        {
            cout << "String not accepted.\nPlease enter a string over {a,b}" << endl;
            return 0;
        }

        // dfa transition check
        if (state == 0 && str[i] == 'a')
            state = 1;
        else if (state == 0 && str[i] == 'b')
            state = 0;
        else if (state == 1 && str[i] == 'a')
            state = 1;
        else if (state == 1 && str[i] == 'b')
            state = 2;
        else if (state == 2 && str[i] == 'a')
            state = 1;
        else if (state == 2 && str[i] == 'b')
            state = 0;
    }

    // check if the string is accepted or not,
    // i.e. if the final state is 0 or 1 then string is accepted
    // else string is not accepted
    if (state == 0 || state == 1)
        cout << "String accepted";
    else
        cout << "String not accepted";

    return 0;
}
