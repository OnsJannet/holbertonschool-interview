#!/usr/bin/python3
'''
Rotate 2D Matrix
'''


def rotate_2d_matrix(matrix):
    '''rotates 2D matrix 90° clockwise
    '''
    copied_matrix = matrix.copy()
    reverced_copy = copied_matrix[::-1]
    for elements in range(len(matrix[0])):
        new_matrix = []
        for row in reverced_copy:
            new_matrix.append(row[elements])
            matrix[elements] = new_matrix
