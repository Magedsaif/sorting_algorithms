#include <stdio.h>
#include "sort.h"
/**
 * partition - apply the Quick sort algorithm on the partition.
 *
 * @arr: array of numbers
 * @first: first element of the partition
 * @last: last element of the partition
 * @size: size of array
 * Return: pivot index
 */

int partition(int arr[], int first, int last, size_t size)
{
	int pivot, i, j;

	pivot = arr[last];
	i = (first - 1);

	for (j = first; j <= last - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
			if (i != j)
				print_array(arr, size);
		}
	}
	if (arr[i + 1] != arr[last])
	{
		swap(&(arr[i + 1]), &(arr[last]));
		print_array(arr, size);
	}
	return (i + 1);
}
/**
 * quick_sort1 - .
 *
 * @array: array of numbers
 * @first: first element of the partition
 * @last: last element of the partition
 * @size: size of array
 */

void quick_sort1(int *array, int first, int last, size_t size)
{

	int pivot_idx;

	if (first < last)
	{
		pivot_idx = partition(array, first, last, size);
		quick_sort1(array, first, pivot_idx - 1, size);
		quick_sort1(array, pivot_idx + 1, last, size);
	}
}
/**
 * quick_sort - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 *
 * @array: array of numbers
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (size <= 1)
		return;

	quick_sort1(array, 0, size - 1, size);
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
