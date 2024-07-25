#!/bin/bash

# Directories
SCRIPT_DIR="$HOME/ProfProg/HomeWork/Home2"
SOURCE_DIR_CPP="$HOME/ProfProg/Class/practice2.1"

# Database file
DATABASE_FILE="$SCRIPT_DIR/user_stats.txt"

# Clean up any existing database file
rm -f $DATABASE_FILE

# Function to run the C++ or Java program
run_program() {
    local language=$1
    shift
    if [ "$language" == "cpp" ]; then
        ./task "$@" > output.txt
    elif [ "$language" == "java" ]; then
        java task "$@" > output.txt
    fi
}

# Function to compile the C++ or Java program
compile_program() {
    local language=$1
    if [ "$language" == "cpp" ]; then
        cd $SOURCE_DIR_CPP
        g++ -o $SCRIPT_DIR/task task3.cpp
        cd $SCRIPT_DIR
    elif [ "$language" == "java" ]; then
        cd $SCRIPT_DIR
        javac task.java
    fi
}

# Function to check the output against the expected result
assert_output() {
    local expected=$1
    local actual=$(cat output.txt)
    if [ "$expected" == "$actual" ]; then
        echo "PASS"
    else
        echo "FAIL: Expected '$expected' but got '$actual'"
    fi
}

# Function to run tests for the C++ or Java program
test_program() {
    local language=$1

    # Compile the program
    compile_program $language

    # Test 1: Add a new user
    echo "Test 1 ($language): Add a new user 'alice'"
    run_program $language alice
    assert_output "Welcome, alice!"

    # Test 2: Greet an existing user
    echo "Test 2 ($language): Greet existing user 'alice'"
    run_program $language alice
    assert_output "Hello again(x1), alice!"

    # Test 3: Add another new user
    echo "Test 3 ($language): Add a new user 'bob'"
    run_program $language bob
    assert_output "Welcome, bob!"

    # Test 4: Delete a user
    echo "Test 4 ($language): Delete user 'alice'"
    run_program $language alice delete
    assert_output "Statistics for alice have been reset."

    # Test 5: Verify user 'alice' is reset
    echo "Test 5 ($language): Verify user 'alice' is reset"
    run_program $language alice
    assert_output "Welcome, alice!"

    # Test 6: Use the secret word to exterminate all history
    echo "Test 6 ($language): Use the secret word to exterminate all history"
    run_program $language bread
    assert_output "All history exterminated."

    # Test 7: Verify all data is cleared
    echo "Test 7 ($language): Verify all data is cleared"
    run_program $language bob
    assert_output "Welcome, bob!"

    # Clean up the program's output and compiled files
    if [ "$language" == "cpp" ]; then
        rm -f output.txt task
    elif [ "$language" == "java" ]; then
        rm -f output.txt task.class
    fi
}

# Check input parameter
if [ $# -ne 1 ]; then
    echo "Usage: $0 <cpp|java>"
    exit 1
fi

# Run the appropriate test based on the input parameter
if [ "$1" == "cpp" ]; then
    test_program cpp
elif [ "$1" == "java" ]; then
    test_program java
else
    echo "Invalid parameter. Use 'cpp' to test the C++ program or 'java' to test the Java program."
    exit 1
fi

# Clean up the database file
rm -f $DATABASE_FILE
