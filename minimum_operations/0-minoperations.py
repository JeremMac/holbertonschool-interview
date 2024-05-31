#!/usr/bin/python3


"""
A module that constains the minOperations function.
"""


def minOperations(n):
    """
    A method that calculates
    the fewest number of operations.
    """

    if n <= 1:

        return 0

    operations = 0
    number = 2

    while number <= n:
        if n % number == 0:
            operations += number
            n //= number
        else:
            number += 1

    return operations
