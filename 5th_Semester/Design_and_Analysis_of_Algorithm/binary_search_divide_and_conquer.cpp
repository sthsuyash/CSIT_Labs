/*
 * Program: Binary Search with Divide and Conquer Program
 *
 * Binary search is a searching algorithm that searches for an element in a sorted array.
 * In this approach, the element is always searched in the middle of a portion of an array.
 *
 * Time Complexity: O(logn)
 * Space Complexity: O(1)
 *
 */

#include <iostream>
// #include "../../utils/generateHeader.h"
// #include "../../utils/name.h"

using namespace std;

int binarySearchRecursive(int[], int, int, int);

int main()
{
    // generateHeader("Binary Search with Divide and Conquer Program");

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

    index = binarySearchRecursive(arr, 0, n - 1, key);

    index == -1 ? cout << "Key not found" : cout << "Key found at position " << index + 1;

    // generateName("0");
    return 0;
}

int binarySearchRecursive(int arr[], int low, int high, int key)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            return binarySearchRecursive(arr, mid + 1, high, key);
        else
            return binarySearchRecursive(arr, low, mid - 1, key);
    }

    return -1;
}
