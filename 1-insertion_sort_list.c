#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm.
 *
 * @list: list of numbers
 */

void insertion_sort_list(listint_t **list)
{

	listint_t *curr1, *temp, *curr2;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	curr1 = (*list)->next;
	while (curr1)
	{
		curr2 = curr1;
		while (curr2 != *list && curr2->n < curr2->prev->n)
		{
			temp = curr2->prev;

			curr2->prev = temp->prev;
			if (temp->prev)
				temp->prev->next = curr2;
			temp->next = curr2->next;
			if (curr2->next)
				curr2->next->prev = temp;

			curr2->next = temp;
			temp->prev = curr2;

			if (!curr2->prev)
				*list = curr2;

			print_list(*list);
			curr2 = temp->prev;
		}
		curr1 = curr1->next;
	}
}
