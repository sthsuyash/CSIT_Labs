# Sorting Algorithms

```README
A Sorting Algorithm is used to rearrange a given array or list of elements according to a comparison operator on the elements. The comparison operator is used to decide the new order of elements in the respective data structure.
```

## Shell Sort

Shell sort is mainly a variation of Insertion Sort. In insertion sort, we move elements only one position ahead. When an element has to be moved far ahead, many movements are involved. The idea of ShellSort is to allow the exchange of far items. In Shell sort, we make the array h-sorted for a large value of h. We keep reducing the value of h until it becomes 1. An array is said to be h-sorted if all sublists of every h’th element are sorted.

Algorithm:

- Step 1 − Start.
- Step 2 − Initialize the value of gap size. Example: h.
- Step 3 − Divide the list into smaller sub-part. Each must have equal intervals to h.
- Step 4 − Sort these sub-lists using insertion sort.
- Step 5 – Repeat this step 2 until the list is sorted.
- Step 6 – Print a sorted list.
- Step 7 – Stop.
