// C++ program for insertion sort
#include <iostream>
#include "../array_functions.h"
using namespace std;

// Driver code
int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    input_array_elements(arr, n);

    // before sorting
    cout << "Unsorted array: ";
    printArray(arr, n);

    // call function to sort array
    insertionSort(arr, n);

    // after sorting
    cout << "Sorted array: " << endl;
    printArray(arr, n);

    return 0;
}

// insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
