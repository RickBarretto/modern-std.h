#!/bin/bash

gcc -o test.exe test.c \
    results.c \
    ../unitc/unitc.c \
    -I"../../" \
    -Wall -Wextra -Wpedantic -Wshadow

echo
echo "====~=~=~=~=~====~=~=~=~=~===="
echo

./test.exe

rm ./test.exe