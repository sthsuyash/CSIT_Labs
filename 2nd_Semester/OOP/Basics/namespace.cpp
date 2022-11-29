// Creating namespaces

#include <iostream>
using namespace std;

namespace ns1
{
    int value() { return 5; }
}
namespace ns2
{
    const double x = 100;
    double value() { return 2 * x; }
}

int main()
{
    // Access value function within ns1
    cout << ns1::value() << '\n';
    // Access value function within ns2
    cout << ns2::value() << '\n';
    // Access variable x directly
    cout << ns2::x << '\n';
    return 0;
}
