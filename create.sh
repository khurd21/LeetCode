#!/bin/bash

read -p "Name of problem: " problem_name
directory_path="algorithms/cpp/$problem_name"
if [ -d "$directory_path" ]; then
    echo "Directory '$directory_path' already exists."
    exit 1
fi

mkdir -p "$directory_path"
cd "$directory_path"
touch solution.cpp solution.md
echo "Directory '$directory_path' and files 'solution.cpp' and 'solution.md' have been created."
