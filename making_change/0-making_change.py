#!/usr/bin/python3
"""Module for the makeChange function"""


def makeChange(coins, total):
    """
    Determines the fewest number of coins needed
    to meet a given amount `total`

    Args:
        coins (list): List of coin denominations.
        total (int): The amount to achieve.

    Returns:
        int: The minimum number of coins required to achieve the total,
        or -1 if it is not possible.
    """
    if total <= 0:
        return 0

    # Sort coins in descending order
    coins.sort(reverse=True)
    num_coins = 0
    remaining = total

    for coin in coins:
        if remaining <= 0:
            break
        # Use as many of this coin as possible
        num_coins += remaining // coin
        remaining %= coin

    # Check if we reached the total
    if remaining == 0:
        return num_coins
    else:
        return -1
