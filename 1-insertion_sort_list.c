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

	/* If the list is empty or contains only one node, no need to sort */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr1 = (*list)->next; /* Initialize curr1 to the second node */

	while (curr1) /* Outer loop to traverse through the list */
	{
		curr2 = curr1; /* Initialize curr2 to the current node */
		/* Inner loop for the insertion sort */
		while (curr2 != *list && curr2->n < curr2->prev->n)
		{
			temp = curr2->prev; /* Save the previous node as temp */

			/* Swap the nodes using their prev and next pointers */
			curr2->prev = temp->prev;
			if (temp->prev)
				temp->prev->next = curr2;
			temp->next = curr2->next;
			if (curr2->next)
				curr2->next->prev = temp;

			curr2->next = temp;
			temp->prev = curr2;
			/* Update the head of the list if curr2 is now the new head */
			if (!curr2->prev)
				*list = curr2;

			print_list(*list); /* Print the updated list after each swap */
			/* Move curr2 one step back for further comparisons */
			curr2 = temp->prev;
		}

		curr1 = curr1->next; /* Move to the next node for the next iteration */
	}
}
