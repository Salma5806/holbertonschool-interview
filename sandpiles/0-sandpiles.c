 #include "sandpiles.h"

/**
 * sandpiles_sum - sums two sandpiles and topples until sum is stable
 * @grid1: first 3x3 grid of integers to sum, assumed to be stable
 * @grid2: second 3x3 grid of integers to sum, assumed to be stable
 *
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0;
	int flags[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	/* sum grid1 and grid2 into grid1 */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
	while (grid1_unstable(grid1, flags))
	{
		/* print unstable grid before topple round */
		printf("=\n");
		print_grid(grid1);
		/* for every indicated flag, topple the cell */
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (flags[i][j])
					topple(grid1, i, j);
			}
		}
	}
}


/**
 * grid1_unstable - checks stabiliby of grid1 and sets flags where unstable
 * grid1 is unstable if any of its cells contain more than 3 grains
 * @grid1: 3x3 grid of integers to check stability of
 * @flags: 3x3 gird indicating where unstable cells are prior to toppling
 *
 * Return: 1 if unstable, 0 otherwise
 */

int grid1_unstable(int grid1[3][3], int flags[3][3])
{
	int check = 0, i = 0, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				check = 1;
				flags[i][j] = 1;
			}
			else
				flags[i][j] = 0;
		}
	}
	return (check);
}


/**
 * topple - topples individual cell to help make sandpile stable
 * @grid1: 3x3 grid which hold cell to topple
 * @i: row coordinate of cell to topple
 * @j: column coordinate of cell to topple
 *
 */

void topple(int grid1[3][3], int i, int j)
{
	grid1[i][j] -= 4;
	if (i - 1 >= 0)
		grid1[i - 1][j] += 1;
	if (i + 1 < 3)
		grid1[i + 1][j] += 1;
	if (j - 1 >= 0)
		grid1[i][j - 1] += 1;
	if (j + 1 < 3)
		grid1[i][j + 1] += 1;
}

/**
 * print_grid - prints individual grid
 * @grid: 3x3 grid of integers to print
 *
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