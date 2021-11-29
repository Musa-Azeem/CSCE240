#!/usr/bin/env bash
g++ -std=c++17 *.cpp -o main
if [ $# -eq 0 ]
then
    ./main
else
    ./main < "$1"
fi


