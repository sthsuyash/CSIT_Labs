// 2.1 C++ Program Structure

// My first program in C++  // -> comments.
#include <iostream>  // -> not regular code lines but are directives for the preprocessor
#include <conio.h>   // -> tells preprocessor to include the iostream standard file.
using namespace std; //-> namespaces allow to group entities under a name and tells the compiler to use the std namespace.
int main()
{                           //-> point by where all C++ programs start their execution.
    cout << "Hello World!"; //-> causes the message "Hello World" to be displayed on the screen.
    getch();                //-> holds the program until a key is pressed.
    return 0;               //-> terminates main( )function and causes it to return the value 0 to the calling process.
}

// Output
// Hello World!
