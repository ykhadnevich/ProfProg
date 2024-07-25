#pragma once
#include <vector>
#include "Rectangle.hpp"

class RectangleManager {
public:
    void addRectangle(double width, double height);
    void displayPlacementPossibilities() const;
    double getBiggestArea() const;
    double getSmallestArea() const;
    double getTotalArea() const;
    void displayBiggestSides() const;

private:
    std::vector<Rectangle> rectangles;
    static const size_t maxRectangles = 5;
};
