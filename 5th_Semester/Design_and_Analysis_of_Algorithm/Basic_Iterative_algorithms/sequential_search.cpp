#include <iostream>
#include "../../../utils/generateHeader.h"
#include "../../../utils/name.h"

using namespace std;

int sequentialSearch(int[], int, int);

int main()
{
    generateHeader("Sequential Search Program");

    int n, key, index;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the key to search: ";
    cin >> key;

    index = sequentialSearch(arr, n, key);

    index == -1 ? cout << "Key not found" : cout << "Key found at position " << index + 1;

    generateName("1(c)");
    return 0;
}

int sequentialSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}