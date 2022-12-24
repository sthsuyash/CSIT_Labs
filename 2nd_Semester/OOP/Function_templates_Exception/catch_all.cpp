#include <iostream>
using namespace std;

int main()
{
    double x, y, result;
    char opr;

    cout << "To proceed enter two numbers:" << endl;
    try
    {
        cout << "First number:" << endl;
        cin >> x;
        cout << "Operator:" << endl;
        cin >> opr;
        cout << "Second number:" << endl;
        cin >> y;

        if (opr != '+' && opr != '-' && opr != '*' && opr != '/') // make sure the user typed a valid operator
            throw opr;
        if (y == 0) // find out if the denominator is 0 OUTPUT 2:
            throw y;
        switch (opr)
        { // perform an operation based on the user's choice
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            result = x / y;
            break;
        }
        cout << "Result=" << result << endl; // display the result of the operation
    }
    catch (...)
    { // catch all exception
        cout << "Exception occurred!" << endl;
    }
}
