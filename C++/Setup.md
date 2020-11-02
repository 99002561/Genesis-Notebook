## Work Setup
Linux Platform based C++ Development
1. Prerequisite Installations 
    1. [vs code editor](https://code.visualstudio.com/Download)
    2. c/c++ extension(Optional)
    3. Update Linux Packages and Dependencies 
        1. `sudo apt-get update`
        2. `sudo apt-get dist-upgrade`
    4. Build Essentials(C/C++ Compiler and Dev. Tool)
        1. `sudo apt update`
        2. `sudo apt install build-essential`
    5. Debugger
        * `sudo apt-get install gdb`
    6. Cpp Check(Static Analysis)
        * `sudo apt-get install cppcheck`
    7. Valgrind(Dynamic Analysis)
        * `sudo apt-get install valgrind`
    8. CI/CD
        * [Git and Github Setup](../Github/Setup.md)
        * [Git Actions](../Github/Actions.md)
    9. Unit Testing
        * Cmake 
            1. `sudo apt-get install cmake`
            2. `sudo apt-get install build-essential cmake`
        * Google Test
            1. `sudo apt-get install libgtest-dev `
            2. `cd /usr/src/gtest `
            3. `sudo cmake CMakeLists.txt `
            4. `sudo make `
            5. `sudo cp *.a /usr/lib `
            6. `sudo ln -s /usr/lib/libgtest.a /usr/local/lib/libgtest.a`
            7. `sudo ln -s /usr/lib/libgtest_main.a /usr/local/lib/libgtest_main.a`

2. Write Alias Names
    1. code ~/.bashrc
    2. write alias names
    3. reopen the terminal 
        or source .bashrc
    **Commands**
    *  alias compileDir='g++ -c src/*.c* && mkdir -p obj && mv *.o obj'
    * alias compile='g++ -c *.c* && mkdir -p obj && mv *.o obj'
    * alias compileTest='g++ -c src/*.c* && g++ -c test/test.cpp && mkdir -p obj && mv *.o obj'
    * alias link='mkdir -p bin && g++ obj/*.o -o bin/out'
    * alias linkGtest='mkdir -p bin && g++ obj/*.o -lgtest -lgtest_main -lpthread -o bin/out'
    * alias run='bin/out'
    * alias genMake='cd build && cmake . && cd ..'
    * alias build='cd build && make && ./out && cd ..'
    * alias runB='build/out'

### Tools Required
0. IDE or Compiler with Editor(Vs code)
1. Unit Testing Framework(gtest and unit test)
2. Code Style Plugin(Clang or Google or vs code)
3. [Code Visualizer](http://www.pythontutor.com/cpp.html#mode=edit)
4. Code Explorer(SourceTrail)
5. Code Quality(Analysis -Staic(Codacy,cppcheck) and Dynamic(valgrind))
6. CI/CD (Genics,github)
7. Documentaion(doxygen)
8. Design Suite(UMl Diagram-draw.io)