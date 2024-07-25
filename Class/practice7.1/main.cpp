#include "UnitTests.hpp"
#include "RectangleManager.hpp"

int main() {
    UnitTests tests;

    tests.addTest("Test Rectangle Area Calculation", []() {
        Rectangle r1(2.0, 3.0);
        ASSERT_EQ(r1.getArea(), 6.0);

        Rectangle r2(4.0, 5.0);
        ASSERT_EQ(r2.getArea(), 20.0);
    });

    tests.addTest("Test Rectangle Bigger Side Calculation", []() {
        Rectangle r1(2.0, 3.0);
        ASSERT_EQ(r1.getBiggerSide(), 3.0);

        Rectangle r2(4.0, 5.0);
        ASSERT_EQ(r2.getBiggerSide(), 5.0);
    });

    tests.addTest("Test Rectangle Placement Inside Another Rectangle", []() {
        Rectangle r1(2.0, 3.0);
        Rectangle r2(4.0, 5.0);

        ASSERT_EQ(r1.canBePlacedInside(r2), true);
        ASSERT_EQ(r2.canBePlacedInside(r1), false);
    });

    tests.addTest("Test Rectangle Manager Functions", []() {
        RectangleManager manager;
        manager.addRectangle(2.0, 3.0); 
        manager.addRectangle(4.0, 5.0); 
        manager.addRectangle(1.0, 1.0); 
        manager.addRectangle(3.0, 3.0); 
        manager.addRectangle(2.0, 2.0); 
        ASSERT_EQ(manager.getBiggestArea(), 20.0);
        ASSERT_EQ(manager.getSmallestArea(), 1.0);
        ASSERT_EQ(manager.getTotalArea(), 40.0); 
    });

    tests.run();

    return 0;
}
