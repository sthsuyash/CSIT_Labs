// C++ Standard Log Stream (clog):

/*
The clog is also a predefined object of ostream class. 
The clog object in conjunction with stream insertion operator (<<) 
allows us to send buffered error messages to standard error device(screen) 
until the buffer(temporary placeholder) is filled or until the buffer is flushed.
*/

// Example:-
#include <iostream>
using namespace std;
int main()
{
    char str[] = "Unable to read...";
    clog << "Error message: " << str << endl;
    return 0;
}

// Output:- Error message: Unable to read...
