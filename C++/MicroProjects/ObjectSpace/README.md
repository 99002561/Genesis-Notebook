# Objects in 2D space

## Execution Commands
1. make all 
2. ./object-test.out ; ./objectdb-test.out

## Output Logs
user@BLRMIESPC-1009:~/Desktop/99002623$ make all 
g++ object-test.cpp wobject.cpp iobject.cpp -o object-test.out -lgtest -lgtest_main -lpthread
g++ objectdb-test.cpp objectdb.cpp wobject.cpp iobject.cpp -o objectdb-test.out -lgtest -lgtest_main -lpthread

user@BLRMIESPC-1009:~/Desktop/99002623$ ./object-test.out ; ./objectdb-test.out
[==========] Running 4 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 4 tests from ObjectTest
[ RUN      ] ObjectTest.DefaultConstructor
[       OK ] ObjectTest.DefaultConstructor (0 ms)
[ RUN      ] ObjectTest.ParameterizedConstructor
[       OK ] ObjectTest.ParameterizedConstructor (0 ms)
[ RUN      ] ObjectTest.ComputationTest
[       OK ] ObjectTest.ComputationTest (0 ms)
[ RUN      ] ObjectTest.AnotherTest
[       OK ] ObjectTest.AnotherTest (0 ms)
[----------] 4 tests from ObjectTest (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 4 tests.

[==========] Running 6 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 6 tests from ObjectDbTest
[ RUN      ] ObjectDbTest.AddObjectTest
[       OK ] ObjectDbTest.AddObjectTest (0 ms)
[ RUN      ] ObjectDbTest.RemoveObjectTest
[       OK ] ObjectDbTest.RemoveObjectTest (0 ms)
[ RUN      ] ObjectDbTest.CountAllTest
[       OK ] ObjectDbTest.CountAllTest (0 ms)
[ RUN      ] ObjectDbTest.ComputationalTest
[       OK ] ObjectDbTest.ComputationalTest (0 ms)
[ RUN      ] ObjectDbTest.CountByColorTest
[       OK ] ObjectDbTest.CountByColorTest (0 ms)
[ RUN      ] ObjectDbTest.AnotherDbTest
[       OK ] ObjectDbTest.AnotherDbTest (0 ms)
[----------] 6 tests from ObjectDbTest (0 ms total)

[----------] Global test environment tear-down
[==========] 6 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 6 tests.

## Problem Statement
* In this problem you are expected to implement a solution 
* with certain operations on collection of Objects in 2D space
* IObject as an abstract class 
*    - suitable constructor
*    - suitable pure virtual like distance from origin, quadrant belongs to  
*    - use enum for list of Quadrants   
* An IObject can be specialized as WObject as follows (i.e. Weighted Object)
*    - attributes - x, y, weight 
*    - suitable constructor(s) for derived class
*    - override pure virtual functions ,i.e distance from origin, quadrant belongs to.
* You must strongly exhibhit polymorphic design aspects with above classes
* Use upcasted pointers/references and dynamic binding to demonstrate runtime polymorphism
* Implement another class say ObjectDb with collection of WObject instances
* (derived class ) using suitable data set (right STL container)
* Implement some operations on collection of Objects as per following test calls
*    - addObject(3, 4, 100)
*    - removeObject(5,6);              
*      //Assuming no two Boxes on same coordinates 
*      //remove only if both x,y matches
*    - countAll()
*    - findMinWeight()
*    - findMaxDistanceFromOrigin()          //distance of farthest point
*    - countObjectsByQuadrant(Q3)
*    - countObjectsOnCircleBoundary(5)      //same radius, distanceFrom Origin
* Please provide optimal business logic in specified functions without any redundancy
* Core functions should be detached from console i/o and suitable for testable approach
* Please implement a simple test plan with suitable function calls in main 
* Provide solution in terms of multiple files with clean hierarchy of
* header, source files 
* Please add class diagram if time permits at end
* Follow the best practices of C++ & clean coding practices while implementing
* Please follow good coding style and meaningful names
* Your code shouldn't be crashed and no memory leaks/heap errors are expected from your code
* Your code will be validated against following code quality parameters
  * Code Style - googlestyle (clang-format/AStyle)
  * Static Analysis - cppcheck.
  * Heap Analysis - valgrind
* Please add class diagram at end
* Try to demonstrate RTTI features like dynamic_cast, typeid (this may not relate with 
* collection of objects or given test codelisted below, can be independent code) 

## Submission guidelines
* Place all code written by you (header files, source files) including provided
  test code + Makefile and zip the code, and name it with your PS no.
* Use zip format only, any other format can't be considered due to sharepoint compatibility
* Exclude any generated code like object files, executable files in zip file

* For e.g. if your PS no. is 99002400 and your submission file should be 99002400.zip
* Place the zip file, in a sub dir called "cpp-reassessment" under Intermediate C++ submission folder of sharepoint (under respective folder with your PS number) 
* Any deviation in file name or folder name is considered as no submission/blank

* Your zip file should contain following 10 files
  * iobject.h, wobject.h, objectdb.h, 
  * iobject.cpp, wobject.cpp, objectdb.cpp
  * object-test.cpp, objectdb-test.cpp, Makefile (already provided)


