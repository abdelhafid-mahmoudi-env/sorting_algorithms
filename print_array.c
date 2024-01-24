#include <stdio.h>
#include "sort.h"

/**
* print_array - prints an array of integers
* @array: The array to be printed
* @size: The number of elements in the array
*
* Description: Prints elements of array of integers followed by a new line.
* Each element separated by comma andspace, with no trailing comma at the end.
*/
void print_array(const int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
