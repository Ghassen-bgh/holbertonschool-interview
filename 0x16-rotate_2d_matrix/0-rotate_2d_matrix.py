#!/usr/bin/python3
""" 0-rotate_2d_matrix """


def rotate_2d_matrix(matrix):
    """ Rotate a 2D matrix 90 degrees clockwise """
    # Get the dimensions of the matrix
    rows = len(matrix)
    cols = len(matrix[0])
    # Create a new matrix with the same dimensions
    new_matrix = [[0 for col in range(rows)] for row in range(cols)]
    # Loop through the rows of the original matrix
    for row in range(rows):
        # Loop through the columns of the original matrix
        for col in range(cols):
            new_matrix[col][rows - row - 1] = matrix[row][col]
    # Copy the values from the new matrix to the original matrix
    for row in range(rows):
        for col in range(cols):
            matrix[row][col] = new_matrix[row][col]
