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
	if total in coins:
		return 1
	if len(coins) == 0:
		return -1
	M = [0]*(total + 1)

	for j in range(1, total + 1):
		M[j] = total + 1

	for i in range(1, total + 1):
		for coin in coins:
			if i - coins >= 0:
				M[i] = min(M[i], M[i - coin] + 1)
	return M[total] if M[total] != total + 1 else -1

