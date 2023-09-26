#include "sort.h"

/**
 * lomuto_partition - Partition the array using the Lomuto scheme
 * @array: The array to be partitioned
 * @low: The starting index for the partition
 * @high: The ending index for the partition
 * @size: The size of the array
 * Return: The partition index
 */
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (array == NULL || size < 2)
		return;
	int pivot, temp;
	ssize_t i, j;

	pivot = array[high];
	i = low - 1;
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - Recursive function for Quick Sort
 * @array: The array to be sorted
 * @low: The starting index
 * @high: The ending index
 * @size: The size of the array
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t partition_index;

	if (low < high)
	{
		partition_index = lomuto_partition(array, low, high, size);
		quicksort(array, low, partition_index - 1, size);
		quicksort(array, partition_index + 1, high, size);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order
 *               using the Quick Sort algorithm (Lomuto partition scheme).
 * @array: An array of integers to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
