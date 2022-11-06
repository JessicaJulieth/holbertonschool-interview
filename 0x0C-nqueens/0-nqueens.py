#!/usr/bin/python3
""" The N queens puzzle is the challenge of placing N non-attacking
queens on an N.N chessboard. Write a program that solves the N queens
problem. 
"""


import sys


if __name__ == "__main__":
    if len(sys.argv) == 1 or len(sys.argv) > 2:
        print("Usage: nqueens N")
        sys.exit(1)
    N = sys.argv[1]
    try:
        Ni = int(N)
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    if Ni < 4:
        print("N must be at least 4")
        sys.exit(1)

    z = []

    def isSafe(z, row, col):
        """ Checks if queen can be placed in coord of board.
        Returns True if can, else False
        """
        rows = []
        cols = []
        diag_r = []
        diag_l = []

        for square in z:
            rows.append(square[0])
            cols.append(square[1])
            diag_r.append(square[0] + square[1])
            diag_l.append(square[1] - square[0])

        if row in rows or col in cols:
            return False
        if row + col in diag_r or col - row in diag_l:
            return False

        return True

    def solveNqueens(z, col, arrays=[]):
        """ Creates array of queen positions
        Returns array
        """
        for x in range(Ni):
            if isSafe(z, x, col):
                z.append([x, col])
                if col == Ni - 1:
                    arrays.append(z.copy())
                    del z[-1]
                else:
                    solveNqueens(z, col + 1)

        if len(z):
            del z[-1]
        return arrays

    z = solveNqueens(z, 0)

    for squares in z:
        print(squares)
