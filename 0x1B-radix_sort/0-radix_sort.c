#include "sort.h"
/**
 * get_max - get the max value in an array
 * @array: array to get max value from
 * @size: size of array
 * Return: max value
 */

int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for ( i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * radix_sort - sort an array of integers using LSD radix sort
 * @array: array to sort
 * @size: size of array
 * Return: void
 * Description: LSD radix sort is a non-comparative integer sorting algorithm
 * that sorts data with integer keys by grouping keys by the individual digits
 * which share the same significant position and value (place value).
*/

void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	int exp;
	size_t i;
	int j;
	int *count = (int *)malloc(sizeof(int) * 10);
	int *output = (int *)malloc(sizeof(int) * size);

	for ( exp = 1; max / exp > 0; exp *= 10)
	{
		for ( j = 0; j < 10; j++)
			count[j] = 0;


		for (size_t i = 0; i < size; i++)
			count[(array[i] / exp) % 10]++;

		for ( j = 1; j < 10; j++)
			count[j] += count[j - 1];

		for (j = size - 1; j >= 0; j--)
		{
			output[count[(array[j] / exp) % 10] - 1] = array[j];
			count[(array[j] / exp) % 10]--;
		}

		for ( i = 0; i < size; i++)
			array[i] = output[i];


		for ( i = 0; i < size; i++)
			if (i == size - 1)
				printf("%d", array[i]);
			else
				printf("%d, ", array[i]);
		printf("\n");
	}

	free(count);
	free(output);
}
