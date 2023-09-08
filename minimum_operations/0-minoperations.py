#!/usr/bin/python3
""" alculates the fewest number of 
operations needed to result in exactly n H """


def minOperations(n):
    """min opearation"""
    if n <= 1:
        return 0

    operations = 0
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            n //= divisor
            operations += divisor

        divisor += 1

    return operations
