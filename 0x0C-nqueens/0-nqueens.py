#!/usr/bin/python3
<<<<<<< HEAD
""" The N queens puzzle is the challenge of placing N non-attacking
queens on an N.N chessboard. Write a program that solves the N queens
problem.
"""
=======
""" Solving n queens """

>>>>>>> 5fcd423258138fc17675ac5e84672fbffb37f053


import sys


if __name__ == "__main__":
    if len(sys.argv) == 1 or len(sys.argv) > 2:
        print("Usage: nqueens N")
        sys.exit(1)
    N = sys.argv[1]
    try:
<<<<<<< HEAD
        Ni = int(N)
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    if Ni < 4:
=======
        N_int = int(N)
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    if N_int < 4:
>>>>>>> 5fcd423258138fc17675ac5e84672fbffb37f053
        print("N must be at least 4")
        sys.exit(1)

    coords = []

<<<<<<< HEAD
    def isSafe(z, row, col):
=======
    def isSafe(coords, row, col):
>>>>>>> 5fcd423258138fc17675ac5e84672fbffb37f053
        """ Checks if queen can be placed in coord of board.
        Returns True if can, else False
        """
        rows = []
        cols = []
        diag_r = []
        diag_l = []

<<<<<<< HEAD
        for square in z:
=======
        for square in coords:
>>>>>>> 5fcd423258138fc17675ac5e84672fbffb37f053
            rows.append(square[0])
            cols.append(square[1])
            diag_r.append(square[0] + square[1])
            diag_l.append(square[1] - square[0])

        if row in rows or col in cols:
            return False
        if row + col in diag_r or col - row in diag_l:
            return False

        return True

<<<<<<< HEAD
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
=======
    def solveNqueens(coords, col, safe_queens=[]):
        """ Creates array of queen positions
        Returns array
        """
        for x in range(N_int):
            if isSafe(coords, x, col):
                coords.append([x, col])
                if col == N_int - 1:
                    safe_queens.append(coords.copy())
                    del coords[-1]
                else:
                    solveNqueens(coords, col + 1)
>>>>>>> 5fcd423258138fc17675ac5e84672fbffb37f053

        if len(coords):
            del coords[-1]
        return safe_queens

<<<<<<< HEAD
    z = solveNqueens(z, 0)

    for squares in z:
=======
    coords = solveNqueens(coords, 0)

    for squares in coords:
>>>>>>> 5fcd423258138fc17675ac5e84672fbffb37f053
        print(squares)
