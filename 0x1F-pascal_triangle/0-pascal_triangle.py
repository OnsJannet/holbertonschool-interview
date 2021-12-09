#!/usr/bin/python3
"""
Pascal Triangle
"""


def pascal_triangle(n):
    """
    returns a list of lists of integers
    representing the Pascal’s triangle of n
    """
    # input n
    if n <= 0:
        return ([])

    tr = [[1]]

    for count in range(1, n):
        tr.append([])

        for m in range(count + 1):

            if m == 0 or m == count:
                tr[count].append(1)

            else:
                tr[count].append(tr[count - 1][m - 1] + tr[count - 1][m])
    return tr
