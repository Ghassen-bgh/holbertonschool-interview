#!/usr/bin/python3
"""Module for minimumOperations method.
"""
def ispremium(n):
    """Method to check if a number is prime.
    """
    if n <= 1:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

def minimumOperations(n):
    """Method to calculate the fewest number of operations needed to result in
    exactly n H characters in the file.
    """
    if n < 2:
        return 0
    i = 2
    o = 0
    while (n != 1):
        if (ispremium(i) and n % i == 0):
            o += i
            n /= i
        else:
            i += 1
    return o
