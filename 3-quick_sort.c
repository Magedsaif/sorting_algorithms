#include <stdio.h>
#include "sort.h"

/**
 * partition - apply the Quick sort algorithm on the partition.
 *
 * @arr: array of numbers
 * @first: first element of the partition
 * @last: last element of the partition
 * @size: size of array
 *
 * Return: pivot index
 */
int partition(int arr[], int first, int last, size_t size)
{
	int pivot, i, j;

	/* Choose the pivot element (last element of the partition) */
	pivot = arr[last];
	i = (first - 1);

	/* Loop to traverse through the partition */
	for (j = first; j <= last - 1; j++)
	{
		if (arr[j] < pivot) /* If the current element is less than the pivot */
		{
			i++;
			/* Swap to move the smaller element to the left */
			swap(&arr[i], &arr[j]);
			if (i != j)
				print_array(arr, size); /* Print the array after each swap */
		}
	}
	/* Swap the pivot element to its correct position */
	if (arr[i + 1] != arr[last])
	{
		swap(&(arr[i + 1]), &(arr[last]));
		print_array(arr, size);
	}
	return (i + 1); /* Return the index of the pivot element */
}

/**
 * quick_sort1 - applies the Quick sort algorithm recursively.
 *
 * @array: array of numbers
 * @first: first element of the partition
 * @last: last element of the partition
 * @size: size of array
 */
void quick_sort1(int *array, int first, int last, size_t size)
{
	int pivot_idx;

	if (first < last) /* If there is more than one element in the partition */
	{
		/* Get the pivot index from the partition step */
		pivot_idx = partition(array, first, last, size);
		/* Recursively sort the elements to the left of the pivot */
		quick_sort1(array, first, pivot_idx - 1, size);
		/* Recursively sort the elements to the right of the pivot */
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
	/* Base case: if the array has 1 or 0 elements, it is already sorted */
	if (size <= 1)
		return;
	/* Call the helper function to perform Quick sort */
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
