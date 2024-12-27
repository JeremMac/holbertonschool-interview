#!/usr/bin/python3
"""
A module that contains isWinner function.
"""


def isWinner(x, nums):
    """
    A function that returns the winner's name.
    """
    def count_primes(n):
        """Returns prime numbers until n."""
        is_prime = [True] * (n + 1)
        p = 2
        while (p * p <= n):
            if (is_prime[p] == True):
                for i in range(p * p, n + 1, p):
                    is_prime[i] = False
            p += 1
        return sum(1 for p in range(2, n + 1) if is_prime[p])

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        if count_primes(n) % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
