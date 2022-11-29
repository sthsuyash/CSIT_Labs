// C++ Standard Input Stream (cin)

/* 
The cin is basically a predefined object of istream class. 
The cin object in conjunction with stream extraction operator (>>) 
allows us to accept/extract data from standard input device(keyboard).
*/

// Example:-
#include <iostream>
using namespace std;
int main()
{
    int age;
    cout << "Enter your age: ";
    cin >> age; // scanf() in C
    cout << "Your age is: " << age << endl;
}

// Output:-
// Enter your age: 35
// Your age is: 35
