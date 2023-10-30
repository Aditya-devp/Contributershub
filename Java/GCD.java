import java.util.Scanner;

public class GCD {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the first number: ");
        int num1 = scanner.nextInt();
        System.out.print("Enter the second number: ");
        int num2 = scanner.nextInt();
        scanner.close();

        int gcd = calculateGCD(num1, num2);
        System.out.println("GCD of " + num1 + " and " + num2 + " is " + gcd);
    }

    // Function to calculate the GCD using the Euclidean algorithm
    public static int calculateGCD(int a, int b) {
        if (b == 0) {
            return a;
        }
        return calculateGCD(b, a % b);
    }
}
