// Friend Function
/*
A friend function can be given a special grant to access private and protected members.
- Following are some important points about friend functions and classes:
1) Friends should be used only for limited purpose. Too many functions or external classes declared
as friends of a class with protected or private data lessens the value of encapsulation of separate
classes in object-oriented programming.
2) Friendship is not mutual. If class A is a friend of B, then B doesn’t become a friend of A
automatically.
3) Friendship is not inherited
4) The concept of friends is not there in Java.
*/

// Friend Function
#include <iostream>
#include <conio.h>
using namespace std;

class sample
{
private:
    int a, b;

public:
    void setData()
    {
        a = 20;
        b = 40;
    }
    friend float mean(sample s); // Friend function
};

float mean(sample s)
{
    return float(s.a + s.b) / 2;
}

int main()
{
    sample s;
    s.setData();
    cout << "Mean of two numbers=" << mean(s);
    return 0;
}
