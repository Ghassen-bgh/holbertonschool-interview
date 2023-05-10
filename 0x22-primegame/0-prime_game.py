#!/usr/bin/python3
"""0. Prime Game"""


def isPrime(n):
    """Check if n is a prime number"""
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True


def addPrime(n, primes):
    """Add primes to the list"""
    last_prime = primes[-1]
    if n > last_prime:
        for i in range(last_prime + 1, n + 1):
            if isPrime(i):
                primes.append(i)
            else:
                primes.append(0)


def isWinner(x, nums):
    """Determine the winner of each game"""
    result = {"Maria": 0, "Ben": 0}
    primes = [0, 0, 2]
    addPrime(max(nums), primes)

    for round in range(x):
        _sum = sum((i != 0 and i <= nums[round])
                   for i in primes[:nums[round] + 1])
        if _sum % 2:
            winner = "Maria"
        else:
            winner = "Ben"
        if winner:
            result[winner] += 1

    if result["Maria"] > result["Ben"]:
        return "Maria"
    elif result["Ben"] > result["Maria"]:
        return "Ben"

    return None
