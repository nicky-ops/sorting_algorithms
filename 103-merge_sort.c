#include "sort.h"

/**
 * merge - Merge two subarrays of the array.
 * @array: The array to be sorted.
 * @left: The left subarray to merge.
 * @right: The right subarray to merge.
 * @size: The size of the array.
 */
void merge(int *array, int *left, int *right, size_t size)
{
    int *tmp;
    size_t i = 0, j = 0, k = 0;
    size_t size_left = size / 2;
    size_t size_right = size - size_left;

    printf("Merging...\n[left]: ");
    print_array(left, size_left);
    printf("[right]: ");
    print_array(right, size_right);

    tmp = malloc(sizeof(int) * size);
    if (tmp == NULL)
        return;

    while (i < size_left && j < size_right)
    {
        if (left[i] <= right[j])
            tmp[k++] = left[i++];
        else
            tmp[k++] = right[j++];
    }

    while (i < size_left)
        tmp[k++] = left[i++];

    while (j < size_right)
        tmp[k++] = right[j++];

    for (i = 0; i < size; i++)
        array[i] = tmp[i];

    printf("[Done]: ");
    print_array(array, size);

    free(tmp);
}

/**
 * merge_sort - Sort an array of integers in ascending order
 *              using the Merge Sort algorithm (top-down).
 * @array: An array of integers to sort.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    if (size > 1)
    {
        size_t mid = size / 2;
        int *left = array;
        int *right = array + mid;

        merge_sort(left, mid);
        merge_sort(right, size - mid);
        merge(array, left, right, size);
    }
}
