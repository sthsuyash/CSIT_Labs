// C++ program for implementation of selection sort
#include <iostream>
#include "../array_functions.h"
using namespace std;

void selectionSort(int[], int);

// Driver program to test above functions
int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];                   // declare array of size n
    input_array_elements(arr, n); // call function to input array elements

    // before sorting
    cout << "Unsorted array: ";
    printArray(arr, n);

    // call function to sort array
    selectionSort(arr, n);

    // after sorting
    cout << "Sorted array: " << endl;
    printArray(arr, n);

    return 0;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_index;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_index = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_index])
                min_index = j;

        // Swap the found minimum element with the first element
        if (min_index != i)
        {
            swap(arr[min_index], arr[i]);
        }
    }
}
