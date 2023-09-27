#include "sort.h"

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the Counting Sort algorithm.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
    int *count_array, *output_array;
    int max = 0, i, j;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < (int)size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    count_array = malloc(sizeof(int) * (max + 1));
    if (count_array == NULL)
        return;

    output_array = malloc(sizeof(int) * size);
    if (output_array == NULL)
    {
        free(count_array);
        return;
    }

    for (i = 0; i <= max; i++)
        count_array[i] = 0;

    for (i = 0; i < (int)size; i++)
        count_array[array[i]]++;

    print_array(count_array, max + 1);

    for (i = 1; i <= max; i++)
        count_array[i] += count_array[i - 1];

    for (i = size - 1; i >= 0; i--)
    {
        output_array[count_array[array[i]] - 1] = array[i];
        count_array[array[i]]--;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = output_array[i];

    free(count_array);
    free(output_array);
}
