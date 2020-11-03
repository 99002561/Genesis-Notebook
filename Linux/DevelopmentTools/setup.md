# Install Development Packages

## Update Linux Packages and Dependencies 
1. sudo apt-get update
2. `sudo apt-get dist-upgrade`
## C/C++ Compiler and Dev. Tool
1. `sudo apt-get update`
2. `sudo apt-get install build-essential`
## Debugger
    * `sudo apt-get install gdb`
## Cpp Check(Static Analysis)
    * `sudo apt-get install cppcheck`
## Valgrind(Dynamic Analysis)
    * `sudo apt-get install valgrind`
## Unit Testing
### Cmake 
    * `sudo apt-get install cmake`
### Google Test
    1. `sudo apt-get install libgtest-dev `         
    2. `cd /usr/src/gtest `
    3. `sudo cmake CMakeLists.txt `
    4. `sudo make`
        5. `sudo cp *.a /usr/lib`