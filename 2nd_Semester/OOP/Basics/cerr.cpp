// C++ Standard Error Stream (cerr):

/*
The cerr is also a predefined object of ostream class.
The cerr object in conjunction with stream insertion operator (<<)
allows us to send un-buffered error messages to standard error device(screen).
*/

// Example:-
#include <iostream>
using namespace std;
int main()
{
    char str[] = "Unable to read...";
    cerr << "Error message: " << str << endl;
    return 0;
}

// Output:-
// Error message: Unable to read...