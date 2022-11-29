// Pass by Pointer

/*
Working principle of pass by pointer is same as the pass by reference. Only difference is
that instead of using the reference variable we use pointer variable in function definition
and pass address of the variable from function call statement as below:
*/

#include <iostream>
#include <conio.h>
using namespace std;

void exchange(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x = 5, y = 3;
    exchange(&x, &y);
    cout << "After function call: " << endl;
    cout << "Value of x= " << x << endl
         << "Value of y= " << y;
    getch();
    return 0;
}
