#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);
listint_t *create_listint(const int *array, size_t size);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *num1, int *num2);
int partition(int arr[], int first, int last, size_t size);
void quick_sort1(int *array, int first, int last, size_t size);
void quick_sort_hoare1(int *array, int first, int last, size_t size);
void shell_sort(int *array, size_t size);
listint_t *get_last_node(listint_t *list);
listint_t *swap_list(listint_t *list, listint_t *curr2);
void cocktail_sort_list(listint_t **list);
int calc_list_size(listint_t *list);
void counting_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
#endif
