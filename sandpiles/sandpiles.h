#ifndef SANDPILES_H
#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdlib.h>
#include <stdio.h>
static void print_grid(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int grid1_unstable(int grid1[3][3], int flags[3][3]);
void topple(int grid1[3][3], int i, int j);

#endif