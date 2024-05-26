#include <iostream>
#include "Helpers.hpp"
#include "UnitTest.hpp"

int main() {
    UnitTests testSuite;

    testSuite.addTest("Dummy_test1",
    [](){
        // Build:
        double value = 0.0;
    
        // Operate:
        auto result = dummyFunc(value);

        // Check:
        ASSERT_EQ(result, 0.0);
    });

    testSuite.addTest("Dummy_test2",
    [](){
        // Build:
        double value = -1.0;

        // Operate:
        auto result = dummyFunc(value);

        // Check:
        ASSERT_EQ(result, 0.0); // Test negative input
    });

    testSuite.addTest("Dummy_test3",
    [](){
        // Build:
        double value = 3.5;

        // Operate:
        auto result = dummyFunc(value);

        // Check:
        ASSERT_EQ(result, 3.5); // Test positive input
    });

    testSuite.addTest("RepeatString_test1",
    [](){
        // Build:
        std::vector<int> vec = {0, 2, 1};
        std::string str = "home";

        // Operate:
        auto result = repeatString(vec, str);

        // Check:
        ASSERT_EQ(result, "homehome");
    });

    testSuite.addTest("RepeatString_test2",
    [](){
        // Build:
        std::vector<int> vec = {1, 1, 1};
        std::string str = "test";

        // Operate:
        auto result = repeatString(vec, str);

        // Check:
        ASSERT_EQ(result, "test");
    });

    testSuite.addTest("RepeatString_test3",
    [](){
        // Build:
        std::vector<int> vec = {3, 3, 3};
        std::string str = "abc";

        // Operate:
        auto result = repeatString(vec, str);

        // Check:
        ASSERT_EQ(result, "abcabcabc");
    });

    testSuite.addTest("RepeatString_test4",
    [](){
        // Build:
        std::vector<int> vec = {0, 0, 0};
        std::string str = "xyz";

        // Operate:
        auto result = repeatString(vec, str);

        // Check:
        ASSERT_EQ(result, "");
    });

    testSuite.addTest("RepeatString_test5",
    [](){
        // Build:
        std::vector<int> vec = {};
        std::string str = "empty";

        // Operate:
        auto result = repeatString(vec, str);

        // Check:
        ASSERT_EQ(result, "");
    });

    testSuite.run();
}
