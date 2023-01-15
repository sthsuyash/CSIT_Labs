/* Cpp program for linear search */

#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
            return i;
    }
    return -1;
}

int main()
{
    int size, num, pos;
    cout << "Enter the size of array: ";
    cin >> size;

    int arr[size]; // declaring array

    // entering data for array
    cout << "Enter the contents of array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the number to be searched: ";
    cin >> num;

    pos = linearSearch(arr, size, num);

    if (pos == -1)
        cout << "Number not found in the array." << endl;
    else
        cout << "Number found at index: " << pos << endl;

    return 0;
}