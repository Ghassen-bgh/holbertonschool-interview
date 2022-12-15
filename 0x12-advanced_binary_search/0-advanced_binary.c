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
    size_t i, mid, left, right;

    if (array == NULL || size == 0)
        return (-1);

    left = 0;
    right = size - 1;
    printf("Searching in array: ");
    for (i = left; i < right; i++)
        printf("%d, ", array[i]);
    printf("%d\n", array[i]);

    if (left == right)
    {
        if (array[left] == value)
            return (left);
        else
            return (-1);
    }

    mid = (left + right) / 2;
    if (array[mid] >= value)
        return (advanced_binary(array + left, mid + 1, value));
    else
        return (advanced_binary(array + mid + 1, right - mid, value) + mid + 1);
}
