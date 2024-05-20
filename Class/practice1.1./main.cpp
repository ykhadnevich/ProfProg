#include <iostream>
#include <vector>
#include <cmath>
#include <ranges>

// 1. It is better to use optional as a result and use ranges to make it more redable
// 2. We are returning 0 in your implementation in case of absent negative values
//    and therefore every client of this function should know or check to find this convention.
//    It is better to use the type that is was created for it std::optional or std::expected
std::optional<double> findLargestNegative(const std::vector<double>& numbers) {
    // this function can be rewritten with ranges:
    auto negativeValues = numbers | std::views::filter([](double x) { return x < 0; });
    if (negativeValues.empty()) {
        return {};
    }
    return *std::ranges::max(negativeValues);
}

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

// It is better to split calculation logic and output logic into separate functions
// For example you can create simple structure QuadraticEquationSolver with an API
// that allows you to caclulateRoots of a quadratic equation that returns std::vector<double>
// or other type and in a separate function or even in main we handle the results and provide output.

// Function to calculate the roots of a quadratic equation
void calculateQuadraticRoots(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        // We are dividing by a but what if it equals to 0?
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        std::cout << "Root 1: " << root1 << std::endl;
        std::cout << "Root 2: " << root2 << std::endl;
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        std::cout << "Double root: " << root << std::endl;
    } else {
        // Standard library provides complex numbers in C++
        // https://en.cppreference.com/w/cpp/numeric/complex
        // therefore we can use that module to perform calculations in this function
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

    // In general it is better to have all the handlers for different scenarios as separate functions
    // and then call them from main function based on user choice.
    // Of course in this case we have small amount of code but in case of scaling it may become less readable
    // You can use something like:
    // switch (choise) {
    //   case 1: handleLargestNegative(); break;
    //   case 2: handleQuadraticRoots(); break;
    //   default: std::cout << "Invalid choice. Please enter 1 or 2.\n"; break;
    //}
    if (choice == 1) {
        // This input should be provided by a user so we should prompt him for that
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
