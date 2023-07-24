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
	int temp;

	/* Outer loop to iterate through the array elements */
	for (i = 0; i < size; i++)
	{
		flag = 0;
		/* Inner loop to perform comparisons and swaps */
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j]; /* Swap elements using a temporary variable 'temp' */
				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size); /* Print the array after each swap */
				flag = 1; /* Set 'flag' to 1 to indicate a swap occurred in this pass */
			}
		}
		/* If'flag'is still 0,the array is already sorted;break outer loop*/
		if (!flag)
			break;
	}
}
