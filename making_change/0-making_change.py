#!/usr/bin/python3
"""
Module to calculate the fewest number of coins needed to meet a total.
"""


def makeChange(coins, total):
    if total <= 0:
        return 0

    # Initialize a list to store the minimum coins needed for each amount
    dp = [float('inf')] * (total + 1)
    dp[0] = 0  # No coins are needed to make 0 total

    # Iterate through each coin
    for coin in coins:
        for amount in range(coin, total + 1):
            dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    # If dp[total] is still inf, it means total cannot be met
    return dp[total] if dp[total] != float('inf') else -1
