#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array using the counting sort algorithm
 * @array: The array to sort
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
    int *count, max = 0, *output;
    size_t i;

    if (!array || size < 2)
        return;

    /* Find the maximum value in the array */
    for (i = 0; i < size; i++)
        if (array[i] > max)
            max = array[i];

    /* Allocate memory for the counting array */
    count = malloc(sizeof(*count) * (max + 1));
    if (!count)
        return;
    for (i = 0; i <= (size_t)max; ++i)
        count[i] = 0;

    /* Store the count of each element */
    for (i = 0; i < size; i++)
        count[array[i]]++;

    /* Modify the count array */
    for (i = 0; i <= (size_t)max; i++)
    {
        if (i > 0)
            count[i] += count[i - 1];
        print_array(count, max + 1); /* Function provided to print array */
    }

    /* Build the output array */
    output = malloc(sizeof(*output) * size);
    if (!output)
    {
        free(count);
        return;
    }
    for (i = 0; i < size; i++)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    /* Copy the output array to original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
    free(count);
}
