#include <iostream>
#include <string>
using namespace std;

void test(int x)
{
    try
    {
        if (x > 0)
            throw x;
        else
            throw 'x';
    }
    catch (int x)
    {
        cout << "Error caught: " << x << endl;
    }
    catch (char x)
    {
        cout << "Error caught: " << x << endl;
    }
}

int main()
{
    test(0);
    return 0;
}