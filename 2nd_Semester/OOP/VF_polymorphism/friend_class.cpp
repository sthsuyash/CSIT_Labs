// Friend Class
// A friend class can access private and protected members of other class in which it is declared as friend. 
// It is sometimes useful to allow a particular class to access private members of other class.
#include <iostream>
using namespace std;

class A
{
private:
    int x;

public:
    A() { x = 0; }
    friend class B; // Friend Class
};
class B
{
private:
    int b;

public:
    void show(A a)
    {
        // Since B is friend of A, it can access private members of A
        cout << "Private member of class A accessed from friend class B: " << a.x;
    }
};

int main()
{
    A a;
    B b;
    b.show(a);
    return 0;
}
