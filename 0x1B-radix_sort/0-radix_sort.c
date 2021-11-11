#include "sort.h"

/**
 * find_max - finds max key in array
 * @array: array to be sorted
 * @size: size of array
 * Return: max value
 */
int find_max(int *array, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * radix_count - Sort the array digitit by digitit depending on digit
 * @array: Array that will be sorted
 * @size: Size of @array
 * @digit: Integer by which array[i] will be divided to find specific digit.
 * Return: nothing
 */

void radix_count(int *array, int size, int digit)
{
	int i, *output, count[10] = {0};

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / digit) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / digit) % 10] - 1] = array[i];
		count[(array[i] / digit) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the LSD
 * radix sort algorithm
 * @array: Array to be sorted
 * @size: Size of @array
 * Return: nothing
 */

void radix_sort(int *array, size_t size)
{
	int max, digitit;

	if (!array || size <= 1)
		return;

	max = find_max(array, size);
	for (digitit = 1; max / digitit > 0; digitit *= 10)
	{
		radix_count(array, size, digitit);
		print_array(array, size);
	}
}
