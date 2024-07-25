#!/bin/bash

# Compile the C++ program
cd ~/ProfProg/Class/practice2.1 || exit
clang++ -std=c++23 -Wall -Wextra -Wpedantic -Werror task3.cpp -o task3

# Run Test Cases
echo "Running Test Cases:"

# Test Case 1: First Run with a New Name
echo "Test Case 1: First Run with a New Name"
./task3 Alice
./task3 Alice

# Test Case 2: Multiple Runs with the Same Name
echo "Test Case 2: Multiple Runs with the Same Name"
./task3 Bob
./task3 Bob
./task3 Bob

# Test Case 3: Reset Statistics for a Given Name
echo "Test Case 3: Reset Statistics for a Given Name"
./task3 Charlie
./task3 Charlie delete
./task3 Charlie

# Test Case 4: Use the Secret Word to Exterminate All History
echo "Test Case 4: Use the Secret Word to Exterminate All History"
./task3 Dave
./task3 Eve
./task3 bread
./task3 Dave
./task3 Eve

# Test Case 5: Handle Incorrect Number of Arguments
echo "Test Case 5: Handle Incorrect Number of Arguments"
./task3
./task3 name delete extra
./task3 name

# Clean up
rm -f task3

echo "All test cases executed."
