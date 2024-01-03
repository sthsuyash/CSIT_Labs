# Design and Analysis of algorithms

### 1. Basic Iterative Algorithms

- GCD algorithm • [Code](./gcd.cpp) • [Theory](#gcd-algorithm)
- Fibonacci series • [Code](./fibonacci.cpp) • [Theory](#fibonacci-series)
- Sequential search • [Code](./sequential_search.cpp) • [Theory](#sequential-search)
- Binary iterative search • [Code](./binary_search.cpp) • [Theory](#binary-iterative-search)

### 2. Basic Iterative Sorting Algorithms

- Bubble sort • [Code](./bubble_sort.cpp) • [Theory](#bubble-sort)
- Selection sort • [Code](./selection_sort.cpp) • [Theory](#selection-sort)
- Insertion sort • [Code](./insertion_sort.cpp) • [Theory](#insertion-sort)

### 3. Binary Search with Divide and Conquer approach

- Binary Search with Divide and Conquer [Code](./binary_search_divide_and_conquer.cpp) • [Theory](#binary-search-with-divide-and-conquer-approach)

### 4. Merge, Heap, Quick and Randomized Quick Sort

- Merge sort • [Code](./merge_sort.cpp) • [Theory](#merge-sort)
- Heap sort • [Code](./heap_sort.cpp) • [Theory](#heap-sort)
- Quick sort • [Code](./quick_sort.cpp) • [Theory](#quick-sort)
- Randomized quick sort • [Code](./randomized_quick_sort.cpp) • [Theory](#randomized-quick-sort)

### 5. Selection Problem with Divide and Conquer approach

- Selection problem • [Code](./selection_problem.cpp) • [Theory](#selection-problem)

### 6. Fractional Knapsack, Job Sequencing with Deadlines, Kruskal’s and Prim’s Algorithm

- Fractional knapsack • [Code](./fractional_knapsack.cpp) • [Theory](#fractional-knapsack)
- Job sequencing with deadlines • [Code](./job_sequencing.cpp) • [Theory](#job-sequencing-with-deadlines)
- Kruskal’s algorithm • [Code](./kruskal.cpp) • [Theory](#kruskals-algorithm)
- Prim’s algorithm • [Code](./prim.cpp) • [Theory](#prims-algorithm)

### 7. Dynamic Programming

- Matrix chain multiplication • [Code](./matrix_chain_multiplication.cpp) • [Theory](#matrix-chain-multiplication)
- String Edit Distance • [Code](./string_editing.cpp) • [Theory](#string-edit-distance)
- Floyd Warshall algorithm • [Code](./floyd_warshall.cpp) • [Theory](#floyd-warshall-algorithm)
- 0/1 knapsack • [Code](./zero_one_knapsack.cpp) • [Theory](#01-knapsack)
- Travelling salesman problem • [Code](./travelling_salesman.cpp) • [Theory](#travelling-salesman-problem)

### 8. Algorithms using Backtracking program

- N-Queen problem • [Code](./n_queen.cpp) • [Theory](#n-queen-problem)
- Subset sum problem • [Code](./subset_sum.cpp) • [Theory](#subset-sum-problem)

### 9. Implement approximation algorithm

- Vertex Cover Problem • [Code](./vertex_cover_problem.cpp) • [Theory](#vertex-cover)

## Theory section

### [GCD algorithm](./gcd.cpp)

GCD of two numbers is the largest number that divides both of them. A simple way to find GCD is to factorize both numbers and multiply common factors.

#### Algorithm

```python
GCD(a, b)
    if b == 0
        return a
    else
        return GCD(b, a%b)
```

#### Time complexity

- Best case: `O(1)`
- Worst case: `O(log n)`
- Average case: `O(log n)`
- Space complexity: `O(1)`
- Auxiliary space complexity: `O(1)`
- Sorting in place: `Yes`
- Stable: `Yes`

### [Fibonacci series](./fibonacci.cpp)

The Fibonacci numbers are the numbers in the following integer sequence. `0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...`

In mathematical terms, the sequence `F(n)` of Fibonacci numbers is defined by the recurrence relation

```c
F(n) = F(n-1) + F(n-2)
```

with seed values `F(0) = 0 and F(1) = 1.`

#### Algorithm

```python
Fib(n)
    if n == 0
        return 0
    else if n == 1
        return 1
    else
        return Fib(n-1) + Fib(n-2)
```

#### Time complexity

- Best case: `O(1)`
- Worst case: `O(2^n)`
- Average case: `O(2^n)`
- Space complexity: `O(1)`
- Auxiliary space complexity: `O(1)`
- Sorting in place: `Yes`
- Stable: `Yes`

### [Sequential search](./sequential_search.cpp)

Sequential search is a method for finding a particular value in a list, that consists of checking every one of its elements, one at a time and in sequence, until the desired one is found.

#### Algorithm

```python
SequentialSearch(A, n, x)
    for i = 0 to n-1
        if A[i] == x
            return i
    return -1
```

#### Time complexity

- Best case: `O(1)`
- Worst case: `O(n)`
- Average case: `O(n)`
- Space complexity: `O(1)`
- Auxiliary space complexity: `O(1)`
- Sorting in place: `Yes`
- Stable: `Yes`

### [Binary iterative search](./binary_search.cpp)

Binary search is a fast search algorithm with run-time complexity of `Ο(log n)`. This search algorithm works on the principle of divide and conquer. For this algorithm to work properly, the data collection should be in the sorted form.

#### Algorithm

```python
BinarySearch(A, n, x)
    low = 0
    high = n-1
    while low <= high
        mid = (low + high) / 2
        if A[mid] == x
            return mid
        else if A[mid] < x
            low = mid + 1
        else
            high = mid - 1
    return -1
```

#### Time complexity

- Best case: `O(1)`
- Worst case: `O(log n)`
- Average case: `O(log n)`
- Space complexity: `O(1)`
- Auxiliary space complexity: `O(1)`
- Sorting in place: `Yes`
- Stable: `Yes`

### [Bubble sort](./bubble_sort.cpp)

Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
The algorithm, which is a comparison sort, is named for the way smaller or larger elements "bubble" to the top of the list.
Although the algorithm is simple, it is too slow and impractical for most problems even when compared to insertion sort.
It can be practical if the input is usually in sort order but may occasionally have some out-of-order elements nearly in position.
The complexity of bubble sort is O(n^2) in the worst and average case because the entire array needs to be iterated for every element.
However, the complexity is O(n) in the best case because the array needs to be iterated only once when the array is already sorted.
Bubble sort is adaptive. It means that for almost sorted array, it gives a good performance.
Bubble sort is stable. It means that the same element in the array will not be swapped.
Bubble sort is a comparison sort. It means that it sorts the array by comparing the elements of the array.
Bubble sort is an in-place sorting algorithm. It means that it does not require any extra space.
Bubble sort is not a recursive algorithm.

#### Algorithm

```cpp
BubbleSort(A, n)
    for i = 0 to n-1
        for j = 0 to n-i-1
            if A[j] > A[j+1]
                swap(A[j], A[j+1])
```

#### Time complexity

- Best case: `O(n)`
- Worst case: `O(n^2)`
- Average case: `O(n^2)`
- Worst case space complexity: `O(1)`
- Auxiliary space complexity: `O(1)`
- Sorting in place: `Yes`
- Stable: `Yes`

### [Selection sort](./selection_sort.cpp)

Selection sort is a sorting algorithm, specifically an in-place comparison sort. It has O(n^2) time complexity, making it inefficient on large lists, and generally performs worse than the similar insertion sort. Selection sort is noted for its simplicity and has performance advantages over more complicated algorithms in certain situations, particularly where auxiliary memory is limited.

#### Algorithm

```cpp
SelectionSort(A, n)
    for i = 0 to n-1
        min = i
        for j = i+1 to n-1
            if A[j] < A[min]
                min = j
        swap(A[i], A[min])
```

#### Time complexity

- Best case: `O(n^2)`
- Worst case: `O(n^2)`
- Average case: `O(n^2)`
- Worst case space complexity: `O(1)`
- Auxiliary space complexity: `O(1)`
- Sorting in place: `Yes`
- Stable: `No`

### [Insertion sort](./insertion_sort.cpp)

Insertion sort is a simple sorting algorithm that builds the final sorted array (or list) one item at a time.

#### Algorithm

```python
InsertionSort(A, n)
    for i = 1 to n-1
        key = A[i]
        j = i-1
        while j >= 0 and A[j] > key
            A[j+1] = A[j]
            j = j-1
        A[j+1] = key
```

#### Time complexity

- Best case: `O(n)`
- Worst case: `O(n^2)`
- Average case: `O(n^2)`
- Worst case space complexity: `O(1)`
- Auxiliary space complexity: `O(1)`
- Sorting in place: `Yes`
- Stable: `Yes`

### [Binary search with divide and conquer approach](./binary_search_divide_and_conquer.cpp)

Binary search is a fast search algorithm with run-time complexity of `Ο(log n)`. This search algorithm works on the principle of divide and conquer. For this algorithm to work properly, the data collection should be in the sorted form.

#### Algorithm

```python
BinarySearch(A, n, x)
    if n == 0
        return -1
    else
        mid = n/2
        if A[mid] == x
            return mid
        else if A[mid] < x
            return BinarySearch(A[mid+1, n], x)
        else
            return BinarySearch(A[0, mid-1], x)
```

#### Time complexity

- Best case: `O(1)`
- Worst case: `O(log n)`
- Average case: `O(log n)`
- Space complexity: `O(1)`
- Auxiliary space complexity: `O(1)`
- Sorting in place: `Yes`
- Stable: `Yes`

### [Merge sort](./merge_sort.cpp)

Merge sort is an efficient, general-purpose, comparison-based sorting algorithm. Most implementations produce a stable sort, which means that the order of equal elements is the same in the input and output. Merge sort is a divide and conquer algorithm that was invented by John von Neumann in 1945.

#### Algorithm

```python
MergeSort(A, n)
    if n < 2
        return
    mid = n/2
    left = mid
    right = n - mid
    L[left], R[right]
    for i = 0 to left-1
        L[i] = A[i]
    for i = mid to n-1
        R[i-mid] = A[i]
    MergeSort(L, left)
    MergeSort(R, right)
    Merge(A, L, left, R, right)

Merge(A, L, left, R, right)
    i = 0
    j = 0
    k = 0
    while i < left and j < right
        if L[i] <= R[j]
            A[k] = L[i]
            i = i+1
        else
            A[k] = R[j]
            j = j+1
        k = k+1
    while i < left
        A[k] = L[i]
        i = i+1
        k = k+1
    while j < right
        A[k] = R[j]
        j = j+1
        k = k+1

```

#### Time complexity

- Best case: `O(n log n)`
- Worst case: `O(n log n)`
- Average case: `O(n log n)`
- Worst case space complexity: `O(n)`
- Auxiliary space complexity: `O(n)`
- Sorting in place: `No`
- Stable: `Yes`

### [Heap sort](./heap_sort.cpp)

Heap sort is a comparison-based sorting technique based on Binary Heap data structure. It is similar to selection sort where we first find the maximum element and place the maximum element at the end. We repeat the same process for the remaining elements.

#### Algorithm

```python
HeapSort(A, n)
    for i = n/2-1 to 0
        Heapify(A, n, i)
    for i = n-1 to 0
        swap(A[0], A[i])
        Heapify(A, i, 0)

Heapify(A, n, i)
    largest = i
    l = 2*i + 1
    r = 2*i + 2
    if l < n and A[l] > A[largest]
        largest = l
    if r < n and A[r] > A[largest]
        largest = r
    if largest != i
        swap(A[i], A[largest])
        Heapify(A, n, largest)
```

#### Time complexity

- Best case: `O(n log n)`
- Worst case: `O(n log n)`
- Average case: `O(n log n)`
- Worst case space complexity: `O(1)`
- Auxiliary space complexity: `O(1)`
- Sorting in place: `Yes`
- Stable: `No`

### [Quick sort](./quick_sort.cpp)

Quicksort is an efficient sorting algorithm. Developed by British computer scientist Tony Hoare in 1959 and published in 1961, it is still a commonly used algorithm for sorting. When implemented well, it can be about two or three times faster than its main competitors, merge sort and heapsort.

#### Algorithm

```python
QuickSort(A, n)
    QuickSort(A, 0, n-1)

QuickSort(A, low, high)
    if low < high
        pi = Partition(A, low, high)
        QuickSort(A, low, pi-1)
        QuickSort(A, pi+1, high)

Partition(A, low, high)
    pivot = A[high]
    i = low-1
    for j = low to high-1
        if A[j] < pivot
            i = i+1
            swap(A[i], A[j])
    swap(A[i+1], A[high])
    return i+1
```

#### Time complexity

- Best case: `O(n log n)`
- Worst case: `O(n^2)`
- Average case: `O(n log n)`
- Worst case space complexity: `O(log n)`
- Auxiliary space complexity: `O(log n)`
- Sorting in place: `Yes`
- Stable: `No`

### [Randomized quick sort](./randomized_quick_sort.cpp)

Randomized quick sort is an efficient sorting algorithm. Developed by British computer scientist Tony Hoare in 1959 and published in 1961, it is still a commonly used algorithm for sorting. When implemented well, it can be about two or three times faster than its main competitors, merge sort and heapsort.

#### Algorithm

```c
RandomizedQuickSort(A, n)
    RandomizedQuickSort(A, 0, n-1)

RandomizedQuickSort(A, low, high)
    if low < high
        pi = RandomizedPartition(A, low, high)
        RandomizedQuickSort(A, low, pi-1)
        RandomizedQuickSort(A, pi+1, high)

RandomizedPartition(A, low, high)
    i = Random(low, high)
    swap(A[i], A[high])
    return Partition(A, low, high)
```

#### Time complexity

- Best case: `O(n log n)`
- Worst case: `O(n^2)`
- Average case: `O(n log n)`
- Worst case space complexity: `O(log n)`
- Auxiliary space complexity: `O(log n)`
- Sorting in place: `Yes`
- Stable: `No`

### [Selection problem](./selection_problem.cpp)

Selection problem is to find the kth smallest element in an unsorted array. For example, the kth smallest element in [1, 4, 3, 2, 5] is 3, and the kth smallest element in [1, -1, 2, -2, 3] is -2.

#### Algorithm

```c
SelectionProblem(A, n, k)
    if k > 0 and k <= n
        pos = RandomizedPartition(A, 0, n-1)
        if pos == k-1
            return A[pos]
        if pos > k-1
            return SelectionProblem(A, 0, pos-1, k)
        return SelectionProblem(A, pos+1, n-1, k)
    return INT_MAX
```

#### Time complexity

- Best case: `O(n)`
- Worst case: `O(n^2)`
- Average case: `O(n)`
- Worst case space complexity: `O(log n)`
- Auxiliary space complexity: `O(log n)`
- Sorting in place: `Yes`
- Stable: `No`

### [Fractional knapsack](./fractional_knapsack.cpp)

Given weights and values of n items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In the 0-1 Knapsack problem, we are not allowed to break items. We either take the whole item or don’t take it. In Fractional Knapsack, we can break items for maximizing the total value of knapsack. This problem in which we can break an item is also called the fractional knapsack problem.

#### Algorithm

```c
FractionalKnapsack(W, wt, val, n)
    for i = 0 to n-1
        ratio[i] = val[i] / wt[i]
    sort(ratio, ratio+n, greater<int>())
    for i = 0 to n-1
        if wt[i] <= W
            W = W - wt[i]
            result = result + val[i]
        else
            result = result + val[i] * (W / wt[i])
            break
    return result
```

#### Time complexity

- Best case: `O(n log n)`
- Worst case: `O(n log n)`
- Average case: `O(n log n)`
- Worst case space complexity: `O(n)`
- Auxiliary space complexity: `O(n)`
- Sorting in place: `No`

### [Job sequencing with deadlines](./job_sequencing.cpp)

Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. It is also given that every job takes a single unit of time, so the minimum possible deadline for any job is 1. How to maximize total profit if only one job can be scheduled at a time.

#### Algorithm

```c
JobSequencing(Jobs)
    sort(Jobs, Jobs+n, greater<int>())
    for i = 0 to n-1
        for j = min(n, Jobs[i].deadline)-1 to 0
            if slot[j] == false
                slot[j] = true
                result[j] = i
                break
    return result
```

#### Time complexity

- Best case: `O(n^2)`
- Worst case: `O(n^2)`
- Average case: `O(n^2)`
- Worst case space complexity: `O(n)`
- Auxiliary space complexity: `O(n)`
- Sorting in place: `No`
- Stable: `No`

### [Kruskal’s algorithm](./kruskal.cpp)

Kruskal's algorithm is a minimum-spanning-tree algorithm which finds an edge of the least possible weight that connects any two trees in the forest. It is a greedy algorithm in graph theory as it finds a minimum spanning tree for a connected weighted graph adding increasing cost arcs at each step.

#### Algorithm

```c
Kruskal(Graph)
    for each vertex v in Graph
        Make-Set(v)
    sort the edges of Graph in ascending order of weight
    for each edge (u, v) in Graph
        if Find-Set(u) != Find-Set(v)
            add (u, v) to the list of edges included in the spanning tree
            Union(u, v)
```

#### Time complexity

- Best case: `O(E log V)`
- Worst case: `O(E log V)`
- Average case: `O(E log V)`
- Worst case space complexity: `O(V)`
- Auxiliary space complexity: `O(V)`
- Sorting in place: `No`
- Stable: `No`

### [Prim’s algorithm](./prim.cpp)

Prim's algorithm is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph. This means it finds a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized.

#### Algorithm

```c
Prim(Graph)
    for each vertex v in Graph
        key[v] = INT_MAX
        parent[v] = NIL
    key[0] = 0
    Q = priority queue of all vertices
    while Q is not empty
        u = Extract-Min(Q)
        for each vertex v adjacent to u
            if v is in Q and weight(u, v) < key[v]
                parent[v] = u
                key[v] = weight(u, v)
```

#### Time complexity

- Best case: `O(E log V)`
- Worst case: `O(E log V)`
- Average case: `O(E log V)`
- Worst case space complexity: `O(V)`
- Auxiliary space complexity: `O(V)`
- Sorting in place: `No`
- Stable: `No`

### [0/1 knapsack](./knapsack.cpp)

Given weights and values of n items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In the 0-1 Knapsack problem, we are not allowed to break items. We either take the whole item or don’t take it.

#### Algorithm

```c
Knapsack(W, wt, val, n)
    if n == 0 or W == 0
        return 0
    if wt[n-1] > W
        return Knapsack(W, wt, val, n-1)
    else
        return max(val[n-1] + Knapsack(W-wt[n-1], wt, val, n-1), Knapsack(W, wt, val, n-1))
```

#### Time complexity

- Best case: `O(nW)`
- Worst case: `O(nW)`
- Average case: `O(nW)`
- Worst case space complexity: `O(nW)`
- Auxiliary space complexity: `O(nW)`
- Sorting in place: `No`
- Stable: `No`

### [Matrix chain multiplication](./matrix_chain_multiplication.cpp)

Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.

#### Algorithm

```c
MatrixChainMultiplication(p, n)
    for i = 1 to n
        m[i][i] = 0
    for L = 2 to n
        for i = 1 to n-L+1
            j = i+L-1
            m[i][j] = INT_MAX
            for k = i to j-1
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]
                if q < m[i][j]
                    m[i][j] = q
    return m[1][n-1]
```

#### Time complexity

- Best case: `O(n^3)`
- Worst case: `O(n^3)`
- Average case: `O(n^3)`
- Worst case space complexity: `O(n^2)`
- Auxiliary space complexity: `O(n^2)`
- Sorting in place: `No`
- Stable: `No`

### [String edit distance](./string_editing.cpp)

Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

- Insert
- Remove
- Replace

#### Algorithm

```c
EditDistance(str1, str2, m, n)
    if m == 0
        return n
    if n == 0
        return m
    if str1[m-1] == str2[n-1]
        return EditDistance(str1, str2, m-1, n-1)
    return 1 + min(EditDistance(str1, str2, m, n-1), EditDistance(str1, str2, m-1, n), EditDistance(str1, str2, m-1, n-1))
```

#### Time complexity

- Best case: `O(mn)`
- Worst case: `O(mn)`
- Average case: `O(mn)`
- Worst case space complexity: `O(mn)`
- Auxiliary space complexity: `O(mn)`
- Sorting in place: `No`
- Stable: `No`

### [Floyd Warshall algorithm](./floyd_warshall.cpp)

The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem. The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph. The Floyd Warshall algorithm works by successively improving an estimate on the shortest path between two vertices, until the estimate is optimal.

#### Algorithm

```c
FloydWarshall(Graph)
    for i = 0 to V-1
        for j = 0 to V-1
            dist[i][j] = graph[i][j]
    for k = 0 to V-1
        for i = 0 to V-1
            for j = 0 to V-1
                if dist[i][k] + dist[k][j] < dist[i][j]
                    dist[i][j] = dist[i][k] + dist[k][j]
```

#### Time complexity

- Best case: `O(V^3)`
- Worst case: `O(V^3)`
- Average case: `O(V^3)`
- Worst case space complexity: `O(V^2)`
- Auxiliary space complexity: `O(V^2)`
- Sorting in place: `No`
- Stable: `No`

### [Travelling salesman problem](./travelling_salesman.cpp)

Given a set of cities and distance between every pair of cities, the problem is to find the shortest possible route that visits every city exactly once and returns to the starting point. Note the difference between Hamiltonian Cycle and TSP. The Hamiltonian cycle problem is to find if there exist a tour that visits every city exactly once. Here we know that Hamiltonian Tour exists (because the graph is complete) and in fact many such tours exist, the problem is to find a minimum weight Hamiltonian Cycle.

#### Algorithm

```c
TravellingSalesmanProblem(graph, s)
    for i = 0 to V-1
        for j = 0 to V-1
            dist[i][j] = graph[i][j]
    for k = 0 to V-1
        for i = 0 to V-1
            for j = 0 to V-1
                if dist[i][k] + dist[k][j] < dist[i][j]
                    dist[i][j] = dist[i][k] + dist[k][j]
    return dist[s][0]
```

#### Time complexity

- Best case: `O(V^2 * 2^V)`
- Worst case: `O(V^2 * 2^V)`
- Average case: `O(V^2 * 2^V)`
- Worst case space complexity: `O(V * 2^V)`
- Auxiliary space complexity: `O(V * 2^V)`
- Sorting in place: `No`
- Stable: `No`

### [N-Queen problem](./n_queen.cpp)

The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other. For example, following is a solution for 4 Queen problem.

#### Algorithm

```c
NQueen(board, col)
    if col >= N
        return true
    for i = 0 to N-1
        if isSafe(board, i, col)
            board[i][col] = 1
            if NQueen(board, col+1)
                return true
            board[i][col] = 0
    return false

isSafe(board, row, col)
    for i = 0 to col-1
        if board[row][i] == 1
            return false
    for i = row, j = col
        while i >= 0 and j >= 0
            if board[i][j] == 1
                return false
            i = i-1
            j = j-1
    for i = row, j = col
        while i < N and j >= 0
            if board[i][j] == 1
                return false
            i = i+1
            j = j-1
    return true
```

#### Time complexity

- Best case: `O(n!)`
- Worst case: `O(n!)`
- Average case: `O(n!)`
- Worst case space complexity: `O(n^2)`
- Auxiliary space complexity: `O(n^2)`
- Sorting in place: `No`
- Stable: `No`

### [Subset sum problem](./subset_sum.cpp)

Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.

#### Algorithm

```c
SubsetSum(set, n, sum)
    if sum == 0
        return true
    if n == 0 and sum != 0
        return false
    if set[n-1] > sum
        return SubsetSum(set, n-1, sum)
    return SubsetSum(set, n-1, sum) or SubsetSum(set, n-1, sum-set[n-1])
```

#### Time complexity

- Best case: `O(n * sum)`
- Worst case: `O(n * sum)`
- Average case: `O(n * sum)`
- Worst case space complexity: `O(n * sum)`
- Auxiliary space complexity: `O(n * sum)`

### [Vertex cover](./vertex_cover_problem.cpp)

The vertex cover problem is the optimization problem of finding the smallest vertex cover for a given graph. A vertex cover of a graph is a set of vertices such that each edge of the graph is incident to at least one vertex of the set. A vertex cover of minimum size is called a minimum vertex cover. The vertex cover problem is a classical optimization problem in computer science and is a typical example of an NP-hard optimization problem that has an approximation algorithm.

#### Algorithm

```c
VertexCover(G)
    for each edge (u, v) in G
        if u is not in vertexCover and v is not in vertexCover
            vertexCover.add(u)
            vertexCover.add(v)
    return vertexCover
```

#### Time complexity

- Best case: `O(V + E)`
- Worst case: `O(V + E)`
- Average case: `O(V + E)`
- Worst case space complexity: `O(V + E)`
- Auxiliary space complexity: `O(V + E)`
- Sorting in place: `No`
- Stable: `No`
