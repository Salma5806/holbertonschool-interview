#!/usr/bin/python3
"""
0-pascal_triangle
"""

def pascal_triangle(n):
    """
    Returns a list of lists representing Pascal's triangle of n rows.

    Args:
        n (int): Number of rows in the triangle

    Returns:
        list of lists of int: Pascal's triangle
    """
    if n <= 0:
        return []

    triangle = [[1]]  # First row

    for i in range(1, n):
        row = [1]  # First element of each row
        # Compute intermediate values
        for j in range(1, i):
            row.append(triangle[i-1][j-1] + triangle[i-1][j])
        row.append(1)  # Last element of each row
        triangle.append(row)

    return triangle