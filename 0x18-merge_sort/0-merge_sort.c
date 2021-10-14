#include "sort.h"


/**
 * merge_sort - sorts an arr by implementing top down merge sort.
 * @arr: arr
 * @size: size of the arr
 */
void merge_sort(int *arr, size_t size)
{
	int *tmp;
	size_t i = 0;

	if (!arr || size < 2)
		return;

	tmp = malloc(size * sizeof(int));
	if (!tmp)
		return;
	for (; i < size; i++)
	{
		tmp[i] = arr[i];
	}

	merge_split(arr, tmp, 0, size);
	free(tmp);
}

/**
 * merge_split - splits an array
 * @arr: arr to sort
 * @tmp: tmp of the arr to sort
 * @l: beginning of arr;
 * @r: end of arr;
 */
void merge_split(int *arr, int *tmp, int l, int r)
{
	int m = l + (r - l) / 2;

	if (r - l <= 1)
	{
		return;
	}

	merge_split(tmp, arr, l, m);
	merge_split(tmp, arr, m, r);
	merge(arr, tmp, l, r, m);
}

/**
 * merge - merges two arrays
 * @arr: array
 * @tmp: tmp of the arr
 * @l: beginning of arr;
 * @r: end of arr;
 * @m: mid
 */
void merge(int *arr, int *tmp, int l, int r, int m)
{
	int start, end, i = l;

	start = l;
	end = m;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(tmp + l, m - l);
	printf("[right]: ");
	print_array(tmp + m, r - m);

	while (start < m && end < r)
	{
		if (tmp[start] < tmp[end])
		{
			arr[i] = tmp[start];
			start++;
		}
		else
		{
			arr[i] = tmp[end];
			end++;
		}
	i++;
	}
	while (start < m)
	{
		arr[i] = tmp[start];
		i++;
		start++;
	}
	while (end <= r)
	{
		arr[i] = tmp[end];
		i++;
		end++;
	}
	printf("[Done]: ");
	print_array(arr + l, r - l);
}
