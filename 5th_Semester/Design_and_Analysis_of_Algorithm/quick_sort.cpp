/*
 * Program: Quick Sort Program
 *
 * Quick sort is a highly efficient sorting algorithm and is based on partitioning of array of data into smaller arrays.
 * A large array is partitioned into two arrays one of which holds values smaller than the specified value, say pivot, based on which the partition is made and another array holds values greater than the pivot value.
 *
 * Time Complexity: O(nlogn)
 * Space Complexity: O(n)
 * 
 */

#include <iostream>
// #include "../../utils/generateHeader.h"
// #include "../../utils/name.h"

using namespace std;

void quickSort(int[], int, int);
int partition(int[], int, int);
void swap(int *, int *);

int main()
{
    // generateHeader("Quick Sort Program");

    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // generateName("0");
    return 0;
}

/*
 * This function sorts an array using quick sort algorithm
 *
 * @param arr[] - array to be sorted
 * @param low - starting index
 * @param high - ending index
 *
 * @returns void
 */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // pi is the partitioning index, arr[pi] is now at the right place
        int pi = partition(arr, low, high);

        // separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/*
 * This function takes the last element as pivot,
 * places the pivot element at its correct position in sorted array
 * and places all smaller (smaller than pivot) to left of pivot
 * and all greater elements to right of pivot
 *
 * @param arr[] - array to be sorted
 * @param low - starting index
 * @param high - ending index
 *
 * @returns partitioning index
 */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // if current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // place the pivot element at its correct position
    return (i + 1);
}

/*
 * This function swaps the values of two variables
 * @param a pointer to the first variable
 * @param b pointer to the second variable
 *
 * @returns void
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}