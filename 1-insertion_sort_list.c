#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;

    if (list == NULL || (*list) == NULL || (*list)->next == NULL)
        return;

    for (current = (*list)->next; current != NULL; current = current->next)
    {
        for (temp = current; temp->prev != NULL && temp->n < temp->prev->n;)
        {
            temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            temp->next = temp->prev;
            temp->prev = temp->next->prev;
            temp->next->prev = temp;

            if (temp->prev != NULL)
                temp->prev->next = temp;
            else
                *list = temp;

            print_list(*list);
            temp = temp->prev;
        }
    }
}
