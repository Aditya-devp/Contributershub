import readchar as r
import os
os.system('clear')

RULES = """\u001b[1m-------- RULES --------\u001b[0m

1. The game is played on a 5x5 board.
2. There are two players, and each player is represented by a different symbol.
3. Players take turns to make a move.
4. Players can make their move by specifying the following:
   - The direction of the move (L for left, R for right, B for bottom, T for top).
   - The column number (1 to 5) where they want to make their move.
   - Players cannot make a move in a column that is already filled.
5. When a player makes a move, the rows or columns shift to accommodate the new symbol. The rows and columns shift as follows:
   - L: the symbols in the selected row are shifted to the right, and the new symbol is placed in the leftmost position of that row.
   - R: the symbols in the selected row are shifted to the left, and the new symbol is placed in the rightmost position of that row.
   - B: the symbols in the selected column are shifted upwards, and the new symbol is placed at the bottom of that column.
   - T: the symbols in the selected column are shifted downwards, and the new symbol is placed at the top of that column.
6. The game continues until one player achieves a straight line of 5 of their symbols in a row, column, or diagonal.
7. If all spaces on the board are filled, and no player has won, the game is declared a draw.
8. Players can replay by typing "y" or "yes" when prompted at the end of the game.
"""

ASCII_RED = '\u001b[31m'
ASCII_GREEN = '\u001b[32m'
ASCII_YELLOW = ''
ASCII_BLUE = '\u001b[34m'
ASCII_RESET = '\u001b[0m'
EMPTY = ASCII_YELLOW+'_'+ASCII_RESET

ASCII_ARROW_UP = ASCII_BLUE+'\u2191'+ASCII_RESET
ASCII_ARROW_DOWN = ASCII_BLUE+'\u2193'+ASCII_RESET
ASCII_ARROW_LEFT = ASCII_BLUE+'\u2190'+ASCII_RESET
ASCII_ARROW_RIGHT = ASCII_BLUE+'\u2192'+ASCII_RESET
ASCII_CROSS = ASCII_RED+'\u2715'+ASCII_RESET
ASCII_CIRCLE = ASCII_GREEN+'\u25CF'+ASCII_RESET

POINTER = [ASCII_CROSS, ASCII_CIRCLE]

class Cursor:
    SAVE = '\u001b[s'
    RESTORE = '\u001b[u'
    @staticmethod
    def pos(x, y): return '\u001b['+str(y)+';'+str(x)+'H'

def pboard(board):
    print(" ", (ASCII_ARROW_DOWN+' ')*5)
    for row in board:
        print(ASCII_ARROW_RIGHT,*row,ASCII_ARROW_LEFT)
    print(" ", (ASCII_ARROW_UP+' ')*5)

def win(board):
    for row in board:
        if all(row[i]==row[i-1] and row[i]!=EMPTY for i in range(1,5)): 
            print(f"\u001b[1m{row[0]} WINS!")
            return True
    for i in range(5):
        if all(board[j][i]==board[j-1][i] and board[j][i]!=EMPTY for j in range(1,5)): 
            print(f"\u001b[1m{board[0][i]} WINS!")
            return True
    if all(board[i][i]==board[i-1][i-1] and board[i][i]!=EMPTY for i in range(1,5)):
        print(f"\u001b[1m{board[0][0]} WINS!")
        return True
    if all(board[i][4-i]==board[i-1][3-i] and board[i][4-i]!=EMPTY for i in range(1,5)):
        print(f"\u001b[1m{board[0][4]} WINS!")
        return True
    playable = False
    if any(board[i][0]==EMPTY for i in range(5)): playable = True
    if any(board[i][4]==EMPTY for i in range(5)): playable = True
    if any(board[0][i]==EMPTY for i in range(5)): playable = True
    if any(board[4][i]==EMPTY for i in range(5)): playable = True
    if not playable:
        print("\u001b[1mDRAW!"+'\u001b[47m')
        return True
    return False

def main():
    board = [ [EMPTY]*5 for _ in range(5) ]
    os.system('clear')
    print(Cursor.SAVE, end='')
    pboard(board)

    turn = 0
    move = input(f"ENTER {POINTER[turn&1]} [LRTB][1-5]: ").upper()
    while True:
        invalid = False
        if move.lower() in ['q','quit','exit']: raise KeyboardInterrupt
        if move[0] not in 'LRTB' or not move[1].isdigit() or not 1<=int(move[1])<=5: 
            print("\u001b[1A\u001b[2K", end='')
            move = input(f"ENTER {POINTER[turn&1]} [LRTB][1-5]: ").upper()
            continue
        print("MOVE RECORDED:",move)
        side, pos = move[0], int(move[1])
        if side == 'L':
            if board[pos-1][-1] != EMPTY: invalid = True
            else: board[pos-1] = [POINTER[turn&1]]+board[pos-1][:4]
        elif side == 'R':
            if board[pos-1][0] != EMPTY: invalid = True
            else: board[pos-1] = board[pos-1][1:]+[POINTER[turn&1]]
        elif side == 'B':
            if board[0][pos-1] != EMPTY: invalid = True
            else: 
                for i in range(4):
                    board[i][pos-1] = board[i+1][pos-1]
                board[4][pos-1] = POINTER[turn&1]
        elif side == 'T':
            if board[-1][pos-1] != EMPTY: invalid = True
            else: 
                for i in range(4,0,-1):
                    board[i][pos-1] = board[i-1][pos-1]
                board[0][pos-1] = POINTER[turn&1]
        if invalid: turn = turn^1
        os.system('clear')
        if win(board): break
        pboard(board)

        turn = turn^1
        move = input(f"ENTER {POINTER[turn&1]} [LRTB][1-5]: ").upper()

    if input('Replay [y/N]? : ').lower() in 'yes': main()

if __name__=='__main__': 
    print(RULES)
    print('\nPress any key to continue ...')
    r.readkey()
    os.system('clear')

    try: 
        while main(): ...
    except KeyboardInterrupt:
        print("\n\n\u001b[1mQuitting ...")
        quit()