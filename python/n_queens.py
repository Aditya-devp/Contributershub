
def solve(n):

    result = []

    board = set()
    cols = set()

    def isSafe(i,j):
        l = r = j
        for y in range(i,-1,-1):
            if (y,l) in board or (y,r) in board: return False
            l -= 1
            r += 1
        return True
    
    def rec(i):
        if i == n: 
            result.append([["-"]*n for _ in range(n)])
            for x,y in board: result[-1][x][y] = '#'
            return
        
        for j in range(n):
            if j in cols: continue
            if not isSafe(i,j): continue
            board.add((i,j))
            cols.add(j)
            rec(i+1)
            cols.remove(j)
            board.remove((i,j))
    rec(0)
    return result

for idx, board in enumerate(solve(int(input("Enter value of n: ")))):
    print(f"Solution {idx+1}")
    for row in board: print(*row)
    print()