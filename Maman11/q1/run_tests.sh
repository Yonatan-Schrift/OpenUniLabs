#!/bin/bash

for test_file in tests/*; do
    test_name=$(basename "$test_file")
    ./letters < "$test_file" > "outputs/${test_name}.out"
done