// Parameterized Constructor

/*
The constructors that can take arguments are called parameterized constructors.
*/
// For example
#include <iostream>
#include <conio.h>
using namespace std;

class square
{
private:
    int length;

public:
    square(int l)
    {
        length = l;
    }
    int getLength()
    {
        return length;
    }
};

int main()
{
    square s(5); // square s=square(5); is valid too.
    cout << "Length=" << s.getLength() << endl;
    getch();
    return 0;
}
