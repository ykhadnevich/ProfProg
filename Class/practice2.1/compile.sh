#!/bin/bash

clang++ -std=c++23 -Wall -Wextra -Wpedantic -Werror "$@" task3.cpp -o task3

if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
else
    echo "Compilation succeeded"
fi
