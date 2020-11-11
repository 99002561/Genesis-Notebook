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

#### Commands only for Github actions 
    5. sudo cp *.a /usr/lib
    6. sudo ln -s /usr/lib/libgtest.a /usr/local/lib/libgtest.a  
    7. sudo ln -s /usr/lib/libgtest_main.a /usr/local/lib/libgtest_main.a

# vs code
1. [vs code editor](https://code.visualstudio.com/Download)
2. [c/c++ extension](https://code.visualstudio.com/docs/cpp/config-linux)
    compile and debug a simple C++ program
3. [cmake tool](https://code.visualstudio.com/docs/cpp/cmake-linux)
    easy to configure, build, and debug your C++ project
4. [C/C++ Advanced Lint](https://marketplace.visualstudio.com/items?itemName=jbenden.c-cpp-flylint)
    static code analyzers for C and C++ code.
4. [Tasks](https://code.visualstudio.com/docs/editor/tasks)

# Alias Names
1. launch terminal
2. code ~/.bashrc
3. write alias names
4. reopen the terminal or source ~/.bashrc
## Commands
    alias buildDir='g++ src/*.c* -o out && ./out'
    alias build='g++ *.c* -o out && ./out'
    alias buildGtest='g++ src/*.c* test/test.cpp -lgtest -lgtest_main -lpthread -o out && ./out'
    alias run='./out'

    #C++ alias names for commands
    alias buildGtest='g++ *.c* -lgtest -lgtest_main -lpthread -o out && ./out'
    
    #c++ make files 
    alias buildMake='make out && ./out'
    alias run='./out'
    alias test='make Gtest && ./Gtest'
    alias testDebug='make GtestDebug && ./GtestDebug'