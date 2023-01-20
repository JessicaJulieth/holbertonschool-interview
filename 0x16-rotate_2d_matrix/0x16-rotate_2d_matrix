#!/usr/bin/python3
"""
0x16-rotate_2d_matrix
"""


def rotate_2d_matrix(matrix):
    """ Rotate  matrix 
    """
    matrix.reverse()
    matrix_temp = matrix.copy()

    for i in range(len(matrix)):
        matrix[i] = [row[i] for row in matrix_temp]
