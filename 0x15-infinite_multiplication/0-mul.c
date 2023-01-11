#include "holberton.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * mul - multiplies two integers
 * @num1: first integer
 * @num2: second integer
 *
 * Return: product of num1 and num2
 */
int mul(int *num1, int *num2)
{
	int i, j;
	int len1, len2, sum, n1, n2 = 0;
	int *res;

	len1 = strlen(num1);
	len2 = strlen(num2);

	res = calloc(len1 + len2, sizeof(len1 + len2));
	if (res == NULL)
		return (0);

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		n2 = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = n1 * n2 + res[i + j + 1];
			res[i + j + 1] = sum % 10;
			res[i + j] += sum / 10;
		}
	}
	print_num(res, len1 + len2);
	free(res);
	return (1);
}

/**
 * print_num - prints an array of integers like a number
 * @res: array of integers
 * @size: size of the array of integers
 */

void print_num(int *res, int size)
{
	int i = 0;

	if (!res && !size)
	{
		printf("0\n");
		return;
	}
	while (res[i] == 0)
		i++;
	for (; i < size; i++)
		printf("%d", res[i]);
	printf("\n");
}

/**
* main - multiplies two positive numbers
* @argc: number of arguments
* @argv: array of arguments
* Return: 0 on success, 98 on error
*/

int main(int argc, char **argv)
{
	int i, j = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	for (i = 1; argv[i]; i++)
	{
		for (j = 0; argv[i][j]; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				exit(98);
			}
		}
	}
	if (*argv[1] == '0' || *argv[2] == '0')

		print_num(NULL, 0);
	if (!mul(argv[1], argv[2]))
	{
		printf("Error\n");
		exit(98);
	}
	return (0);
}
