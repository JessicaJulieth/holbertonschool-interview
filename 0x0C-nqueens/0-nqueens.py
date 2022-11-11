#!/usr/bin/python3
<<<<<<< HEAD
<<<<<<< HEAD
""" The N queens puzzle is the challenge of placing N non-attacking
=======
"""
The N queens puzzle is the challenge of placing N non-attacking
>>>>>>> parent of 5062193... Changes
queens on an N.N chessboard. Write a program that solves the N queens
problem.
"""
=======
""" Solving n queens """

>>>>>>> 5fcd423258138fc17675ac5e84672fbffb37f053

import sys


if __name__ == "__main__":

    argv = sys.argv
    argc = len(sys.argv)

    if argc == 1 or len(sys.argv) > 2:
        print('Usage: nqueens N')
        sys.exit(1)
    N = sys.argv[1]
    try:
<<<<<<< HEAD
<<<<<<< HEAD
        Ni = int(N)
=======
        In = int(N)
>>>>>>> parent of 5062193... Changes
    except ValueError:
        print('N must be a number')
        sys.exit(1)
<<<<<<< HEAD
    if Ni < 4:
=======
        N_int = int(N)
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    if N_int < 4:
>>>>>>> 5fcd423258138fc17675ac5e84672fbffb37f053
        print("N must be at least 4")
=======
    if In < 4:
        print('N must be at least 4')
>>>>>>> parent of 5062193... Changes
        sys.exit(1)

    coords = []

<<<<<<< HEAD
    def isSafe(z, row, col):
<<<<<<< HEAD
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
=======
        x = []
        y = []
        x_diag = []
        y_diag = []

        for pos in z:
            x.append(pos[0])
            y.append(pos[1])
            x_diag.append(pos[0] + pos[1])
            y_diag.append(pos[1] - pos[0])
>>>>>>> parent of 5062193... Changes

        if row in x or col in y:
            return False

        if row + col in x_diag or col - row in y_diag:
            return False

        return True

<<<<<<< HEAD
<<<<<<< HEAD
    def solveNqueens(z, col, arrays=[]):
        """ Creates array of queen positions
        Returns array
=======
    def Nqueens(z, col, arrays=[]):
        """
        Queens
>>>>>>> parent of 5062193... Changes
        """
        for i in range(In):
            if isSafe(z, i, col):
                z.append([i, col])
                if col == In - 1:
                    arrays.append(z.copy())
                    del z[-1]
                else:
<<<<<<< HEAD
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
=======
                    Nqueens(z, col + 1)
>>>>>>> parent of 5062193... Changes

        if len(coords):
            del coords[-1]
        return safe_queens

<<<<<<< HEAD
<<<<<<< HEAD
    z = solveNqueens(z, 0)

    for squares in z:
=======
    coords = solveNqueens(coords, 0)

    for squares in coords:
>>>>>>> 5fcd423258138fc17675ac5e84672fbffb37f053
        print(squares)
=======
    z = Nqueens(z, 0)

    for pos in z:
        print(pos)
>>>>>>> parent of 5062193... Changes
