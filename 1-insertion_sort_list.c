#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 *
 * @array: array of numbers
 * @size: size of array
 */

void insertion_sort_list(listint_t **list)
{
    listint_t *curr1 = (*list)->next;
    listint_t *curr2;
    listint_t *temp;

    while (curr1)
    {
        curr2 = curr1;
        while (curr2 != *list && curr2->n < curr2->prev->n)
        {
            temp = curr2->prev;
            curr2->prev = temp->prev;
            temp->next = curr2->next;
            if (temp->prev)
                temp->prev->next = curr2;
            curr2->next = temp;
            temp->prev = curr2;

            if (!curr2->prev)
                *list = curr2;

            print_list(*list);
            curr2 = temp;
        }
        curr1 = curr1->next;
    }
}
