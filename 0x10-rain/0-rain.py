#!/usr/bin/python3
"""
  Given a list of non-negative integers representing the heights
  of walls with unit width 1, as if viewing the cross-section of
  a relief map, calculate how many square units of water will be
  retained after it rains
"""


def rain(walls):
    """rain
    @walls: Is a list of non-negative integers.
    Return: Integer indicating total amount of rainwater retained.
    """
    left = 0
    x_max = 0
    right = len(walls) - 1
    y_max = 0
    z = 0
    while (left < right):
        if walls[left] < walls[right]:
            if walls[left] >= x_max:
                x_max = walls[left]
            else:
                z += x_max - walls[left]
            left += 1
        else:
            if walls[right] >= y_max:
                y_max = walls[right]
            else:
                z += y_max - walls[right]
            right -= 1
    return z
