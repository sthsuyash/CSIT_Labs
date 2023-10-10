/*
 * Program: Selection Sort Program
 *
 * Selection sort is a sorting algorithm that sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning.
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 *
 */

#include <iostream>
#include "../../../utils/generateHeader.h"
#include "../../../utils/name.h"

using namespace std;

void selectionSort(int[], int);

int main()
{
    // generateHeader("Selection Sort Program");

    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    selectionSort(arr, n);

    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // generateName("0");
    return 0;
}

/*
 * This function sorts an array using selection sort algorithm
 *
 * @param arr[] - array to be sorted
 * @param size - size of the array
 *
 * @returns void
 */
void selectionSort(int arr[], int size)
{
    int minIndex, temp;
    for (int i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}