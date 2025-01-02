#!/bin/bash

for test_file in inputs/*; do
    test_name=$(basename "$test_file")
    ./adjacency < "$test_file" > "outputs/${test_name}.out"
done
echo "done"