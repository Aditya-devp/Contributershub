import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        char[][] board = new char[3][3];
        for (char[] chars : board) {
            Arrays.fill(chars, ' ');
        }
        Scanner scanner = new Scanner(System.in);
        boolean gameOver = false;
        char player = 'X';
        int x = 0;
        int y = 0;
        while (!gameOver){
            showBoard(board);
            System.out.print(player+" enter coordinates : ");
            try{
                x = scanner.nextInt();
                y = scanner.nextInt();
            }catch (Exception e){
                System.out.println("invalid input");
                return;
            }

            System.out.println();
            if(isValid(board,x,y)){
                board[x][y] = player;
                if(isWon(board,player)){
                    System.out.println("congratulations "+player+" you won");
                    showBoard(board);
                    gameOver = true;
                }
                if(movesOver(board)){
                    System.out.println("Game Over");
                    return;
                }
                if(player == 'X'){
                    player = 'O';
                }else{
                    player = 'X';
                }
            }else{
                System.out.println("invalid move, try again");
            }
        }
    }
    private static boolean movesOver(char[][] board){
        for (char[] chars : board) {
            for (char aChar : chars) {
                if (aChar == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    private static boolean isWon(char[][] board, char player) {

        //check for row
        for (char[] chars : board) {
            if (chars[0] == player && chars[1] == player && chars[2] == player) {
                return true;
            }
        }

        //check for column
        for(int col = 0 ; col < board.length ; col++){
            if(board[0][col] == player && board[1][col] == player && board[2][col] == player  ){
                return true;
            }
        }

        for(int row = 0 ; row < board.length ; row++){
            if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
                return true;
            }
            if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
                return true;
            }
        }
        return false;
    }

    private static boolean isValid(char[][] board, int x, int y) {

        if(x > 2 || y > 2 || x < 0 || y < 0){
            return false;
        }
        return board[x][y] == ' ';
    }

    private static void showBoard(char[][] board) {
        for (char[] chars : board) {
            for (char aChar : chars) {
                System.out.print(aChar + " | ");
            }
            System.out.println();
        }
    }
}
