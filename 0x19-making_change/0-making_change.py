#!/usr/bin/python3
"""
Given a pile of coins of different values, determine the
fewest number of coins needed to meet a given amount total
"""


def makeChange(coins, total):
    """Return the least number of coins need to return the total
    @coins: list of the coins available
    @total: If total is 0 or less, return 0
    Return: fewest number of coins needed to meet total
    """
    n_coins = 0
    if total <= 0:
        return 0
    for coin in sorted(coins)[::-1]:
        n_coins += total // coin
        total = total % coin
    if total != 0:
        return -1
    return n_coins
