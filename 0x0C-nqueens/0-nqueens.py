#!/usr/bin/python3
"""
The N queens puzzle
"""


import sys

def is_valid(board, row, col, n):
    for i in range(row):
        if board[i] == col or \
           board[i] + i == col + row or \
           board[i] - i == col - row:
            return False
    return True

def solve(board, row, n):
    if row == n:
        print(" ".join(str(x+1) for x in board))
        return
    for col in range(n):
        if is_valid(board, row, col, n):
            board[row] = col
            solve(board, row+1, n)

def nqueens(n):
    if not n.isnumeric():
        print("N must be a number")
        return 1
    n = int(n)
    if n < 4:
        print("N must be at least 4")
        return 1
    board = [-1] * n
    solve(board, 0, n)

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    nqueens(sys.argv[1])
