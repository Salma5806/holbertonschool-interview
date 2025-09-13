#!/usr/bin/python3
"""
Module for calculating minimum coins to make change
"""


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet a given total

    Args:
        coins (list): List of coin denominations (integers > 0)
        total (int): Amount to reach

    Returns:
        int: Minimum number of coins to reach total
             0 if total <= 0
             -1 if total cannot be reached
    """
    if total <= 0:
        return 0

    # Initialize DP array; dp[i] = min coins to make i
    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for coin in coins:
        for amount in range(coin, total + 1):
            if dp[amount - coin] != float('inf'):
                dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1