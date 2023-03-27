#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
int get_max(int *array, size_t size);
void count(int *array, int size, int dig);

#endif