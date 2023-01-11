#include "holberton.h"
/**
 * mul - multiplies two integers
 * @num1: first integer
 * @num2: second integer
 *
 * Return: product of num1 and num2
 */
int mul(int num1, int num2)
{
	return (num1 * num2);
}

/**
* is_valid_number - checks if a string is a valid number
* @num: string to check
* Return: 1 if valid, 0 otherwise
*/

int is_valid_number(char *num)
{
	int len = strlen(num);

	for (int i = 0; i < len; i++)
	{
		if (!isdigit(num[i]))
		{
			return (0);
		}
	}
	return (1);
}

/**
* main - multiplies two positive numbers
* @argc: number of arguments
* @argv: array of arguments
* Return: 0 on success, 98 on error
*/

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	if (!is_valid_number(argv[1]) || !is_valid_number(argv[2]))
	{
		printf("Error\n");
		return (98);
	}

	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[2]);
	int result = mul(num1, num2);

	int digits[10];
	int num_digits = 0;

	while (result > 0)
	{
		digits[num_digits++] = result % 10;
		result /= 10;
	}

	for (int i = num_digits - 1; i >= 0; i--)
	{
		putchar('0' + digits[i]);
	}
	putchar('\n');

	return (0);
}
