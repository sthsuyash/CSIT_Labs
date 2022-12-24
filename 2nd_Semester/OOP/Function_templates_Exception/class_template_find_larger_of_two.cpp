#include <iostream>
using namespace std;

template <class T>
class myPair
{
private:
    T a, b;

public:
    myPair(T x, T y)
    {
        a = x;
        b = y;
    }
    T getMax()
    {
        return (a > b) ? a : b;
    }
};

int main()
{
    myPair<int> object1(10, 20);
    cout << "Larger=" << object1.getMax() << endl;
    myPair<double> object2(20.5, 10.5);
    cout << "Larger=" << object2.getMax() << endl;
    
    return 0;
}