#include <iostream>
#include <vector>
#include <cmath>
#include <optional>
#include <limits>
#include <sstream>
#include <algorithm>

using namespace std;

optional<double> findLargestNegative(const vector<double>& numbers) {
    vector<double> negativeValues;
    copy_if(numbers.begin(), numbers.end(), back_inserter(negativeValues), [](double x) { return x < 0; });

    if (negativeValues.empty()) {
        return nullopt;
    }
    
    return *max_element(negativeValues.begin(), negativeValues.end());
}

double findLargestNegativeOld(const vector<double>& numbers) {
    double largestNegative = 0; 
    bool foundNegative = false;

    for (double num : numbers) {
        if (num < 0 && (!foundNegative || num > largestNegative)) {
            largestNegative = num;
            foundNegative = true;
        }
    }
    if (!foundNegative) {
        cout << "No negative values found.\n";
    }
    return largestNegative;
}

void calculateQuadraticRoots(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Root 1: " << root1 << endl;
        cout << "Root 2: " << root2 << endl;
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        cout << "Double root: " << root << endl;
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "Root 1: " << realPart << " + " << imaginaryPart << "i" << endl;
        cout << "Root 2: " << realPart << " - " << imaginaryPart << "i" << endl;
    }
}

void handleLargestNegative() {
    vector<double> numbers;
    string input;
    cout << "Enter numbers separated by spaces: ";
    cin.ignore(); 
    getline(cin, input);
    
    stringstream ss(input);
    double number;
    while (ss >> number) {
        numbers.push_back(number);
    }

    auto largestNegativeOpt = findLargestNegative(numbers);
    if (largestNegativeOpt) {
        cout << "The largest negative number is: " << *largestNegativeOpt << endl;
    } else {
        cout << "No negative numbers found." << endl;
    }
}

void handleQuadraticRoots() {
    double a, b, c;
    cout << "Enter coefficients a, b, and c: ";
    cin >> a >> b >> c;
    if (a == 0) {
        cout << "Coefficient 'a' cannot be zero." << endl;
        return;
    }
    calculateQuadraticRoots(a, b, c);
}

int main() {
    int choice;
    cout << "Which task would you like to perform?\n";
    cout << "1. Find the largest negative value from a list of numbers.\n";
    cout << "2. Calculate the roots of a quadratic equation.\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    switch (choice) {
        case 1:
            handleLargestNegative();
            break;
        case 2:
            handleQuadraticRoots();
            break;
        default:
            cout << "Invalid choice. Please enter 1 or 2.\n";
            break;
    }

    return 0;
}
