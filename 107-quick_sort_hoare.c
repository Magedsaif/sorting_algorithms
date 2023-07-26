#include <stdio.h>
#include "sort.h"

/**
 * partition - apply the Quick sort algorithm on the partition.
 *
 * @array: array of numbers
 * @first: first element of the partition
 * @last: last element of the partition
 * @size: size of array
 *
 * Return: pivot index
 */
int partition(int array[], int first, int last, size_t size)
{
	int pivot, i, j;

	pivot = array[last];
	i = first - 1;
	j = last + 1;

	while (!0)
	{
		do
			i++;
		while (array[i] < pivot);

		do
			j--;
		while (array[j] > pivot);

		if (i > j)
			return (j);

		if (array[i] != array[j])
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
}

/**
 * quick_sort_hoare1 - applies the Quick sort algorithm recursively.
 *
 * @array: array of numbers
 * @first: first element of the partition
 * @last: last element of the partition
 * @size: size of array
 */
void quick_sort_hoare1(int *array, int first, int last, size_t size)
{
	int pivot_idx;

	if (first < last)
	{
		pivot_idx = partition(array, first, last, size);
		quick_sort_hoare1(array, first, pivot_idx, size);
		quick_sort_hoare1(array, pivot_idx + 1, last, size);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 *
 * @array: array of numbers
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size <= 1)
		return;

	quick_sort_hoare1(array, 0, size - 1, size);
}

/**
 * swap - swap two numbers
 *
 * @num1: first number
 * @num2: second number
 */
void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
