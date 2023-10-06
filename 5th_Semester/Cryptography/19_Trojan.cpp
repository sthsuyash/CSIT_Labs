/*
 * Cpp program to shutdown a computer
 */

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    cout << "Antivirus program running..." << endl;
    Sleep(10000); // Wait for 10 seconds
    system("shutdown /s /t 1");
    return 0;
}
