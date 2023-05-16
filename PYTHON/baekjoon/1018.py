def get_map(rows):
    return [input().strip() for _ in range(rows)]

def check_map(board):
    min_repaints = float('inf')
    for i in range(len(board) - 7):
        for j in range(len(board[0]) - 7):
            repaints = count_repaints(board, i, j)
            min_repaints = min(min_repaints, repaints)
    return min_repaints

def count_repaints(board, start_row, start_col):
    repaints = 0
    colors = ['B', 'W']
    for i in range(start_row, start_row + 8):
        for j in range(start_col, start_col + 8):
            if board[i][j] != colors[(i - start_row + j - start_col) % 2]:
                repaints += 1
    return min(repaints, 64 - repaints)

# Read N and M
N, M = map(int, input().split())

# Read the board
board = get_map(N)

# Check the board and print the result
min_repaints = check_map(board)
print(min_repaints)
