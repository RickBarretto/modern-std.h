#!/bin/bash

gcc -o test.exe test.c \
    optionals.c \
    ../unitc/unitc.c \
    -I"../../"

echo
echo "====~=~=~=~=~====~=~=~=~=~===="
echo

./test.exe

rm ./test.exe