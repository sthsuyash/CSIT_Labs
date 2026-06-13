// Cpp program for DFA for the language of string over {0,1} in which each string ends with 11


#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int state = 0; // q0 is initial state

    cout << "Enter the string: ";
    cin >> str;


    // loop to check each character of the string for the DFA
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '0' && str[i] != '1')
        {
            cout << "String not accepted.\nPlease enter a string over {0,1}" << endl;
            return 0;
        }

        if (state == 0 && str[i] == '0')
            state = 0;
        else if (state == 0 && str[i] == '1')
            state = 1;
        else if (state == 1 && str[i] == '0')
            state = 0;
        else if (state == 1 && str[i] == '1')
            state = 2;
        else if (state == 2 && str[i] == '0')
            state = 0;
        else if (state == 2 && str[i] == '1')
            state = 2; // corrected
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