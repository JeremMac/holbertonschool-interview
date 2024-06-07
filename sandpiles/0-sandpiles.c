#include <stdio.h>
#include "sandpiles.h"

/**
 * sandpiles_sum - a function that computes
 * the sum of two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int unstable = 0;
	int i, j;


	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	do {
		unstable = 0;


		printf("=\n");
		print_grid(grid1);

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					unstable = 1;
					grid1[i][j] -= 4;
					if (i > 0)
						grid1[i - 1][j]++;
					if (i < 2)
						grid1[i + 1][j]++;
					if (j > 0)
						grid1[i][j - 1]++;
					if (j < 2)
						grid1[i][j + 1]++;
				}
			}
		}
	} while (unstable);
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
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
