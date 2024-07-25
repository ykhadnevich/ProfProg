#include "UnitTest.hpp"
#include <cmath>
#include <functional> // Add this for std::function
#include <vector>     // Add this for std::vector

class Triangle {
public:
    Triangle(double a, double b, double c) : sideA(a), sideB(b), sideC(c) {}

    double calculateArea() const {
        // Heron's formula to calculate the area of a triangle
        double s = (sideA + sideB + sideC) / 2;
        return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }

private:
    double sideA, sideB, sideC;
};

int main() {
    UnitTests tests; // Corrected class name

    // Test case for Triangle class
    tests.addTest("TriangleAreaTest", [](){
        Triangle triangle(3, 4, 5);
        ASSERT_EQ(triangle.calculateArea(), 6.0);
    });

    // Run the tests
    tests.run();

    return 0;
}
