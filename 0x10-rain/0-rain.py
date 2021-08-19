#!/usr/bin/python3
"""
Rain
"""
def rain(walls: int) -> int:
    """calculation of rains"""
    if not walls:
        return 0
    walls_length = len(walls)
    water = 0
    for i in range(walls_length):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]
        for j in range(i + 1, len(walls)):
            right = max(right, walls[j])
        water += min(left, right) - walls[i]
    return water
