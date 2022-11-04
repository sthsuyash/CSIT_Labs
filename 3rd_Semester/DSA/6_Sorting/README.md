# Sorting Algorithms

```README
Sorting is the process of arranging data into meaningful order so that you can analyze it more effectively.

Internal sorting: If the input data is such that it can be adjusted in the main memory at once, it is called internal sorting.

External sorting: If the input data is such that it cannot be adjusted in the memory entirely at once, it needs to be stored in a hard disk, floppy disk, or any other storage device.
```

## Programs

1. ## Comparison Sorting

   - [Bubble Sort](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/DSA/6_Sorting/bubble_sort.cpp)
   - [Insertion Sort](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/DSA/6_Sorting/insertion_sort.cpp)
   - [Selection Sort](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/DSA/6_Sorting/selection_sort.cpp)
   - [Shell Sort](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/DSA/6_Sorting/shell_sort.cpp)

2. ## Divide and Conquer

   - [Merge Sort](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/DSA/6_Sorting/merge_sort.cpp)
   - [Quick Sort](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/DSA/6_Sorting/quick_sort.cpp)
   - [Heap Sort](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/DSA/6_Sorting/heap_sort.cpp)

## Bubble Sort

Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order. This algorithm is not suitable for large data sets as its average and worst-case time complexity is quite high.

- Follow the below steps to solve the problem:

  1. Run a nested for loop to traverse the input array using two variables i and j, such that 0 ≤ i < n-1 and 0 ≤ j < n-i-1
  2. If arr[j] is greater than arr[j+1] then swap these adjacent elements, else move on
  3. Print the sorted array

Time Complexity: O(N2)
Auxiliary Space: O(1)

## Insertion Sort

In insertion sort, we move elements only one position ahead. When an element has to be moved far ahead, many movements are involved.

Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.

- Algorithm

  1. Iterate from arr[1] to arr[N] over the array.
  2. Compare the current element (key) to its predecessor.
  3. If the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements one position up to make space for the swapped element.

## Selection Sort

The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from the unsorted part and putting it at the beginning.

The algorithm maintains two subarrays in a given array.

The subarray which already sorted.
The remaining subarray was unsorted.
In every iteration of the selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.

- Time Complexity: O(N<sup>2</sup>)

- Auxiliary Space: O(1) as the only extra memory used is for temporary variables while swapping two values in Array. The selection sort never makes more than O(N) swaps and can be useful when memory write is a costly operation.

## Shell Sort

Shell sort is mainly a variation of Insertion Sort.The idea of ShellSort is to allow the exchange of far items. In Shell sort, we make the array h-sorted for a large value of h. We keep reducing the value of h until it becomes 1. An array is said to be h-sorted if all sublists of every h’th element are sorted.

- Algorithm:

  1. Start.
  2. Initialize the value of gap size. Example: h.
  3. Divide the list into smaller sub-part. Each must have equal intervals to h.
  4. Sort these sub-lists using insertion sort.
  5. Repeat this step 2 until the list is sorted.
  6. Print a sorted list.
  7. Stop.

## Merge Sort

Merge Sort is a Divide and Conquer algorithm. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves. The merge() function is used for merging two halves. The merge(arr, l, m, r) is key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.

- Algorithm:

  1. Divide the unsorted list into n sublists, each containing 1 element (a list of 1 element is considered sorted).
  2. Repeatedly merge sublists to produce new sorted sublists until there is only 1 sublist remaining. This will be the sorted list.

## Quick Sort

QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways.

- Always pick first element as pivot.
- Always pick last element as pivot (implemented below)
- Pick a random element as pivot.
- Pick median as pivot.

## Heap Sort

Heap Sort is a comparison based sorting technique based on Binary Heap data structure. It is similar to selection sort where we first find the maximum element and place the maximum element at the end. We repeat the same process for remaining element.

- Algorithm:

  1. Build a max heap from the input data.
  2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. Finally, heapify the root of tree.
  3. Repeat above steps while size of heap is greater than 1.

## References

- [GeeksforGeeks](https://www.geeksforgeeks.org/sorting-algorithms/)
- [Tutorials Point](https://www.tutorialspoint.com/data_structures_algorithms/sorting_algorithms.htm)
