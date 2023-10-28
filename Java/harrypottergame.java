import java.util.Scanner;

public class harrypottergame {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int score = 0;

        System.out.println("Welcome to the Harry Potter Quiz!");
        System.out.println("Let's test your knowledge of the Wizarding World.");

        // Question 1
        System.out.println("\nQuestion 1: What is the name of Harry Potter's owl?");
        System.out.print("Your answer: ");
        String answer1 = scanner.nextLine();
        if (answer1.equalsIgnoreCase("Hedwig")) {
            System.out.println("Correct! Hedwig is the correct answer.");
            score++;
        } else {
            System.out.println("Sorry, that's incorrect. The correct answer is Hedwig.");
        }

        // Question 2
        System.out.println("\nQuestion 2: Who is the Half-Blood Prince?");
        System.out.print("Your answer: ");
        String answer2 = scanner.nextLine();
        if (answer2.equalsIgnoreCase("Severus Snape")) {
            System.out.println("Correct! Severus Snape is the Half-Blood Prince.");
            score++;
        } else {
            System.out.println("Sorry, that's incorrect. The correct answer is Severus Snape.");
        }

        // Question 3
        System.out.println("\nQuestion 3: What is the name of the train that takes students to Hogwarts?");
        System.out.print("Your answer: ");
        String answer3 = scanner.nextLine();
        if (answer3.equalsIgnoreCase("Hogwarts Express")) {
            System.out.println("Correct! The Hogwarts Express is the correct answer.");
            score++;
        } else {
            System.out.println("Sorry, that's incorrect. The correct answer is Hogwarts Express.");
        }

        // Display the final score
        System.out.println("\nYour final score is: " + score + " out of 3");

        // Provide a different message based on the score
        if (score == 3) {
            System.out.println("Congratulations! You are a true Harry Potter fan.");
        } else if (score > 0) {
            System.out.println("Well done! You know some Harry Potter trivia.");
        } else {
            System.out.println("Better luck next time. Keep reading the books!");
        }

        // Close the Scanner at the end of the program
        scanner.close();
    }
}
