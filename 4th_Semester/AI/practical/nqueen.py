'''
logic where the queen must not be placed:
1) row, col+-
2) row--, col--
3) row++, col--
'''


def is_safe(board, row, col, n):
    for c in range(col, -1, -1):  # check for the same row in left side of the board
        if board[row][c] == 'Q':
            return False

    i = row
    j = col

    while i >= 0 and j >= 0:  # check for the left diagonal in the upper side of the board
        if board[i][j] == 'Q':
            return False

        i -= 1
        j -= 1

    i = row
    j = col

    while i < n and j >= 0:  # check for the left diagonal in the bottom side of the board
        if board[i][j] == 'Q':
            return False

        i += 1
        j -= 1

    return True


def nqueen(board, col, n):
    if col >= n:
        return True
    for i in range(n):
        if is_safe(board, i, col, n):
            board[i][col] = 'Q'
            if nqueen(board, col+1, n):
                return True
            board[i][col] = 0
    return False


n = int(input("Enter the number of queens: "))
board = [[0 for j in range(n)] for i in range(n)]

if nqueen(board, 0, n) == True:
    for i in range(n):
        for j in range(n):
            print(board[i][j], end=' ')
        print()
else:
    print("Not possible")
