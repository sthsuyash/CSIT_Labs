// try block throwing exception

#include <iostream>
using namespace std;

int main()
{
    float a, b;
    cout << "Enter two numbers:" << endl;
    cin >> a >> b;
    try
    {
        if (b == 0)
            throw b;
        else
            cout << "Result=" << a / b << endl;
    }
    catch (float x)
    {
        cout << "Divide by zero exception." << endl;
    }
    cout << "END" << endl;
    return 0;
}
