#include "sort.h"

/**
 * get_max - Get the maximum element from an array.
 * @array: The array to find the maximum element from.
 * @size: The size of the array.
 * 
 * Return: The maximum element from the array.
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return (max);
}

/**
 * counting_sort_radix - Perform counting sort on an array
 *                      based on a specific digit (exp).
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @exp: The exponent representing the digit to sort.
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
    int *output, *count;
    int i;
    int max = get_max(array, size);

    count = malloc(sizeof(int) * (max + 1));
    if (count == NULL)
        return;

    output = malloc(sizeof(int) * size);
    if (output == NULL)
    {
        free(count);
        return;
    }

    for (i = 0; i <= max; i++)
        count[i] = 0;

    for (i = 0; i < (int)size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = output[i];

    print_array(array, size);

    free(count);
    free(output);
}

/**
 * radix_sort - Sort an array of integers in ascending order
 *              using the Radix Sort algorithm (LSD).
 * @array: An array of integers to sort.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
    int max = get_max(array, size);
    int exp;

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort_radix(array, size, exp);
    }
}
