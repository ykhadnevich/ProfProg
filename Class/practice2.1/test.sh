#!/bin/bash

run_test() {
    local input="$1"
    local expected_output="$2"
    local test_case_name="$3"

    echo "Running: $test_case_name"

    # Run the program with the given input
    OUTPUT=$(./task3 "$input")

    # Check if the output matches the expected output
    if [ "$OUTPUT" != "$expected_output" ]; then
        echo "Test case failed: $test_case_name"
        echo "Expected: $expected_output"
        echo "Got: $OUTPUT"
    else
        echo "Test case passed: $test_case_name"
    fi
}

./compile.sh

if [ $? -ne 0 ]; then
    echo "Compilation failed, aborting tests."
    exit 1
fi

run_test "Alice" "Welcome, Alice!" "Test Case 1: First Run with a New Name"

run_test "Alice" "Hello again(x2), Alice!" "Test Case 2: Second Run with the Same Name"

run_test "Bob" "Welcome, Bob!" "Test Case 3: First Run with Another New Name"
