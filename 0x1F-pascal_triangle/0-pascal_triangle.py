#!/usr/bin/python3
"""
Returns a list of lists of integers
representing the Pascal’s triangle of n
"""


def pascal_triangle(n):
    """
    The Pascal's Triangle
    """
    triangle = []
    if n <= 0:
        return triangle
    triangle = [[1]]
    if n == 1:
        return triangle
    triangle = []
    for i in range(n):
        base = [1]
        for j in range(i):
            base.append(sum(triangle[-1][j:j+2]))
        triangle.append(base)
    return triangle
