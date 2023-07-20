#include "sort.h"
/**
 * selection_sort - sorts an array of integers in
 * ascending order using the Selection sort algorithm
 *
 * @array: array of numbers
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_ele;
	int temp;

	for (i = 0; i < size; i++)
	{
		min_ele = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[min_ele])
			{
				min_ele = j;
			}
		}
		if (min_ele != i)
		{
			temp = array[i];
			array[i] = array[min_ele];
			array[min_ele] = temp;
			print_array(array, size);
		}
	}

}
