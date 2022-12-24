#include <iostream>
using namespace std;

template <class T, class U>
T myMax(T x, U y)
{
    return (x > y) ? x : y;
}

int main()
{
    cout << myMax(10.5, 20) << endl;
    cout << myMax<double>(10.5, 5) << endl;
    cout << myMax(100, 'y') << endl;
    return 0;
}
