// Pointer and Arrays:

/*
Arrays work very much like pointers to their first elements
and an array can always be implicitly converted to the pointer of the proper type.

For example, consider two declarations:
int x[20];
int *p;
p=x; //valid
x=p; // not valid since x represents the same block of 20
        elements while value of p may be different

In arrays, brackets ([]) are used for specifying the index of an element 
of the array known as dereferencing operator just as * does in pointer.

a[5]=0; //a[offset of 5]=0, gives content
*(a+5)=0; //pointed to by (a+5)=0, gives content
These two expressions are equivalent and valid.
*/

// Example:
#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int var[3] = {10, 20, 30};
    int *p;
    p = var;
    for (int i = 0; i < 3; i++)
    {
        cout << "Value at var[" << i << "] is " << *p << endl;
        p++; // point to next location
    }
    getch();
}