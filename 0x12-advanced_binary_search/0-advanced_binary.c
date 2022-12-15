#include"search_algos.h"
#include <stddef.h>

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is located
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i, a, index = 0;
	int temp;

	if (array == NULL)
		return (-1);
	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		if (i == size - 1)
			printf("%d\n", array[i]);
		else
			printf("%d, ", array[i]);
	}
	if (size == 1 && array[0] != value)
		return (-1);
	a = (size - 1) / 2;
	if (array[a] == value)
	{
		if (array[a - 1] == value)
		{
			index = advanced_binary(array, a + 1, value);
			return (index);
		}
		return (a);
	}
	if (array[a] > value)
	{
		index = advanced_binary(array, a + 1, value);
		return (index);
	}
	if (array[a] < value)
	{
		temp = advanced_binary(array + a + 1, size - a - 1, value);
		if (temp == -1)
			return (-1);
		return (a + 1 + temp);
	}
	return (-1);
}
