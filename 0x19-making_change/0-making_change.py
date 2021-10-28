#!/usr/bin/python3
"""
finds minimum number of coins needed
to meet a given amount total.
"""


def makeChange(coins, total):
    """ calculates coins """
    if total <= 0:
        return 0
    if len(coins) <= 0:
        return -1

    coins.sort()
    coins.reverse()
    result = 0

    for coin in coins:
        if total <= 0:
            break
        tmp = total // coin
        result += tmp
        total -= (tmp * coin)
    if total != 0:
        return -1
    return result
