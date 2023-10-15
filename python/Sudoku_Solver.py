N = 9

def display(board):
    for i in range(9):
        if i % 3 == 0 and i != 0:
            print("------+-------+-------")
        for j in range(9):
            if j % 3 == 0 and j != 0:
                print("|", end = " ")
            if j == 8:
                print(board[i][j] if board[i][j] else "_")
            else:
                if board[i][j] == 0: print("_", end = " ")
                else: print(str(board[i][j]), end = " ")

def isSafe(board, row, col, num):

	for x in range(9):
		if board[row][x] == num:
			return False

	for x in range(9):
		if board[x][col] == num:
			return False

	startRow = row - row % 3
	startCol = col - col % 3
	for i in range(3):
		for j in range(3):
			if board[i + startRow][j + startCol] == num:
				return False
	return True

def solve(board, row, col):
	
	if (row == N - 1 and col == N): return True
	if col == N: row, col = row+1, 0

	if board[row][col] > 0: return solve(board, row, col + 1)
	for num in range(1, N + 1, 1):

		if isSafe(board, row, col, num):
			board[row][col] = num
			if solve(board, row, col + 1):
				return True
		board[row][col] = 0
	return False

# Driver Code

Sudoku = [
	[3, 0, 6, 5, 0, 8, 4, 0, 0],
	[5, 2, 0, 0, 0, 0, 0, 0, 0],
	[0, 8, 7, 0, 0, 0, 0, 3, 1],
	[0, 0, 3, 0, 1, 0, 0, 8, 0],
	[9, 0, 0, 8, 6, 3, 0, 0, 5],
	[0, 5, 0, 0, 9, 0, 6, 0, 0],
	[1, 3, 0, 0, 0, 0, 2, 5, 0],
	[0, 0, 0, 0, 0, 0, 0, 7, 4],
	[0, 0, 5, 2, 0, 6, 3, 0, 0]
]

print("Given Sudoku Puzzle:")
display(Sudoku)

if (solve(Sudoku, 0, 0)):
	print("\nSolution: ")
	display(Sudoku)
else: print("no solution exists ")