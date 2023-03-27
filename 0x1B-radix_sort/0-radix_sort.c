#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: the array to sort contain only numbers >= 0
 * @size: size of the array to sort
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	int i, max;

	if (size < 2)
		return;
	max = get_max(array, size);
	for (i = 1; max / i > 0; i *= 10)
	{
		count(array, size, i);
		print_array(array, size);
	}
}

/**
 * get_max - gets the max number in an array
 * @array: the array to search
 * @size: size of the array
 * Return: the biggest number in the array
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * count - counting sort of the array
 * @array: the array to sort
 * @size: size of the array
 * @dig: digit to count around
 * Return: Nothing
 */
void count(int *array, int size, int dig)
{
	int *result = malloc(sizeof(int) * size);
	int i;
	int count[10] = {0};

	if (!result)
		return;
	for (i = 0; i < size; i++)
		count[(array[i] / dig) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		result[count[(array[i] / dig) % 10] - 1] = array[i];
		count[(array[i] / dig) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = result[i];
	free(result);
}
