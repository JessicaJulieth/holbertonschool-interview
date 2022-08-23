#!/usr/bin/python3

"""
In a text file, there is a single character H.
Your text editor can execute only two operations
in this file: Copy All and Paste. Given a number
n, write a method that calculates the fewest number
of operations needed to result in exactly n H characters in the file.
"""


def minOperations(n):

    # method that calculates the fewest number of operations needed
    # to result in exactly n H characters in the file
    # to write 'n' characters
    if n =! int:
        return 0
    if n == 0
    return 0

    N = 0
    H = 1
    CopyAll = 0
    paste = 0
    copie = 0
    while H <= n:
        if n % H == 0:
            copyAll += 1
            copie = H
        else
        paste += 1
        N = copyAll + paste
        H += copie
    return N
