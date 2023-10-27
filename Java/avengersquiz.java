import java.util.Scanner;

public class avengersquiz {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int score = 0;

        System.out.println("Welcome to the Avengers Quiz!");
        System.out.println("Let's test your knowledge of Earth's mightiest heroes.");

        // Question 1
        System.out.println("\nQuestion 1: Who is known as the God of Thunder?");
        System.out.print("Your answer: ");
        String answer1 = scanner.nextLine();
        if (answer1.equalsIgnoreCase("Thor")) {
            System.out.println("Correct! Thor is the God of Thunder.");
            score++;
        } else {
            System.out.println("Sorry, that's incorrect. The correct answer is Thor.");
        }

        // Question 2
        System.out.println("\nQuestion 2: What is Tony Stark's superhero alter ego?");
        System.out.print("Your answer: ");
        String answer2 = scanner.nextLine();
        if (answer2.equalsIgnoreCase("Iron Man")) {
            System.out.println("Correct! Tony Stark is also known as Iron Man.");
            score++;
        } else {
            System.out.println("Sorry, that's incorrect. The correct answer is Iron Man.");
        }

        // Question 3
        System.out.println("\nQuestion 3: What is Captain America's shield made of?");
        System.out.print("Your answer: ");
        String answer3 = scanner.nextLine();
        if (answer3.equalsIgnoreCase("Vibranium")) {
            System.out.println("Correct! Captain America's shield is made of Vibranium.");
            score++;
        } else {
            System.out.println("Sorry, that's incorrect. The correct answer is Vibranium.");
        }

        // Display the final score
        System.out.println("\nYour final score is: " + score + " out of 3");

        // Provide a different message based on the score
        if (score == 3) {
            System.out.println("Congratulations! You are a true Avengers fan.");
        } else if (score > 0) {
            System.out.println("Well done! You know some Avengers trivia.");
        } else {
            System.out.println("Better luck next time. Keep watching the movies!");
        }

        // Close the Scanner at the end of the program
        scanner.close();
    }
}
