#include "RectangleManager.hpp"
#include <iostream>
#include <limits>
#include <algorithm>

void RectangleManager::addRectangle(double width, double height) {
    if (rectangles.size() < maxRectangles) {
        rectangles.emplace_back(width, height);
    }
}

void RectangleManager::displayPlacementPossibilities() const {
    for (size_t i = 0; i < rectangles.size(); ++i) {
        for (size_t j = 0; j < rectangles.size(); ++j) {
            if (i != j && rectangles[i].canBePlacedInside(rectangles[j])) {
                std::cout << "Rectangle " << i + 1 << " can be placed inside Rectangle " << j + 1 << std::endl;
            }
        }
    }
}

double RectangleManager::getBiggestArea() const {
    double biggestArea = 0;
    for (const auto &rectangle : rectangles) {
        if (rectangle.getArea() > biggestArea) {
            biggestArea = rectangle.getArea();
        }
    }
    return biggestArea;
}

double RectangleManager::getSmallestArea() const {
    double smallestArea = std::numeric_limits<double>::max();
    for (const auto &rectangle : rectangles) {
        if (rectangle.getArea() < smallestArea) {
            smallestArea = rectangle.getArea();
        }
    }
    return smallestArea;
}

double RectangleManager::getTotalArea() const {
    double totalArea = 0;
    for (const auto &rectangle : rectangles) {
        totalArea += rectangle.getArea();
    }
    return totalArea;
}

void RectangleManager::displayBiggestSides() const {
    for (size_t i = 0; i < rectangles.size(); ++i) {
        std::cout << "The biggest side of rectangle " << i + 1 << ": " << rectangles[i].getBiggerSide() << std::endl;
    }
}
