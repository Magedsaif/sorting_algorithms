#include <stdlib.h>
#include <stdio.h>

/**
 * swap - swap two numbers
 *
 * @array: array of numbers.
 * @idx1: first index
 * @idx2: second index
 * Return: array
 */
int *swap(int array[], int idx1, int idx2)
{
	int temp = 0;

	temp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = temp;

	return (array);
}
