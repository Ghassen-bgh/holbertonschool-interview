#!/usr/bin/python3
"""prime game"""
def isWinner(x, nums):
    """Determine the winner of a game of prime numbers"""
    def getPrimes(n):
        """Get all primes up to n"""
        primes = [True] * (n+1)
        primes[0] = primes[1] = False
        for i in range(2, int(n**0.5)+1):
            if primes[i]:
                for j in range(i*i, n+1, i):
                    primes[j] = False
        return [i for i in range(2, n+1) if primes[i]]

    def playGame(primes):
        """Play the game"""
        player = 0
        remaining = set(primes)
        while remaining:
            canPlay = False
            for p in primes:
                if p in remaining:
                    canPlay = True
                    remaining.difference_update(set(range(p, n+1, p)))
                    player = (player + 1) % 2
                    break
            if not canPlay:
                return player
        return (player + 1) % 2
    wins = [0, 0]
    for i in range(x):
        n = nums[i]
        primes = getPrimes(n)
        winner = playGame(primes)
        wins[winner] += 1
    if wins[0] > wins[1]:
        return "Maria"
    elif wins[1] > wins[0]:
        return "Ben"
    else:
        return None
