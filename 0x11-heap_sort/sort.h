#ifndef _SORT_H
#define _SORT_H
#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void heapify(int arr[], int n, int i);
void swap(int *a, int *b);
#endif
