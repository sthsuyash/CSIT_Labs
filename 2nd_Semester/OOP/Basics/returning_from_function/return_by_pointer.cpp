// Return by Pointer

/*
Returning by pointer involves returning the address of a variable to the user. 
Just like pass by pointer, return by pointer can only return the address of a variable.
*/

// Example
#include <iostream>
#include <conio.h>
using namespace std;

int *min(int *a, int *b)
{ //*min to return pointer variable
    if (*a < *b)
        return a;
    else
        return b;
}

int main()
{
    int x = 5, y = 3;
    int *m = min(&x, &y);                         //*m to store pointer variable
    cout << "Smaller Element is: " << *m << endl; //*m to display content in memory address m
    getch();
    return 0;
}
