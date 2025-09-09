#!/usr/bin/python3
"""N queens problem solver"""
import sys


def is_safe(board, row, col, N):
    """Check if a queen can be placed on board[row][col]"""
    # Check column
    for i in range(row):
        if board[i] == col:
            return False

    # Check diagonals
    for i, j in zip(range(row - 1, -1, -1), range(col - 1, -1, -1)):
        if board[i] == j:
            return False

    for i, j in zip(range(row - 1, -1, -1), range(col + 1, N)):
        if board[i] == j:
            return False

    return True


def solve_nqueens(N, row, board, solutions):
    """Use backtracking to solve the N queens problem"""
    if row == N:
        solution = [[i, board[i]] for i in range(N)]
        solutions.append(solution)
        return

    for col in range(N):
        if is_safe(board, row, col, N):
            board[row] = col
            solve_nqueens(N, row + 1, board, solutions)
            board[row] = -1


def main():
    """Main entry point"""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    board = [-1] * N
    solutions = []
    solve_nqueens(N, 0, board, solutions)

    for sol in solutions:
        print(sol)


if __name__ == "__main__":
    main()
