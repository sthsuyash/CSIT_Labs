// Pass by Reference:

/*In case of pass by reference, address of the variables (variable itself) are passed to
the function but not the copies of the arguments.
*/
// For example
#include <iostream>
#include <conio.h>
using namespace std;

void exchange(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 5, y = 6;
    exchange(x, y);
    cout << "After function call " << endl;
    cout << "x= " << x << endl
         << "y= " << y;
    getch();
    return 0;
}
