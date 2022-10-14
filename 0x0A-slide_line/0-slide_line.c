#include "slide_line.h"

/**
 * swap - swap two integers
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
    int tmp = *a;

    *a = *b;
    *b = tmp;
}

/**
 * slide_left - slide all non-zero elements to the left
 * @line: array of integers
 * @size: size of the array
 */
void slide_left(int *line, size_t size)
{
    size_t i, j = 0;

    for (i = 0; i < size && j < size; i++)
    {
        while (line[j] == 0 && j < size && j + 1 < size)
            j++;
        if (line[i] == 0)
            swap(&line[i], &line[j]);
        j++;
    }
}

/**
 * slide_right - slide all non-zero elements to the right
 * @line: array of integers
 * @size: size of the array
 */
void slide_right(int *line, size_t size)
{
    size_t i, j;

    for (i = size - 1; i >= 0 && j >= 0; i--)
    {
        while (line[j] == 0 && j >= 0 && j - 1 >= 0)
            j--;
        if (line[i] == 0)
            swap(&line[i], &line[j]);
        j--;
    }
    }

/**
 * slide_line - slides and merges an array of integers
 * @line: array of integers
 * @size: size of the array
 * @direction: direction to slide the array
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i;

    if (line == NULL || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return (0);

    if (direction == SLIDE_LEFT)
        slide_left(line, size);
    else
        slide_right(line, size);

    for (i = 0; i < size - 1; i++)
    {
        if (line[i] == line[i + 1])
        {
            line[i] += line[i + 1];
            line[i + 1] = 0;
            if (direction == SLIDE_LEFT)
                slide_left(line, size);
            else
                slide_right(line, size);
        }
    }

    return (1);
}