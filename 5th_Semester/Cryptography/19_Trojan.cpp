/*
 * Cpp program to shutdown a computer
 applicable for Windows OS only
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
