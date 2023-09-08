#!/usr/bin/python3
""" alculates the fewest number of operations needed to result in exactly n H """


def minOperations(n):
    """ Min number of operations """
    if n <= 1:
        return 0

    operations = [0] * (n + 1)

    for i in range(2, n + 1):
        operations[i] = float('inf')
        for j in range(1, i):
            if i % j == 0:
                operations[i] = min(operations[i], operations[j] + i // j)

    return operations[n]
