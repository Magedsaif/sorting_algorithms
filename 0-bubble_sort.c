#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 *
 * @array: array of numbers
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, flag;

	for (i = 0; i < size; i++)
	{
		flag = 0;
		for (j = 0; j < size - i; j++)
		{
			if (array[j] > array[j + 1])
			{

				array = swap(array, j, j + 1);

				print_array(array, size);
				flag = 1;
			}
		}

		if (!flag)
			break;
	}
}
