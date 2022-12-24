#include <iostream>
using namespace std;

template <class T> // function with one parameter
T myMax(T x, T y)
{
    return (x > y) ? x : y;
}

int main()
{
    cout << myMax(30, 20) << endl;
    cout << myMax(2.5, 10.3) << endl;
    cout << myMax('c', 'x') << endl;
    return 0;
}
