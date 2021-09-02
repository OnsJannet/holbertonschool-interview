#include "search_algos.h"

/**
 * print_array - Print array or subarray
 * @array: array to be printed
 * @start_index: beginning of array
 * @end_index: end of  array
 */

void print_array(int *array, int start_index, int end_index)
{
	int i;

	printf("Searching in array: ");
	for (i = start_index; i <= end_index; i++)
	{
		if (i != start_index)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
