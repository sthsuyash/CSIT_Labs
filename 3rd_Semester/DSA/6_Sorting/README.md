# Sorting Algorithms

```README
Sorting is the process of arranging data into meaningful order so that you can analyze it more effectively.
```

Internal sorting: If the input data is such that it can be adjusted in the main memory at once, it is called internal sorting.

External sorting: If the input data is such that it cannot be adjusted in the memory entirely at once, it needs to be stored in a hard disk, floppy disk, or any other storage device.

## Programs

1. ## Comparison Sorting

   - [Bubble Sort](/3rd_Semester/DSA/6_Sorting/bubble_sort.cpp)
   - [Insertion Sort](/3rd_Semester/DSA/6_Sorting/insertion_sort.cpp)
   - [Selection Sort](/3rd_Semester/DSA/6_Sorting/selection_sort.cpp)
   - [Shell Sort](/3rd_Semester/DSA/6_Sorting/shell_sort.cpp)

2. ## Divide and Conquer

   - [Merge Sort](/3rd_Semester/DSA/6_Sorting/merge_sort.cpp)
   - [Quick Sort](/3rd_Semester/DSA/6_Sorting/quick_sort.cpp)
   - [Heap Sort](/3rd_Semester/DSA/6_Sorting/heap_sort.cpp)

## Bubble Sort

Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order. This algorithm is not suitable for large data sets as its average and worst-case time complexity is quite high.

- Algorithm:

  1. Run a nested for loop to traverse the input array using two variables i and j, such that 0 ≤ i < n-1 and 0 ≤ j < n-i-1
  2. If arr[j] is greater than arr[j+1] then swap these adjacent elements, else move on
  3. Print the sorted array

  ```c
     begin BubbleSort(arr)  
      for all array elements  
         if arr[i] > arr[i+1]  
            swap(arr[i], arr[i+1])  
         end if  
      end for     
      return arr     
   end BubbleSort  
  ```

- Time Complexity: O(N<sup>2</sup>)
- Auxiliary Space: O(1)

## Insertion Sort

In insertion sort, we move elements only one position ahead. When an element has to be moved far ahead, many movements are involved.

Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.

- Algorithm

  1. Iterate from arr[1] to arr[N] over the array.
  2. Compare the current element (key) to its predecessor.
  3. If the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements one position up to make space for the swapped element.

- Time Complexity: O(N<sup>2</sup>) 
- Auxiliary Space: O(1)

## Selection Sort

The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from the unsorted part and putting it at the beginning.

- The algorithm maintains two subarrays in a given array.

  - The subarray which already sorted.
  - The remaining subarray was unsorted.
  - In every iteration of the selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.

```c
   SELECTION SORT(arr, n)  

   Step 1: Repeat Steps 2 and 3 for i = 0 to n-1  
   Step 2: CALL SMALLEST(arr, i, n, pos)  
   Step 3: SWAP arr[i] with arr[pos]  
   [END OF LOOP]  
   Step 4: EXIT  

   SMALLEST (arr, i, n, pos)  
   Step 1: [INITIALIZE] SET SMALL = arr[i]  
   Step 2: [INITIALIZE] SET pos = i  
   Step 3: Repeat for j = i+1 to n  
   if (SMALL > arr[j])  
        SET SMALL = arr[j]  
   SET pos = j  
   [END OF if]  
   [END OF LOOP]  
   Step 4: RETURN pos  
```

- Time Complexity: O(N<sup>2</sup>)
- Auxiliary Space: O(1) => as the only extra memory used is for temporary variables while swapping two values in Array. The selection sort never makes more than O(N) swaps and can be useful when memory write is a costly operation.

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
  <br/>
  
  ```c
      ShellSort(a, n) // 'a' is the given array, 'n' is the size of array  
      for (interval = n/2; interval > 0; interval /= 2)  
      for ( i = interval; i < n; i += 1)  
      temp = a[i];  
      for (j = i; j >= interval && a[j - interval] > temp; j -= interval)  
      a[j] = a[j - interval];   
      a[j] = temp;  
      End ShellSort      
  ```
  
- Time Complexity: O(N^2)
- Auxiliary Space: O(1)

## Merge Sort

Merge Sort is a Divide and Conquer algorithm. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves. The merge() function is used for merging two halves. The merge(arr, l, m, r) is key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.

- Algorithm:

  1. Divide the unsorted list into n sublists, each containing 1 element (a list of 1 element is considered sorted).
  2. Repeatedly merge sublists to produce new sorted sublists until there is only 1 sublist remaining. This will be the sorted list.

```README

Step 1: start

Step 2: declare array and left, right, mid variable

Step 3: perform merge function.
    if left > right
        return
    mid= (left+right)/2
    mergesort(array, left, mid)
    mergesort(array, mid+1, right)
    merge(array, left, mid, right)

Step 4: Stop
```

- Time Complexity: O(N*log(N))
- Auxiliary Space: O(N)

## Quick Sort

QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways.

- Always pick first element as pivot.
- Always pick last element as pivot (implemented below)
- Pick a random element as pivot.
- Pick median as pivot.

```c
   QUICKSORT (array A, start, end){  
      if (start < end){
         p = partition(A, start, end)
         QUICKSORT (A, start, p - 1)
         QUICKSORT (A, p + 1, end)    
      }   
   }  
```

- Time Complexity: O(N^2)
- Auxiliary Space: O(n*logn)

## Heap Sort

Heap Sort is a comparison based sorting technique based on Binary Heap data structure. It is similar to selection sort where we first find the maximum element and place the maximum element at the end. We repeat the same process for remaining element.

- Algorithm:

  1. Build a max heap from the input data.
  2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. Finally, heapify the root of tree.
  3. Repeat above steps while size of heap is greater than 1.
  
  ```c
   HeapSort(arr)  
   BuildMaxHeap(arr)  
   for i = length(arr) to 2  
      swap arr[1] with arr[i]  
      heap_size[arr] = heap_size[arr] ? 1  
      MaxHeapify(arr,1)  
   End  
  ```
  
- Time Complexity: O(n log(n))
- Auxiliary Space: O(1)

## References

- [GeeksforGeeks](https://www.geeksforgeeks.org/sorting-algorithms/)
- [Tutorials Point](https://www.tutorialspoint.com/data_structures_algorithms/sorting_algorithms.htm)
