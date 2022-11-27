/* C++ implementation of Shell Sort */

#include <iostream>
#include "../array_functions.h"
using namespace std;

int shellSort(int[], int);

int main()
{
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    input_array_elements(arr, n);

    cout << "Array before sorting: " << endl;
    printArray(arr, n);

    shellSort(arr, n);

    cout << "Array after sorting: " << endl;
    printArray(arr, n);

    return 0;
}

/* function to sort arr using shellSort */
int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order keep adding one more element until the entire array is gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            // put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}
