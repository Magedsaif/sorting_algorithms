#include "sort.h"
/**
 * counting_sort - function sorts the given array of integers
 * in ascending order using the Counting Sort algorithm.
 * It is assumed that the array contains only non-negative numbers.
 *
 * @array: The array of integers to be sorted.
 * @size: The number of elements in the array.
 *
 * @return Pointer to the sorted array.
 * Returns NULL if memory allocation fails or the input array is NULL.
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int j, max_num, num;
	int *counts, *output;

	if (array == NULL || size < 2)
		return;
	max_num = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max_num)
			max_num = array[i];
	counts = malloc(sizeof(int) * (max_num + 1));
	if (counts == NULL)
		return;
	for (j = 0; j < (max_num + 1); j++)
		counts[j] = 0;
	for (i = 0; i < size; i++)
	{
		num = array[i];
		counts[num] += 1;
	}
	for (j = 0; j < max_num; j++)
		counts[j + 1] += counts[j];
	print_array(counts, max_num + 1);
	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(counts);
		return;
	}
	for (i = 0; i < size; i++)
	{
		num = array[i];
		output[counts[num] - 1] = num;
		counts[num]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
	free(counts);
}
