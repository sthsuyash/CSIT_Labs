/*
 * Program: Randomized Quick Sort
 *
 * Randomized Quick Sort is an improvement over Quick Sort. 
 * In Quick Sort, we always choose last element as pivot. 
 * By choosing a random index as pivot, the worst case complexity can be reduced to O(nlogn).
 *
 * Time Complexity: O(nlogn)
 * Space Complexity: O(n)
 *
 */

#include <iostream>

using namespace std;

int partition(int[], int, int);
int randomPartition(int[], int, int);
void quickSort(int[], int, int);
void swap(int *, int *);

int main()
{
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

    return 0;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // pi is the partitioning index, arr[pi] is now at the right place
        int pi = randomPartition(arr, low, high);

        // separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = low - 1;       // index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // if current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}

int randomPartition(int arr[], int low, int high)
{
    // generate a random number in between low and high
    srand(time(NULL));
    int random = low + rand() % (high - low);

    // swap the random element with the last element
    swap(&arr[random], &arr[high]);

    return partition(arr, low, high);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
