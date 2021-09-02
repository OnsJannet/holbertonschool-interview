#include "search_algos.h"

/**
 * recursiveBinary - A function that
 * implement binary search using recursive call
 * @array: array to be searched its value
 * @start_index: beginning of array
 * @end_index: end of array
 * @element: value to be searched
 * Return: index of value or -1
 */

int recursiveBinary(int array[], int start_index, int end_index, int element)
{
	if (end_index >= start_index)
	{
		int middle = start_index + (end_index - start_index) / 2;

		print_array(array, start_index, end_index);
		if (array[middle] == element)
		{
			if (array[middle - 1] == element)
				return (recursiveBinary(array, start_index, middle, element));
			return (middle);
		}
		if (array[middle] > element)
			return (recursiveBinary(array, start_index, middle - 1, element));
		return (recursiveBinary(array, middle + 1, end_index, element));
	}
	return (-1);
}

/**
 * advanced_binary - Calls recursiveBinary
 * @array: the array of the value
 * @size: size
 * @value: value
 * Return: index of the value or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (recursiveBinary(array, 0, size - 1, value));
}
