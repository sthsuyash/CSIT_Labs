# Sorting Algorithms

```README
Sorting is the process of arranging data into meaningful order so that you can analyze it more effectively.

Internal sorting: If the input data is such that it can be adjusted in the main memory at once, it is called internal sorting.

External sorting: If the input data is such that it cannot be adjusted in the memory entirely at once, it needs to be stored in a hard disk, floppy disk, or any other storage device.
```

## Comparison Sorting

Algorithms: Bubble, Selection, Insertion Sort and Shell Sort

## Divide and Conquer

Merge, Quick and Heap Sort

In insertion sort, we move elements only one position ahead. When an element has to be moved far ahead, many movements are involved.

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
