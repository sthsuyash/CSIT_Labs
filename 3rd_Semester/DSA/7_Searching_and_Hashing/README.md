# Searching and Hashing Algorithms

## Programs

1. Searching

   - [Linear Search](linear_search.cpp)
   - [Binary Search](binary_search.cpp)

2. Hashing

   - [Hashing](hashing.cpp)

## Searching

Searching is the process of finding a particular item in a collection of items. Every item is called a key and the process of finding a key is called searching.

1. ## Linear Search

   Linear search is a very simple search algorithm. In this type of search, a sequential search is made over all items one by one. Every item is checked and if a match is found then that particular item is returned, otherwise the search continues till the end of the data collection.

   -Algorithm:

   1. Run a for loop to traverse the input array using a variable i, such that 0 ≤ i < n
   2. If arr[i] is equal to the key, then return i
   3. If the key is not found, then return -1

   - Time Complexity: O(N)
   - Auxiliary Space: O(1)

2. ## Binary Search

   Binary search is a search algorithm that finds the position of a target value within a sorted array.

   Binary search compares the target value to the middle element of the array. If they are not equal, the half in which the target cannot lie is eliminated and the search continues on the remaining half, again taking the middle element to compare to the target value, and repeating this until the target value is found. If the search ends with the remaining half being empty, the target is not in the array.

   - Algorithm:

     1. Run a while loop to traverse the input array using two variables low and high, such that low ≤ high
     2. Find the middle element mid = (low + high) / 2
     3. If arr[mid] is equal to the key, then return mid
     4. If arr[mid] is greater than the key, then high = mid - 1
     5. If arr[mid] is less than the key, then low = mid + 1
     6. If the key is not found, then return -1

   - Time Complexity: O(logN)
   - Auxiliary Space: O(1)

## Hashing

Hashing is a technique to convert a range of key values into a range of indexes of an array. The idea is to use a hash function that converts a given key to a smaller number and uses the small number as an index in a table called hash table.

- Follow the below steps to solve the problem:

  1. Run a for loop to traverse the input array using a variable i, such that 0 ≤ i < n
  2. Find the hash value of arr[i] using the hash function
  3. Insert arr[i] into the hash table at the index hash_value
  4. Run a for loop to traverse the input array using a variable i, such that 0 ≤ i < n
  5. Find the hash value of arr[i] using the hash function
  6. If arr[i] is present in the hash table at the index hash_value, then return true
  7. If the key is not found, then return false

Time Complexity: O(N)

Auxiliary Space: O(N)
