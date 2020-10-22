# Notes

## Basics
[std](https://www.geeksforgeeks.org/using-namespace-std-considered-bad-practice/)

### Namespace
Namespaces were introduced into C++ to resolve identifier name conflicts.
This ensured that two objects can have the same name and yet be treated differently if they belonged to different namespaces. 

### Alias Names
1. typedef <existingName> <NewName>
    * typedef 
    * alias names for type
    * done by compiler
[typedef](https://www.studytonight.com/c/typedef.php)

2. #define <newName> <existingName>
    * done by preprocessor directive
    * alias name for both values and types



 
## Classes
Data members of a class may be declared as const . Such a data member must be initialized by the constructor using an initialization list. Once initialized, a const data member may never be modified, not even in the constructor or destructor.

## I/O
### Boolean Formatting
    noboolalpha - for 1/0
    boolalpha - for true/false


## Reference Links
    https://www.geeksforgeeks.org/templates-cpp/

## Threads
* Support from C++11 standard