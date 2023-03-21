#!/usr/bin/python3
"""
Make Change Module
"""
def makeChange(coins, total):
	if total == 0:
		return 0
	minCoins = total
	for i in [c for c in coins if c <= total]:
		numCoins = 1 + makeChange(coins, total - i)
		if numCoins < minCoins:
			minCoins = numCoins
	return minCoins
