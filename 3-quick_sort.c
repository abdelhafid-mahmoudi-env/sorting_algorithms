#include "sort.h"

void quick_sort_recursive(int *array, ssize_t low, ssize_t high, size_t size);
ssize_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size);
void swap_int(int *a, int *b);

/**
* quick_sort - Sorts an array of integers in ascending order using quicksort.
* @array: Array to be sorted.
* @size: Size of the array.
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
* quick_sort_recursive - A recursive function to apply quicksort.
* @array: Array to be sorted.
* @low: The lowest index of the array.
* @high: The highest index of the array.
* @size: Size of the array.
*/

void quick_sort_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
		ssize_t pivot = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
* lomuto_partition - Partitions the array and sorts elements
* @array: Array to be sorted.
* @low: The lowest index of the array.
* @high: The highest index of the array.
* @size: Size of the array.
* @return: The partition index.
*/

ssize_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low - 1, j;

	for (j = low; j <= high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap_int(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	return (i);
}

/**
* swap_int - Swaps two integers in memory.
* @a: Pointer to the first integer.
* @b: Pointer to the second integer.
*/

void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
