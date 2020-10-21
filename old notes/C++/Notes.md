# Basics
## Terminolagy
* Parameter : Input for the Function Block
* Argument : Values passed

## References
    * Alternate Name or alias name for variable 
        int x = 10; 
        int& ref = x;       // ref/x is same variable
        ref = 20;          // x = 20

    * const reference(const int&) for constant or variable as argument
       
       int& for only variable as argument

       void add(int& a){
       }
       add(20)  // error
       x = 20 
       add(x)   // variable as argument

       void(const int&a){}
        add(20) // ok

    * it is same as const pointer ie.  reference cannot be re-assigned, 

    * no null assignment

    * onelevel of indirection
    int& p =a;
    int&& q = p; // not allowed

    * used as function parameters design

    * dont use reference for containers or multi element datatype


    https://www.geeksforgeeks.org/references-in-c/

# Trivial Classes in C++

* has compiler provided special member functions
* contiguos memory area occupied
* 
