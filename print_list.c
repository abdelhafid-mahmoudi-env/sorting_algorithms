#include "sort.h"
#include <stdio.h>

/**
* print_list - Prints the elements of a doubly linked list
* @list: The list to be printed
*/
void print_list(const listint_t *list)
{
	int i = 0;

	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
}
