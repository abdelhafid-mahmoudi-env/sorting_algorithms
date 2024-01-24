#include "sort.h"

/**
* shell_sort - Sorts an array of integers in ascending order
* using the Shell sort algorithm with Knuth sequence.
* @array: Array of integers to sort.
* @size: Size of the array.
*/
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	for (gap = 1; gap < size; gap = gap * 3 + 1)
		;
	while (gap > 1)
	{
		gap = (gap - 1) / 3;
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
