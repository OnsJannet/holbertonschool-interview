#include "sort.h"

/**
* swap - swaps two integers
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
 * @n: current given index within array
 * @i: size of the array
 */
void heapify(int arr[], int n, int i)
{
	int max = i;
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;


	if (leftChild < n && arr[leftChild] > arr[max])
		max = leftChild;


	if (rightChild < n && arr[rightChild] > arr[max])
		max = rightChild;


	if (max != i)
	{
		swap(&arr[i], &arr[max]);
		heapify(arr, n, max);
	}
}

/**
 * heap_sort - sorts an array of integers
 * in ascending order using the Heap
 * sort algorithm
 * @array: pointer to array
 * @size: size of the pointer
 *
 **/

void heap_sort(int *array, size_t size)

{
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i);

	for (int i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0);
	}
}
