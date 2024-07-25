#include "UnitTest.hpp"
#include <functional> // Add this for std::function
#include <vector>     // Add this for std::vector

class Color {
public:
    Color(int r, int g, int b) : red(r), green(g), blue(b) {}

    void generateMagicColor() {
        // Applying the rules
        red = red / 2 - 1;
        green = green * 2 - 2;
        // No changes for blue component
    }

    int getRed() const { return red; }
    int getGreen() const { return green; }
    int getBlue() const { return blue; }

private:
    int red, green, blue;
};
