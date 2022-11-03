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
