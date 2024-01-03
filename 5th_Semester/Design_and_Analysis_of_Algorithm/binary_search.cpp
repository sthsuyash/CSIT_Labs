/*
 * Program: Binary Search Program
 *
 * Binary search is a searching algorithm that searches for an element in a sorted array.
 * It works by repeatedly dividing the search interval in half.
 * Begin with an interval covering the whole array.
 * If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half.
 * Otherwise narrow it to the upper half.
 * Repeatedly check until the value is found or the interval is empty.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 *
 */

#include <iostream>
using namespace std;

int binarySearch(int[], int, int);

int main()
{
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