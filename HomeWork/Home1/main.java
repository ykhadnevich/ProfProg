import java.util.Scanner;

// Please check the comments from class work:
// we also can use java tools to handle and filter lists
// also encapsulation and some checks should be applied.
public class main {
    // Function to find the largest negative value from a list of numbers
    public static double findLargestNegative(double[] numbers) {
        double largestNegative = 0; // Initialize with 0 assuming all numbers are non-negative
        boolean foundNegative = false;

        for (double num : numbers) {
            if (num < 0 && num < largestNegative) {
                largestNegative = num;
                foundNegative = true;
            }
        }

        if (!foundNegative) {
            System.out.println("No negative values found.");
        }

        return largestNegative;
    }

    // Function to calculate the roots of a quadratic equation
    public static void calculateQuadraticRoots(double a, double b, double c) {
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            double root1 = (-b + Math.sqrt(discriminant)) / (2 * a);
            double root2 = (-b - Math.sqrt(discriminant)) / (2 * a);
            System.out.println("Root 1: " + root1);
            System.out.println("Root 2: " + root2);
        } else if (discriminant == 0) {
            double root = -b / (2 * a);
            System.out.println("Double root: " + root);
        } else {
            double realPart = -b / (2 * a);
            double imaginaryPart = Math.sqrt(-discriminant) / (2 * a);
            System.out.println("Root 1: " + realPart + " + " + imaginaryPart + "i");
            System.out.println("Root 2: " + realPart + " - " + imaginaryPart + "i");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Which task would you like to perform?");
        System.out.println("1. Find the largest negative value from a list of numbers.");
        System.out.println("2. Calculate the roots of a quadratic equation.");
        System.out.print("Enter your choice (1 or 2): ");
        int choice = scanner.nextInt();

        if (choice == 1) {
            double[] numbers = {-1, 5, -10, 8, 3, -7};
            double largestNegative = findLargestNegative(numbers);

            if (largestNegative != 0) {
                System.out.println("The largest negative value is: " + largestNegative);
            }
        } else if (choice == 2) {
            System.out.print("Enter the coefficients (a, b, c) of the quadratic equation: ");
            double a = scanner.nextDouble();
            double b = scanner.nextDouble();
            double c = scanner.nextDouble();

            calculateQuadraticRoots(a, b, c);
        } else {
            System.out.println("Invalid choice. Please enter 1 or 2.");
        }

        scanner.close();
    }
}
