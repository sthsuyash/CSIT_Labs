// C++ program for implementation of Bubble sort
#include <iostream>
#include "../array_functions.h"
using namespace std;

void bubbleSort(int[], int);

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
    bubbleSort(arr, n);

    // after sorting
    cout << "Sorted array: " << endl;
    printArray(arr, n);

    return 0;
}

// bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
