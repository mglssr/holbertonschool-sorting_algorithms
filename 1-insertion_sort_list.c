#include "sort.h"

/**
* insertion_sort_list - function that sorts a doubly linked list of integers
* in ascending order using the Insertion sort algorithm
* @list: doubly linked list
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *new_node, *actual;

	if (list == NULL || *list == NULL)
		return;

	actual = (*list)->next;

	while (actual)
	{
		new_node = (*actual).next;
		while ((*actual).prev && (*actual).n < (*actual).prev->n)
		{
			(*actual).prev->next = (*actual).next;
			if ((*actual).next)
				(*actual).next->prev = (*actual).prev;
			(*actual).next = (*actual).prev;
			if ((*actual).next)
			{
				(*actual).prev = (*actual).next->prev;
				(*actual).next->prev = actual;
			}
			if ((*actual).prev)
				(*actual).prev->next = actual;
			else
				(*list) = actual;
			print_list(*list);
		}
		actual = new_node;
	}
}
