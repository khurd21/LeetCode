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

echo "Please paste your solution content below. Press Ctrl+D when you're done:"
solution_content=$(cat)
echo "$solution_content" > solution.cpp
echo "Content has been written to 'solution.cpp'."

echo "Please paste your problem description below. Press Ctrl+D when you're done:"
problem_content=$(cat)
echo "$problem_content" > solution.md
echo "Content has been written to 'solution.md'."
