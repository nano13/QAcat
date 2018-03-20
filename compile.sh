#!/usr/bin/bash

qmake-qt5 -o Makefile qacat.pro
make

if [ $? -eq 0 ]
then
    ./debug/qacat
fi
