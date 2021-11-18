#!/usr/bin/python3
'''
Island Perimeter
'''


def island_perimeter(grid) -> int:
    '''
        returns the perimeter of the island described in grid
        grid is a list of list of integers
        0 represents water
        1 represents land

            Find land (1).
            Find neighbor (<->).
            Return 4 * land -2 * neightbor.
    '''
    row, col = len(grid), len(grid[0])
    land, neighbor_land = 0, 0
    for i in range(row):
        for j in range(col):
            if grid[i][j] == 1:
                land += 1
                if i < row-1 and grid[i+1][j] == 1:
                    neighbor_land += 1
                if j < col-1 and grid[i][j+1] == 1:
                    neighbor_land += 1
    return land*4-2*neighbor_land
