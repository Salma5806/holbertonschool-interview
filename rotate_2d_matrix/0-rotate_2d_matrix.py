#!/usr/bin/python3
"""
0-rotate_2d_matrix.py
Rotate a 2D n x n matrix 90 degrees clockwise in-place
"""

def rotate_2d_matrix(matrix):
    """
    Rotates a 2D matrix 90 degrees clockwise in-place.
    
    Args:
        matrix (list of list of ints): n x n matrix to rotate
    """
    n = len(matrix)
    # Transpose the matrix
    for i in range(n):
        for j in range(i + 1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Reverse each row
    for row in matrix:
        row.reverse()