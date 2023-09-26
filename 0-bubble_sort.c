#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order
 * using Bubble sort algorithm
 * @array: pointer to an array of integers
 * @size: array size
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
        int temp;
        size_t j, i;

        if (array == NULL || size < 2)
                return;
        for (i = 0; i < size - 1; i++)
        {
                for (j = 0; j < size - 1; j++)
                {
                        if (array[j]> array[j + 1])
                        {
                                temp = array[j];
                                array[j] = array[j + 1];
                                array[j + 1] = temp;
                        }
                }
                printf("%lu:", i + 1);
                for (j = 0; j < size; j++)
                {
                        printf("%d", array[j]);
                        if (j < size - 1)
                        {
                                printf(", ");
                        }
                }
                printf("\n");
        }
}
