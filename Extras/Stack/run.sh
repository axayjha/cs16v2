#!/bin/bash

## Shell script to compile and run or interpret source
## codes of many different languages including
##   1. C
##   2. C++
##   3. Java
##   4. Python
##   5. Assembly
##   6. Ruby
##
## Last edited: 27/08/16
## (C) 2016 AKSHAY
## github.com/axayjha

## C
if [[ "$1" == *.c ]];
then
	gcc $1 -lm -o "${1//.c}".out
	./"${1//.c}".out

## Python3
elif [[ "$1" == *.py ]];
then
	python3 $1

## C++
elif [[ "$1" == *.cpp ]];
then
	g++ $1 -lm -o "${1//.c}".out
        ./"${1//.c}".out

## Java
elif [[ "$1" == *.java ]];
then
	javac $1
	java "${1//.java}"

## ASM
elif [[ "$1" == *.s ]];
then
	gcc -c $1 -o "${1//.s}".o
	gcc "${1//.s}".o -o "${1//.s}"
	./"${1//.s}"

## Ruby
elif [[ "$1" == *.rb ]];
then
	ruby $1

fi
