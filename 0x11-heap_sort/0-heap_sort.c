#include "sort.h"
/**
 * swap - swap element
 * @a: first elemnt
 * @b: seconde element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort
 * @array: the array to be sorted
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i, last;

	if (size < 2)
		return;
	last = size - 1;
	for (i = (last - 1) / 2; i >= 0; i--)
		heap(array, size, i, last);
	for (i = last; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		heap(array, size, 0, i - 1);
	}
}

/**
 * heap - heap sort
 * @array: the array to be sorted
 * @size: size of the array
 * @parent: parent
 * @last: last
 * Return: void
 */
void heap(int *array, int size, int parent, int last)
{
	int left, right, max;

	left = 2 * parent + 1;
	right = 2 * parent + 2;
	max = parent;
	if (left <= last && array[left] > array[max])
		max = left;
	if (right <= last && array[right] > array[max])
		max = right;
	if (max != parent)
	{
		swap(&array[parent], &array[max]);
		heap(array, size, max, last);
	}
}
