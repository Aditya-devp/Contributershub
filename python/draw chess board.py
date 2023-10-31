import turtle

# Constants for chessboard dimensions
BOARD_SIZE = 8
SQUARE_SIZE = 50
BOARD_START_X = -200
BOARD_START_Y = 200

# Chess pieces
pieces = [
    "♜", "♞", "♝", "♛", "♚", "♝", "♞", "♜",
    "♟", "♟", "♟", "♟", "♟", "♟", "♟", "♟",
    "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", "",
    "♙", "♙", "♙", "♙", "♙", "♙", "♙", "♙",
    "♖", "♘", "♗", "♕", "♔", "♗", "♘", "♖",
]

def draw_chessboard():
    turtle.penup()
    for i in range(BOARD_SIZE):
        for j in range(BOARD_SIZE):
            x = BOARD_START_X + j * SQUARE_SIZE
            y = BOARD_START_Y - i * SQUARE_SIZE
            turtle.goto(x, y)
            turtle.pendown()
            turtle.color("red" if (i + j) % 2 == 0 else "white")
            turtle.begin_fill()
            for _ in range(4):
                turtle.forward(SQUARE_SIZE)
                turtle.right(90)
            turtle.end_fill()

def draw_pieces():
    turtle.penup()
    for i in range(BOARD_SIZE):
        for j in range(BOARD_SIZE):
            piece_idx = i * BOARD_SIZE + j
            piece = pieces[piece_idx]
            if piece:
                x = BOARD_START_X + j * SQUARE_SIZE + SQUARE_SIZE // 2
                y = BOARD_START_Y - i * SQUARE_SIZE - SQUARE_SIZE // 2
                turtle.goto(x, y)
                turtle.write(piece, align="center", font=("Arial", 24, "normal"))

def main():
    turtle.speed(0)
    turtle.hideturtle()
    turtle.bgcolor("white")
    draw_chessboard()
    draw_pieces()
    turtle.done()

if __name__ == "__main__":
    main()
