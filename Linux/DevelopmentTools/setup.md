# Install Linux Packages
    Launch terminal and paste following commands 
## Update Linux Packages and Dependencies 
    1. sudo apt-get update
    2. sudo apt-get dist-upgrade
## C/C++ Compiler and Dev. Tool
    1. sudo apt-get update
    2. sudo apt-get install build-essential
## Debugger
    sudo apt-get install gdb
## Cpp Check(Static Analysis)
    sudo apt-get install cppcheck
## Valgrind(Dynamic Analysis)
    sudo apt-get install valgrind
## Unit Testing
### Cmake 
    sudo apt-get install cmake
### Google Test
    1. sudo apt-get install libgtest-dev        
    2. cd /usr/src/gtest
    3. sudo cmake CMakeLists.txt
    4. sudo make
    5. sudo cp *.a /usr/lib

# Alias Names
1. launch terminal
2. code ~/.bashrc
3. write alias names
4. reopen the terminal or source ~/.bashrc
## Commands
    alias compileDir='g++ -c src/*.c* && mkdir -p obj && mv *.o obj'
    alias compile='g++ -c *.c* && mkdir -p obj && mv *.o obj'
    alias compileTest='g++ -c src/*.c* && g++ -c test/test.cpp && mkdir -p obj && mv *.o obj'
    alias link='mkdir -p bin && g++ obj/*.o -o bin/out'
    alias linkGtest='mkdir -p bin && g++ obj/*.o -lgtest -lgtest_main -lpthread -o bin/out'
    alias run='bin/out'
    alias genMake='cd build && cmake . && cd ..'
    alias build='cd build && make && ./out && cd ..'
    alias runB='build/out'

# vs code
1. [vs code editor](https://code.visualstudio.com/Download)
2. [c/c++ extension](https://code.visualstudio.com/docs/cpp/config-linux)
3. [Tasks](https://code.visualstudio.com/docs/editor/tasks)
