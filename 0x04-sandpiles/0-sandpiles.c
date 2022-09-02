#include "sandpiles.h"

/**
 * verify_grid - Verify if grid is valid
 * grid: 3x3 grid
 * Return: 1 if valid, 0 if not
 */


int verify_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] < 0)
			{
				return (0);
			}
		}
	}
	return (1);
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * copy_grid - Copy grid to another grid
 * @src: 3x3 grid
 * @dest: 3x3 grid
 */
void copy_grid(int src[3][3], int dest[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			dest[i][j] = src[i][j];
		}
	}
}

/**
 * sandpiles_sum - Sum two 3x3 grids
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int x, y;
	int grid3[3][3];
	int type = 0;

	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			grid1[x][y] = grid1[x][y] + grid2[x][y];
	type = verify_grid(grid1);
	if (type == 0)
	{
		printf("=\n");
		print_grid(grid1);
	}
	while (type == 0)
	{
		copy_grid(grid1, grid3);
		for (x = 0; x < 3; x++)
		{
			for (y = 0; y < 3; y++)
			{
				if (grid3[x][y] > 3)
				{
					grid1[x][y] = grid1[x][y] - 4;
					if (x - 1 >= 0)
						grid1[x - 1][y] = grid1[x - 1][y] + 1;
					if (x + 1 < 3)
						grid1[x + 1][y] = grid1[x + 1][y] + 1;
					if (y - 1 >= 0)
						grid1[x][y - 1] = grid1[x][y - 1] + 1;
					if (y + 1 < 3)
						grid1[x][y + 1] = grid1[x][y + 1] + 1;
				}
			}
		}
			type = verify_grid(grid1);
			if (type == 1)
				break;
			printf("=\n");
			print_grid(grid1);
	}
}
