#!/usr/bin/python3
"""
The N queens puzzle is the challenge of placing N non-attacking
queens on an N×N chessboard. Write a program that solves the N queens
problem.
"""

import sys


if __name__ == "__main__":

    argv = sys.argv
    argc = len(sys.argv)

    if argc == 1 or len(sys.argv) > 2:
        print('Usage: nqueens N')
        sys.exit(1)
    N = sys.argv[1]
    try:
        In = int(N)
    except ValueError:
        print('N must be a number')
        sys.exit(1)
    if In < 4:
        print('N must be at least 4')
        sys.exit(1)

    z = []

    def isSafe(z, row, col):
        x = []
        y = []
        x_diag = []
        y_diag = []

        for pos in z:
            x.append(pos[0])
            y.append(pos[1])
            x_diag.append(pos[0] + pos[1])
            y_diag.append(pos[1] - pos[0])

        if row in x or col in y:
            return False

        if row + col in x_diag or col - row in y_diag:
            return False

        return True

    def Nqueens(z, col, arrays=[]):
        """
        Queens
        """
        for i in range(In):
            if isSafe(z, i, col):
                z.append([i, col])
                if col == In - 1:
                    arrays.append(z.copy())
                    del z[-1]
                else:
                    Nqueens(z, col + 1)

        if len(z):
            del z[-1]
        return arrays

    z = Nqueens(z, 0)

    for pos in z:
        print(pos)
