// Assignment and copy initialization
/*
- Copy constructor is called when a new object is created from an existing object,
as a copy object is assigned a new value from another existing object.
*/
#include <iostream>
#include <stdio.h>
using namespace std;

class Test
{
public:
    Test() {}
    Test(Test &t)
    {
        cout << "Copy constructor called " << endl;
    }
    void operator=(Test &t)
    {
        cout << "Assignment operator called " << endl;
    }
};

int main()
{
    Test t1, t2;
    t2 = t1;
    Test t3 = t1;
    return 0;
}
