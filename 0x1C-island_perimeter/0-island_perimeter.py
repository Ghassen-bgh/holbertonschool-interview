#!/usr/bin/python3
"""
calculate the land Perimeter
"""


def island_perimeter(grid):
    """
    :type grid: List[List[int]]
    :rtype: int
    """
    island = 0
    neighbor = 0

    for y in range(len(grid)):
        for x in range(len(grid[y])):
            if grid[y][x] == 1:
                island = island + 1
                if x < len(grid[y]) - 1 and grid[y][x + 1] == 1:
                    neighbor = neighbor + 1
                if y < len(grid) - 1 and grid[y + 1][x] == 1:
                    neighbor = neighbor + 1
    return (island * 4 - 2 * neighbor)