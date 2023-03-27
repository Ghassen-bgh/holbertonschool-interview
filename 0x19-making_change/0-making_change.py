#!/usr/bin/python3
"""
Make Change Module
"""


def makeChange(coins, total):
    """
    Make Change
    """
    if total <= 0:
        return 0

    minCoins = [float('inf')] * (total+1)
    minCoins[0] = 0
    for coin in coins:
        for i in range(coin, total+1):
            if minCoins[i-coin] + 1 < minCoins[i]:
                minCoins[i] = minCoins[i-coin] + 1
    if minCoins[total] == float('inf'):
        return -1

    return minCoins[total]
