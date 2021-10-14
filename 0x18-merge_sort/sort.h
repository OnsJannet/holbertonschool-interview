#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>


void print_array(const int *array, size_t size);
void merge(int *arr, int *tmp, int l, int r, int m);
void merge_split(int *arr, int *tmp, int l, int r);
void merge_sort(int *arr, size_t size);

#endif
