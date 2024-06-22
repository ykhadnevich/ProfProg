#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Rectangle {
public:
    Rectangle(double width, double height) : width(width), height(height) {}

    double getWidth() const {
        return width;
    }

    double getHeight() const {
        return height;
    }

    double getArea() const {
        return width * height;
    }

    double getBiggerSide() const {
        return std::max(width, height);
    }

    bool canBePlacedInside(const Rectangle &other) const {
        return width <= other.width && height <= other.height;
    }

private:
    double width;
    double height;
};

class RectangleManager {
public:
    void addRectangle(double width, double height) {
        if (rectangles.size() < maxRectangles) {
            rectangles.emplace_back(width, height);
        }
    }

    void displayPlacementPossibilities() const {
        for (size_t i = 0; i < rectangles.size(); ++i) {
            for (size_t j = 0; j < rectangles.size(); ++j) {
                if (i != j && rectangles[i].canBePlacedInside(rectangles[j])) {
                    std::cout << "Rectangle " << i + 1 << " can be placed inside Rectangle " << j + 1 << std::endl;
                }
            }
        }
    }

    double getBiggestArea() const {
        double biggestArea = 0;
        for (const auto &rectangle : rectangles) {
            if (rectangle.getArea() > biggestArea) {
                biggestArea = rectangle.getArea();
            }
        }
        return biggestArea;
    }

    double getSmallestArea() const {
        double smallestArea = std::numeric_limits<double>::max();
        for (const auto &rectangle : rectangles) {
            if (rectangle.getArea() < smallestArea) {
                smallestArea = rectangle.getArea();
            }
        }
        return smallestArea;
    }

    void displayBiggestSides() const {
        for (size_t i = 0; i < rectangles.size(); ++i) {
            std::cout << "The biggest side of rectangle " << i + 1 << ": " << rectangles[i].getBiggerSide() << std::endl;
        }
    }

    double getTotalArea() const {
        double totalArea = 0;
        for (const auto &rectangle : rectangles) {
            totalArea += rectangle.getArea();
        }
        return totalArea;
    }

private:
    std::vector<Rectangle> rectangles;
    static const size_t maxRectangles = 5;
};

int main() {
    RectangleManager manager;

    for (int i = 1; i <= 5; ++i) {
        double width, height;
        std::cout << "Enter rectangle " << i << ":" << std::endl;
        if (std::cin >> width >> height) {
            manager.addRectangle(width, height);
        }
    }

    manager.displayPlacementPossibilities();

    std::cout << "The biggest area: " << manager.getBiggestArea() << std::endl;
    std::cout << "The smallest area: " << manager.getSmallestArea() << std::endl;

    manager.displayBiggestSides();

    std::cout << "Total area of rectangles: " << manager.getTotalArea() << std::endl;

    return 0;
}
