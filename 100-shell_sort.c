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

	gap = 1;
	while (gap < size)
		gap = (gap * 3) + 1;
	gap = (gap - 1) / 3;
	while (gap > 0)
	{
		for (i = 0; i < size; i++)
		{
			for (j = i; j < size - gap; j += gap)
			{
				if (array[j] > array[j + gap])
					swap(&array[j], &array[j + gap]);
				f = j;
				while (f > gap)
				{
					if (array[f] < array[f - gap])
						swap(&array[f], &array[f - gap]);
					f -= gap;
				}
			}
		}
		gap = (gap - 1) / 3;
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
