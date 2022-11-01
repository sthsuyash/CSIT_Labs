# Sorting Algorithms

```README
Sorting is the process of arranging data into meaningful order so that you can analyze it more effectively.

Internal sorting: If the input data is such that it can be adjusted in the main memory at once, it is called internal sorting.

External sorting: If the input data is such that it cannot be adjusted in the memory entirely at once, it needs to be stored in a hard disk, floppy disk, or any other storage device.
```

## Programs

1. ## Comparison Sorting

   - [Bubble Sort](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/DSA/Lab6/bubble_sort.cpp)
   - [Selection Sort](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/DSA/Lab6/selection_sort.cpp)
   - [Insertion Sort](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/DSA/Lab6/insertion_sort.cpp)
   - [Shell Sort](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/DSA/Lab6/shell_sort.cpp)

2. ## Divide and Conquer

   - [Merge Sort](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/DSA/Lab6/merge_sort.cpp)
   - [Quick Sort](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/DSA/Lab6/quick_sort.cpp)
   - [Heap Sort](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/DSA/Lab6/heap_sort.cpp)

In insertion sort, we move elements only one position ahead. When an element has to be moved far ahead, many movements are involved.

## Selection Sort

The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from the unsorted part and putting it at the beginning.

The algorithm maintains two subarrays in a given array.

The subarray which already sorted.
The remaining subarray was unsorted.
In every iteration of the selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.

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
