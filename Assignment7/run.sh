#!/usr/local/bin/zsh
g++ *.cpp
if [ $# -eq 0 ]
then
    ./a.out
else
    ./a.out < "$1"
fi


