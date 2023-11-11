#include <iostream>
#include "../../../utils/generateHeader.h"
#include "../../../utils/name.h"

using namespace std;

int binarySearch(int[], int, int);

int main()
{
    generateHeader("Binary Search Program");

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

    index = binarySearch(arr, n, key);

    index == -1 ? cout << "Key not found" : cout << "Key found at position " << index + 1;

    generateName("1(d)");
    return 0;
}

int binarySearch(int arr[], int size, int key)
{
    int low = 0, high = size - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else if (arr[mid] > key)
            high = mid - 1;
    }
    return -1;
}