#include "sort.h"

void quick_sort_recursive(int *array, ssize_t low, ssize_t high);
ssize_t lomuto_partition(int *array, ssize_t low, ssize_t high);
void swap_int(int *a, int *b);

void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1);
}

void quick_sort_recursive(int *array, ssize_t low, ssize_t high)
{
    if (low < high)
    {
        ssize_t pivot = lomuto_partition(array, low, high);
        quick_sort_recursive(array, low, pivot - 1);
        quick_sort_recursive(array, pivot + 1, high);
    }
}

ssize_t lomuto_partition(int *array, ssize_t low, ssize_t high)
{
    int pivot = array[high];
    ssize_t i = low, j;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            if (i != j)
            {
                swap_int(&array[i], &array[j]);
                print_array(array, high + 1);  /* Assuming print_array is provided */
            }
            i++;
        }
    }
    if (i != high)
    {
        swap_int(&array[i], &array[high]);
        print_array(array, high + 1);  /* Assuming print_array is provided */
    }
    return i;
}

void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
