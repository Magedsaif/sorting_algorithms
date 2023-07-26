#include "sort.h"

/**
 * count_occurrences - Counts the occurrences of each number in the array
 *
 * @array: The input array
 * @size: Number of elements in @array
 * @max_num: Pointer to store the maximum number in the array
 *
 * Return: The counting array
 */
int *count_occurrences(int *array, size_t size, int *max_num)
{
	int i;
	int *counts;

	*max_num = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > *max_num)
			*max_num = array[i];
	}

	counts = (int *)malloc(sizeof(int) * (*max_num + 1));
	if (counts == NULL)
		return (NULL);

	for (i = 0; i < (*max_num + 1); i++)
		counts[i] = 0;

	for (i = 0; i < (int)size; i++)
	{
		counts[array[i]] += 1;
	}
	print_array(counts, *max_num + 1);
	return (counts);
}
/**
 * rearrange_elements - Rearranges the elements in
 * the original array based on the counting array
 *
 * @array: The original array
 * @counts: The counting array
 * @size: Number of elements in @array
 */
void rearrange_elements(int *array, int *counts, size_t size)
{
	int i, num;

	int *output = (int *)malloc(sizeof(int) * size);

	if (output == NULL)
	{
		free(counts);
		return;
	}

	for (i = (int)size - 1; i >= 0; i--)
	{
		num = array[i];
		output[counts[num] - 1] = num;
		counts[num]--;
	}

	for (i = 0; i < (int)size; i++)
	{
		array[i] = output[i];
	}

	free(output);
	free(counts);
}

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
	int max_num, j;
	int *counts;

	if (array == NULL || size < 2)
		return;
	counts = count_occurrences(array, size, &max_num);

	if (counts == NULL)
		return;

	for (j = 1; j <= max_num; j++)
		counts[j] += counts[j - 1];

	rearrange_elements(array, counts, size);
}

