#include <iostream>
#include <vector>
#include <cmath>

// Function to find the largest negative value from a list of numbers
double findLargestNegative(const std::vector<double>& numbers) {
    double largestNegative = 0; // Initialize with 0 assuming all numbers are non-negative
    bool foundNegative = false;

    for (double num : numbers) {
        if (num < 0 && num < largestNegative) {
            largestNegative = num;
            foundNegative = true;
        }
    }

    if (!foundNegative) {
        std::cout << "No negative values found.\n";
    }

    return largestNegative;
}

// Function to calculate the roots of a quadratic equation
void calculateQuadraticRoots(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        std::cout << "Root 1: " << root1 << std::endl;
        std::cout << "Root 2: " << root2 << std::endl;
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        std::cout << "Double root: " << root << std::endl;
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        std::cout << "Root 1: " << realPart << " + " << imaginaryPart << "i" << std::endl;
        std::cout << "Root 2: " << realPart << " - " << imaginaryPart << "i" << std::endl;
    }
}

int main() {
    int choice;
    std::cout << "Which task would you like to perform?\n";
    std::cout << "1. Find the largest negative value from a list of numbers.\n";
    std::cout << "2. Calculate the roots of a quadratic equation.\n";
    std::cout << "Enter your choice (1 or 2): ";
    std::cin >> choice;

    if (choice == 1) {
        std::vector<double> numbers = {-1, 5, -10, 8, 3, -7};
        double largestNegative = findLargestNegative(numbers);

        if (largestNegative != 0) {
            std::cout << "The largest negative value is: " << largestNegative << std::endl;
        }
    } else if (choice == 2) {
        double a, b, c;
        std::cout << "Enter the coefficients (a, b, c) of the quadratic equation: ";
        std::cin >> a >> b >> c;

        calculateQuadraticRoots(a, b, c);
    } else {
        std::cout << "Invalid choice. Please enter 1 or 2.\n";
    }

    return 0;
}
