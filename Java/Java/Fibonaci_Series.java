package Programming.Contributershub.Java.Java;

import java.util.Scanner;
public class Fibonaci_Series {
        public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter the upper bound for the Fibonacci series: ");
            int upperBound = scanner.nextInt();

            int num1 = 0, num2 = 1, nextTerm;

            System.out.println("Fibonacci Series up to " + upperBound + " terms:");

            while (num1 <= upperBound) {
                System.out.print(num1 + " ");
                nextTerm = num1 + num2;
                num1 = num2;
                num2 = nextTerm;
            }
        }
    }


