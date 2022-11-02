// write the program to find the reverse of given number

#include <iostream>
using namespace std;

int main()
{
    int n, rev = 0;
    cout << "Enter a number: ";
    cin >> n;

    while (n != 0)
    {
        int temp = n % 10;
        rev = rev * 10 + temp;
        n /= 10;
    }
    cout << "Reverse: " << rev << endl;

    return 0;
}