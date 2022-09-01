#ifndef _SANDPILES_H_
#define _SANDPILES_H_

#include<stdlib.h>
#include<stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
static void print_grid(int grid[3][3]);
int verify_grid(int grid[3][3]);
void copy_grid(int src[3][3], int dest[3][3]);


#endif
