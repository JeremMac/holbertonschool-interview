#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdlib.h>
#include <stdio.h>

void grid_addition(int grid1[3][3], int grid2[3][3]);
void grid_print(int grid[3][3]);
int grid_is_ok(int grid[3][3]);
void grid_change(int grid1[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif
