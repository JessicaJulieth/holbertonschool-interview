#!/usr/bin/python3
"""
The N queens puzzle is the challenge of placing N non-attacking
queens on an N×N chessboard. Write a program that solves the N queens
problem.
"""
if __name__ == "__main__":
    import sys


def flldiagonals(rest, n):
    flldiagonals = []
    for i in rest:
        x = i[0]
        y = i[1]
        while y >= 0 and y < n and x >= 0 and x < n:
            if [x, y] not in flldiagonals:
                flldiagonals.append([x, y])
            x -= 1
            y -= 1

        x = i[0]
        y = i[1]
        while y >= 0 and y < n and x >= 0 and x < n:
            if [x, y] not in flldiagonals:
                flldiagonals.append([x, y])
            x -= 1
            y += 1

        x = i[0]
        y = i[1]
        while y >= 0 and y < n and x >= 0 and x < n:
            if [x, y] not in flldiagonals:
                flldiagonals.append([x, y])
            x += 1
            y -= 1

        x = i[0]
        y = i[1]
        while y >= 0 and y < n and x >= 0 and x < n:
            if [x, y] not in flldiagonals:
                flldiagonals.append([x, y])
            x += 1
            y += 1

    return flldiagonals


def safe(x, y, rest, n):
    """
    Here safe a position
    """
    for _x in range(n):
        if [_x, y] in rest:
            return False

    return not [x, y] in flldiagonals(rest, n)


def iter(n):
    """
    Iterate all positions
    """
    rest = []
    x = 0
    y = 0

    while x < n:
        while y < n:
            if safe(x, y, rest, n):
                rest.append([x, y])
                break
            y += 1

        if len(rest) != (x + 1):
            x -= 1
            if x < 0:
                break
            y = rest[x][1] + 1
            del rest[x]
            continue
        elif len(rest) == n:
            print(rest)
            y += 1
            del rest[x]
            continue
        x += 1
        y = 0


def init():
    """
    N queens
    """
    argc = sys.argv

    if argc != 2:
        print("Usage: nqueens N")
        exit(1)

    try:
        int(args[1])
    except User.DoesNotExist:
        print("N must be a number")
        sys.exit(1)

    if int(args[1]) < 4:
        print("N must be at least 4")
        sys.exit(1)

    n = int(args[1])
    iter(n)
