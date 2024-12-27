#!/usr/bin/python3
"""
A module that contains isWinner function.
"""


def is_prime(num):
    """Check if a number is prime."""
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True


def sieve_up_to(max_num):
    """Generate a list of booleans where True indicates
    that the index is a prime number.
    """
    primes = [True] * (max_num + 1)
    primes[0] = primes[1] = False
    for i in range(2, int(max_num**0.5) + 1):
        if primes[i]:
            for multiple in range(i * i, max_num + 1, i):
                primes[multiple] = False
    return primes


def isWinner(x, nums):
    """Determine the winner of the prime game."""
    if not nums or x < 1:
        return None

    max_num = max(nums)
    primes = sieve_up_to(max_num)

    wins = {"Maria": 0, "Ben": 0}

    for n in nums:
        prime_count = sum(primes[:n + 1])

        # Maria starts first; if prime_count is odd, Maria wins this round
        if prime_count % 2 == 1:
            wins["Maria"] += 1
        else:
            wins["Ben"] += 1

    if wins["Maria"] > wins["Ben"]:
        return "Maria"
    elif wins["Ben"] > wins["Maria"]:
        return "Ben"
    else:
        return None
