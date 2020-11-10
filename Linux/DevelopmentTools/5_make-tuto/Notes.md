# Make File

## Why Make Files ? 
    If you want to run or update a task when certain files are updated, the make utility can come in handy. 

## What is Make File?
* The make utility requires a file, Makefile (or makefile), which defines set of tasks to be executed. 
* You may have used make to compile a program from source code. 
* Most open source projects use make to compile a final executable binary, which can then be installed using make install.

## Example
Gtest: bankingtest.cc banking.h
    g++ $^ -o $@ -lgtest -lgtest_main -lpthread
GtestDebug: bankingtest.cc
    g++ $^ -D DEBUG -o $@ -lgtest -lgtest_main -lpthread
    
all.out : iobject.cpp wobject.cpp objectdb.cpp object-test.cpp objectdb-test.cpp
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
build: 
	g++ *.c* -o bin.out -lgtest -lgtest_main -lpthread
	./bin.out
run:
	./bin.out
clean:
	rm -rf *.out
