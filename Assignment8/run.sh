#!/usr/local/bin/zsh
g++ -std=c++17 *.cpp
if [ $# -eq 0 ]
then
    ./a.out
else
    ./a.out < "$1"
fi


