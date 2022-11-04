#!/usr/bin/python3
"""
The N queens puzzle is the challenge of placing N non-attacking
queens on an N×N chessboard. Write a program that solves the N queens
problem.
"""

if __name__ == "__main__":
    import sys

    argv = sys.argv
    argc = len(argv)

    if argc is not 2:
        print('Usage: nqueens N')
        exit(1)

    try:
        n = int(argv[1])
        if n < 4:
            print('N must be at least 4')
            exit(1)
    except ValueError:
        print('N must be a number')
        exit(1)

    z = []

    def safe(z, row, col):
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

    def queens(z, col, arrays=[]):
        """
        Queens
        """
        for i in range(n):
            if safe(z, i, col):
                z.append([i, col])
                if col == n - 1:
                    arrays.append(z.copy())
                    del z[-1]
                else:
                    queens(z, col + 1)

        if len(z):
            del z[-1]
        return arrays

    z = queens(z, 0)

    for pos in z:
        print(pos)
