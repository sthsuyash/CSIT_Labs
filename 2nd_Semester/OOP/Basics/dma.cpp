// Dynamic Memory Allocation

/* C++ defines two unary operators new and delete
that perform the task of allocating and freeing the memory.
They are also known as free store operators.
A data object created inside a block with new will remain in existence
until it is explicitly destroyed by using delete.
*/

/*
Syntax:
new data-type;
delete variable-name;
*/

// Program to demonstrate DMA
#include <iostream>
using namespace std;
int main()
{
    double *pvalue = NULL; // Pointer initialized with null
    pvalue = new double;   // Request memory for the variable
    *pvalue = 29494;       // Store value at allocated address
    cout << "Value of pvalue : " << *pvalue << endl;
    delete pvalue; // free up the memory.
    
    return 0;
}