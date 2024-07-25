import java.util.Scanner;

public class Main {
    
    // Function to find the largest negative value from a list of numbers
    public static double findLargestNegative(double[] numbers) {
        double largestNegative = Double.NEGATIVE_INFINITY;
        
        for (double num : numbers) {
            if (num < 0 && num > largestNegative) {
                largestNegative = num;
            }
        }
        
        return largestNegative != Double.NEGATIVE_INFINITY ? largestNegative : Double.NaN;
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
    
    // Function to handle finding the largest negative number
    public static void handleLargestNegative() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter numbers separated by spaces: ");
        String input = scanner.nextLine();
        
        String[] parts = input.split(" ");
        double[] numbers = new double[parts.length];
        
        for (int i = 0; i < parts.length; i++) {
            numbers[i] = Double.parseDouble(parts[i]);
        }
        
        double largestNegative = findLargestNegative(numbers);
        if (!Double.isNaN(largestNegative)) {
            System.out.println("The largest negative number is: " + largestNegative);
        } else {
            System.out.println("No negative numbers found.");
        }
    }
    
    // Function to handle calculating quadratic roots
    public static void handleQuadraticRoots() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter coefficients a, b, and c: ");
        double a = scanner.nextDouble();
        double b = scanner.nextDouble();
        double c = scanner.nextDouble();
        
        if (a == 0) {
            System.out.println("Coefficient 'a' cannot be zero.");
            return;
        }
        
        calculateQuadraticRoots(a, b, c);
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Which task would you like to perform?");
        System.out.println("1. Find the largest negative value from a list of numbers.");
        System.out.println("2. Calculate the roots of a quadratic equation.");
        System.out.println("Enter your choice (1 or 2): ");
        int choice = scanner.nextInt();
        
        switch (choice) {
            case 1:
                handleLargestNegative();
                break;
            case 2:
                handleQuadraticRoots();
                break;
            default:
                System.out.println("Invalid choice. Please enter 1 or 2.");
                break;
        }
    }
}
