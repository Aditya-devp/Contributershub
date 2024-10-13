package gameProject1;
import java.util.Scanner;

class guesser{
    int guessNum;
    int guessingNum(){
        try (Scanner scan = new Scanner(System.in)) {
            System.out.println("Kindly guess the number!!");
            guessNum = scan.nextInt();
        }
        return guessNum;
    }
}

class player{
    int guessedNum;
    int decodeNum(){
        try(Scanner scan = new Scanner(System.in)){
            System.out.println("Kindly guess your number to decode the number by guess!!");
            guessedNum = scan.nextInt();           
        }
        return guessedNum;
    }
}

class umpire{
    int numFromGuesser;
    int numFromPlayer1;
    int numFromPlayer2;
    int numFromPlayer3;
    int numFromPlayer4;

    void collectNumFromGuesser(){
        guesser g = new guesser();
        numFromGuesser = g.guessingNum();
    }
    void collectNumFromPlayers(){
        player p1 = new player();
        player p2 = new player();
        player p3 = new player();
        player p4 = new player();
        numFromPlayer1 = p1.decodeNum();
        numFromPlayer2 = p2.decodeNum();
        numFromPlayer2 = p3.decodeNum();
        numFromPlayer2 = p4.decodeNum();
    }
    void compare(){
        if (numFromGuesser == numFromPlayer1){
            if(numFromGuesser == numFromPlayer2 && numFromGuesser == numFromPlayer3 && numFromGuesser == numFromPlayer4){
                System.out.println("All the players won :)");
            }
            else if(numFromGuesser == numFromPlayer2 && numFromGuesser == numFromPlayer3 && numFromGuesser != numFromPlayer4 ){
                System.out.println("Player 1, 2 and 3 won :)");
            }
            else if(numFromGuesser == numFromPlayer2 && numFromGuesser == numFromPlayer4 && numFromGuesser != numFromPlayer3 ){
                System.out.println("Player 1, 2 and 4 won :)");
            }
            else if(numFromGuesser != numFromPlayer2 && numFromGuesser == numFromPlayer3 && numFromGuesser == numFromPlayer4 ){
                System.out.println("Player 1, 3 and 4 won :)");
            }
            else if(numFromGuesser == numFromPlayer2 && numFromGuesser != numFromPlayer3 && numFromGuesser != numFromPlayer4 ){
                System.out.println("Player 1 and 2 won :)");
            }
            else if(numFromGuesser != numFromPlayer2 && numFromGuesser == numFromPlayer3 && numFromGuesser != numFromPlayer4 ){
                System.out.println("Player 1 and 3 won :)");
            }
            else if(numFromGuesser != numFromPlayer2 && numFromGuesser != numFromPlayer3 && numFromGuesser == numFromPlayer4 ){
                System.out.println("Player 1 and 4 won :)");
            }
            else{
                System.out.println("Player 1 is the winner :)");
            }
            }
        else if (numFromGuesser == numFromPlayer2){
            if(numFromGuesser == numFromPlayer3 && numFromGuesser == numFromPlayer4 ){
                System.out.println("Player 2, 3 and 4 won :)");
            }
            else if(numFromGuesser == numFromPlayer3 && numFromGuesser != numFromPlayer4 ){
                System.out.println("Player 2 and 3 won :)");
            }
            else if(numFromGuesser != numFromPlayer3 && numFromGuesser == numFromPlayer4 ){
                System.out.println("Player 2 and 4 won :)");
            }
            else{
                System.out.println("Player 2 is the winner :)");
            }
            }
        else if (numFromGuesser == numFromPlayer3){
            if(numFromGuesser == numFromPlayer4 ){
                System.out.println("Player 3 and 4 won :)");
            }
            else{
                System.out.println("Player 3 is the winner :)");
            }
        }
        else if (numFromGuesser == numFromPlayer4){
            System.out.println("Player 4 is the winner :)");
        }
        else {
            System.out.println("No oone decoded the number, Everyone lose :( ");
        }
    }
}

class guesserGameLaunch{
    public static void main(String[] args){
        System.out.println("heyy, let's start the game!!");
        umpire u = new umpire();
        u.collectNumFromGuesser();
        u.collectNumFromPlayers();
        u.compare();
    }
}