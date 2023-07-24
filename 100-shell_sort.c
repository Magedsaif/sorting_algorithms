#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence.
 *
 * @array: array of numbers
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap, f;

	/* Calculate initial gap using Knuth's sequence */
	gap = 1;
	while (gap < size)
		gap = (gap * 3) + 1;
	gap = (gap - 1) / 3;

	/* Start Shell sort with the calculated gap */
	while (gap > 0)
	{
		/* Perform insertion sort on sub arrays with the current gap */
		for (i = 0; i < size; i++)
		{
			for (j = i; j < size - gap; j += gap)
			{
				/* Compare and swap elements if necessary */
				if (array[j] > array[j + gap])
					swap(&array[j], &array[j + gap]);

				/* Perform insertion sort on the current sub array */
				f = j;
				while (f >= gap)
				{
					if (array[f] < array[f - gap])
						swap(&array[f], &array[f - gap]);
					f -= gap;
				}
			}
		}

		/* Reduce the gap for the next iteration */
		gap = (gap - 1) / 3;

		/* Print the current state of the array after each iteration */
		print_array(array, size);
	}
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
