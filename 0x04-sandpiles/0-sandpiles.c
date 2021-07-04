#include "sandpiles.h"

/**
 * print_grid - print a grid
 * @grid: sandpile
 *
 * Return: nothing
 */
void print_grid(int grid[3][3])
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
 * non_stable - checks the stabilty of the grid
 * @grid1: sandpile
 *
 * Return: 1 if it is unstable or 0 if not
 */
int non_stable(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				return (1);
		}
	}
	return (0);
}

/**
 * copy - copy a grid in another one
 * @grid1: first sandpile
 * @grid2: second sandpile
 *
 * Return: nothing
 */
void copy(int grid2[3][3], int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid2[i][j];
		}
	}
}


/**
 * zero - add zero to the grid
 * @grid2: sandpile
 *
 * Return: nothing
 */
void zero(int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid2[i][j] = 0;
		}
	}
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 *
 * Return: nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	}
	while (non_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		zero(grid2);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					grid2[i][j] += grid1[i][j] - 4;
					if (i - 1 >= 0)
						grid2[i - 1][j] += 1;
					if (j - 1 >= 0)
						grid2[i][j - 1] += 1;
					if (i + 1 <= 2)
						grid2[i + 1][j] += 1;
					if (j + 1 <= 2)
						grid2[i][j + 1] += 1;
				}
				else
					grid2[i][j] += grid1[i][j];
			}
		}
		copy(grid2, grid1);
	}
}
