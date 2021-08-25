#include "sort.h"

/**
* _swap - swaps two integers
* @a: integer to swap
* @b: integer to swap
*/
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heapify - turns an array into a max heap
 * @arr: array of integers to heapify
 * @index: current given index within array
 * @size: size of the array
 * @len: length
 */

void heapify(int *arr, int index, int size, int len)
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int max = index;

	if (left > 0 && left < len && arr[left] > arr[max])
	{
		max = left;
	}
	if (right > 0 && right < len && arr[right] > arr[max])
	{
		max = right;
	}
	if (max != index)
	{
		swap(arr + max, arr + index);
		print_array(arr, size);
		heapify(arr, max, size, len);
	}
}


/**
 * heap_sort - sorts an array of integers in ascending order using the Heap
 * sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 */

void heap_sort(int *array, size_t size)
{
	int i = size / 2 - 1;
	int end = size - 1;

	while (i >= 0)
	{
		heapify(array, i, size, size);
		i--;
	}

	while (end > 0)
	{
		swap(array + end, array);
		print_array(array, size);
		heapify(array, 0, size, end);
		end--;
	}
}
