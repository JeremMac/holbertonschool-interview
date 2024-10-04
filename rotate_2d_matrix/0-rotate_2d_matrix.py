#!/usr/bin/python3
"""
Rotate 2D Matrix - 90 degrees clockwise
"""


def rotate_2d_matrix(matrix):
    """
    Rotate a square matrix 90 degrees clockwise in place.
    Args:
        matrix (list of lists): The n x n 2D matrix to rotate.
    Returns:
        None: The matrix is modified in place.
    """
    n = len(matrix)

    # Step 1: Transpose the matrix (convert rows to columns)
    for i in range(n):
        for j in range(i, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Step 2: Reverse each row
    for i in range(n):
        matrix[i].reverse()
