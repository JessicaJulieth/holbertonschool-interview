#include "sandpiles.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * print_grid - Print a grid
 * @grid: Grid.
 */

void print_grid(int grid[3][3])
{
	int m = 0;
    int n = 0;

    printf("=\n");
	for (m = 0; m < 3; m++)
	{
		for (m = 0; n < 3; n++)
		{
			if (n)
				printf(" ");
			printf("%d", grid[m][n]);
		}
		printf("\n");
	}
}
/**
 * is_stable - Checks a grid
 * @grid: Grid
 * Return: 1 if stable 0 or 0
 */

int is_stable(int grid[3][3])
{
	int m = 0;
    int n = 0;

	for (m = 0; m < 3; m++)
	{
		for (n = 0; n < 3; n++)
		{
			if (grid[m][n] > 3)
				return (0);
		}
	}
	return (1);
}
/**
 * sum_sandpiles - adds sandpiles without toppling
 * @grid1: Grid 1
 * @grid2: Grid 2
 */

void sum_sandpiles(int grid1[3][3], int grid2[3][3])
{
	int m = 0;
    int n = 0;
    int x = 0;

	for (m = 0; m < 3; m++)
	{
		for (n = 0; n < 3; n++)
		{
			x = grid1[m][n] + grid2[m][n];
			grid2[m][n] = x;
			grid1[m][n] = x;
		}
	}
}
/**
 * sandpiles_sum - Sum sandpiles
 * @grid1: Grid 1
 * @grid2: Grid 2
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int m = 0;
    int n = 0;

	sum_sandpiles(grid1, grid2);

	while (!(is_stable(grid1)))
	{
		printf("=\n");
		print_grid(grid1);
		for (m = 0; m < 3; m++)
		{
			for (n = 0; n < 3; n++)
			{
				if (grid1[m][n] > 3)
					grid1[m][n] -= 4;
				if ((m > 0) && (grid2[m - 1][n] > 3))
					grid1[m][n] += 1;
				if ((m < 2) && (grid2[m + 1][n] > 3))
					grid1[m][n] += 1;
				if ((n > 0) && (grid2[m][n - 1] > 3))
					grid1[m][n] += 1;
				if ((n < 2) && (grid2[m][n + 1] > 3))
					grid1[m][n] += 1;
			}
		}
		for (m = 0; m < 3; m++)
		{
			for (n = 0; n < 3; n++)
				grid2[m][n] = grid1[m][n];
		}
	}
}
