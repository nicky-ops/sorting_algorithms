# 0x1B. C - Sorting algorithms & Big O
A <em>sorting algorithm</em> is an algorithm tha puts elements of a list into an order.
Frequently used  orders include:
* Numerical order an dlexicographical order
* Ascending or descending order

The output of any sorting algorithm must satisfy two conditions:
1. The output is in monotonic order
2. The output is a permutation

The input data should be stored in a data structure that allows random access rather than one that allows only sequential access only, for optimum efficiency.

## Classification of Sorting algorithims.
* Computational complexity
* Memory usage
* Recursion
* Whether or not they are a comparison sort
* Stability
* General method: insertion, exchange, selection, merging
* Whether algorithm is serial or parallel
* Adaptability: whether or not the presortedness of the input affects the running time.
* Online e.g Isertion sort that is online can sort a constant stream of input.

## Popular sorting algorithms
### 1. Insertion sort
A simple sorting algorithm that is relatively efficient for small lists and mostly sorted lists, and is often used as part of more sophisticated algorithms.  It works by taking elements from the list one by one and inserting them in their correct position into a new sorted list.

### 2. Selection sort
An in-place comparison sort that has 0(n^2) complexity thus making it inefficient on large lists. Performs worse than a similar insertion sort. 
The algorithm finds the minimum value, swaps it with the value in the first position, and repeats these steps for the remainder of the list.[23] It does no more than n swaps, and thus is useful where swapping is very expensive.

### 3. Merge Sort
It takes advantage of the ease of merging already sorted lists into a new sorted list.
It starts by comparing every two elements (i.e., 1 with 2, then 3 with 4...) and swapping them if the first should come after the second. It then merges each of the resulting lists of two into lists of four, then merges those lists of four, and so on; until at last two lists are merged into the final sorted list.
Merge sort scales well to very large lists, because its worst case runnign time is O(n log n). 
It is also easily applied to lists, not only arrays, as it only requires sequential access, not random access. However, it has additional O(n) space complexity, and involves a large number of copies in simple implementations.

### 4. Heapsort
Heapsort is a much more efficient version of selection sort. It also works by determining the largest (or smallest) element of the list, placing that at the end (or beginning) of the list, then continuing with the rest of the list, but accomplishes this task efficiently by using a data structure called a heap, a special type of binary tree.[29] Once the data list has been made into a heap, the root node is guaranteed to be the largest (or smallest) element. When it is removed and placed at the end of the list, the heap is rearranged so the largest element remaining moves to the root. Using the heap, finding the next largest element takes O(log n) time, instead of O(n) for a linear scan as in simple selection sort. This allows Heapsort to run in O(n log n) time, and this is also the worst case complexity.

### 5. Quicksort
It is a divide and conquer algorithm which relies on a partition operation. To partition an array, an element called a pivot is selected. 
All elements smaller than the pivot are moved before it and all greater elements are moved after it. This can be done efficiently in linear time and in-place. The lesser and greater sublists are then recursively sorted. This yields average time complexity of O(n log n), with low overhead, and thus this is a popular algorithm.
Efficient implementations of quicksort (with in-place partitioning) are typically unstable sorts and somewhat complex, but are among the fastest sorting algorithms in practice. Together with its modest O(log n) space usage, quicksort is one of the most popular sorting algorithms and is available in many standard programming libraries.

### 6. Bubble sort
A simple sorting algorithm. The algorithm starts at the beginning of the data set. It compares the first two elements, and if the first is greater than the second, it swaps them. It continues doing this for each pair of adjacent elements to the end of the data set. It then starts again with the first two elements, repeating until no swaps have occurred on the last pass. 
This algorithm's average time and worst-case performance is O(n2), so it is rarely used to sort large, unordered data sets. 
