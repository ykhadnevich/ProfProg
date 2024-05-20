#!/bin/bash

# I hope that it should be to scripts - one for compilation with forwarding args $@
# and one for testing which will call compilation script.
# Compile the C++ program
clang++ -std=c++23 -Wall -Wextra -Wpedantic -Werror task3.cpp -o task3

# For test cases it is necessary to check the expected result
# We do some things and then check the result
# and then we do some other thing and check the result.
# In this case it should be something like this:
OUTPUT=$(./task3 Alice)
if [ "$OUTPUT" != "Welcome, Alice!" ]; then
    echo "Test case failed"
fi

OUTPUT=$(./task3 Alice)
if [ "$OUTPUT" != "Hello again(x2), Alice!" ]; then
    echo "Test case failed"
fi
# And of course it is better to write some helper functions that will perform similar type of check and will write proper error messages.



# Test Case 1: First Run with a New Name
echo "Test Case 1: First Run with a New Name"
./task3 Alice
./task3 Alice

# Test cases should be isolated - you can not just run one after another in line - some environment reset should be done
# to ensure that prerequisites for test case are satisfied.
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
