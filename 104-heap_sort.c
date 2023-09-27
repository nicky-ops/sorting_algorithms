#include "sort.h"

/**
 * sift_down - Restore the heap property of a subtree.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @root: The root of the subtree.
 * @end: The end of the heap.
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
    size_t largest = root;
    size_t left_child = 2 * root + 1;
    size_t right_child = 2 * root + 2;

    if (left_child < end && array[left_child] > array[largest])
        largest = left_child;

    if (right_child < end && array[right_child] > array[largest])
        largest = right_child;

    if (largest != root)
    {
        int temp = array[root];
        array[root] = array[largest];
        array[largest] = temp;
        print_array(array, size);
        sift_down(array, size, largest, end);
    }
}

/**
 * heap_sort - Sort an array of integers in ascending order
 *             using the Heap Sort algorithm (sift-down).
 * @array: An array of integers to sort.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    for (int i = (size / 2) - 1; i >= 0; i--)
        sift_down(array, size, (size_t)i, size);

    for (int i = size - 1; i > 0; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        print_array(array, size);
        sift_down(array, size, 0, (size_t)i);
    }
}
