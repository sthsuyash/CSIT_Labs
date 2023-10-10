/*
 * Program: Sequential Search Program
 *
 * Sequential search is a method for finding a particular value in a list, that consists of checking every one of its elements,
 * one at a time and in sequence, until the desired one is found.
 * The algorithm used here is a simple linear search algorithm.
 * The algorithm states that, for searching a key in an array, if the key is found, return the index of the key, else return -1.
 * 
 * For example, consider the array [1, 2, 3, 4, 5] and the key 3.
 * The algorithm will return 2 as the index of the key 3.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 */

#include <iostream>
// #include "../../utils/generateHeader.h"
// #include "../../utils/name.h"

using namespace std;

int sequentialSearch(int[], int, int);

int main()
{
    // generateHeader("Sequential Search Program");

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

    // generateName("0");
    return 0;
}

/*
 * This function searches for a key in an array using sequential search algorithm
 *
 * @param arr[] - array to be searched
 * @param size - size of the array
 * @param key - key to be searched
 *
 * @returns index of the key if found, else -1
 */
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
