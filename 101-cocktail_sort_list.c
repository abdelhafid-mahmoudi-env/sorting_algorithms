#include "sort.h"

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);

/**
* cocktail_sort_list - Sorts doubly linked list of integers in ascending order
* using the Cocktail shaker sort algorithm.
* @list: Double pointer to the head of the doubly linked list.
*/
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		current = *list;

		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		current = current->prev;
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}
}

/**
* swap_nodes - Swaps two adjacent nodes in a doubly linked list.
* @list: Double pointer to the head of the doubly linked list.
* @node1: Pointer to the first node to swap.
* @node2: Pointer to the second node to swap.
*/
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *temp_prev, *temp_next;

	if (*list == node1)
		*list = node2;
	else if (*list == node2)
		*list = node1;
	temp_prev = node1->prev;
	node1->prev = node2->prev;
	node2->prev = temp_prev;
	if (node1->prev != NULL)
		node1->prev->next = node1;
	if (node2->prev != NULL)
		node2->prev->next = node2;
	temp_next = node1->next;
	node1->next = node2->next;
	node2->next = temp_next;
	if (node1->next != NULL)
		node1->next->prev = node1;
	if (node2->next != NULL)
		node2->next->prev = node2;
}
