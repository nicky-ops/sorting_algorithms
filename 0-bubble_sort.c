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
	int temp, swp;
	size_t j, i, k;

	if (array == NULL || size < 2)
		return;
	if (array)
	{
		for (i = 0; i < size - 1; i++)
		{
			swp = 0;
			for (j = 0; j < size -1; j++)
			{
				if (array[j]> array[j + 1])
				{
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					for (k = 0; k < size; k++)
					{
						printf("%d", array[k]);
					}
					swp = 1;
				}
			}
		}
	}
}
