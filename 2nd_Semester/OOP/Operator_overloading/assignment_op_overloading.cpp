// Assignment Operator Overloading:

/*
We can overload assignment (=) operator in C++.
By overloading assignment operator, all values of one object can be copied to another object by using assignment operator.
If the overloading function for the assignment operator is not written in the class,
the compiler generates the function to overload the assignment operator.
*/
#include <iostream>
#include <conio.h>
using namespace std;

class time
{
private:
    int hrs, mins;

public:
    time(int h, int m)
    {
        hrs = h;
        mins = m;
    }
    void operator=(time &t)
    {
        hrs = t.hrs;
        mins = t.mins;
    }
    void getData()
    {
        cout << "(" << hrs << "," << mins << ")" << endl;
    }
};

int main()
{
    time t1(3, 55), t2(4, 2);
    t1.getData();
    t1 = t2;
    t1.getData();
    return 0;
}
