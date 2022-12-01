// Default Constructor:

/*
Default constructor is the constructor which doesn’t take any argument.
It has no parameters.
*/
#include <iostream>
#include <conio.h>
using namespace std;

class hello
{
public:
    hello()
    {
        cout << "Hello World";
    }
};

int main()
{
    hello h;
    getch();
    return 0;
}
