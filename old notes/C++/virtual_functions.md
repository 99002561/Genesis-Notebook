# Virtual functions :

* A virtual function is a member function which is declared within a base class and is re-defined(Overriden) by a derived class. 

* Pointer Created of base type will point to derived members if it is virtual in base clan

* If we have created a virtual function in the base class and it is being overridden in the derived class then we don’t need virtual keyword in the derived class, functions are automatically considered as virtual functions in the derived class.

* They are always defined in base class and overridden in derived class. It is not mandatory for derived class to override (or re-define the virtual function), in that case base class version of function is used.

* C++ provides facility to specify that the compiler should match function calls with the correct definition at the run time; this is called dynamic binding or late binding or run-time binding. Dynamic binding is achieved using virtual functions. Base class pointer points to derived class object.

Reference Links :
https://www.geeksforgeeks.org/virtual-function-cpp/

*  pure virtual functions eg : virtual void credit(double)=0;  


## Pure Virtual Functions
* int credit(double)=0;  - expecting return to 0

## Example

#include <iostream> 
using namespace std; 
  
class base { 
public: 
    void fun_1() { cout << "base-1\n"; } 
    virtual void fun_2() { cout << "base-2\n"; } 
    virtual void fun_3() { cout << "base-3\n"; } 
    virtual void fun_4() { cout << "base-4\n"; } 
}; 
  
class derived : public base { 
public: 
    void fun_1() { cout << "derived-1\n"; } 
    void fun_2() { cout << "derived-2\n"; } 
    void fun_4(int x) { cout << "derived-4\n"; } 
}; 
  
int main() 
{ 
    base* p; 
    derived obj1; 
    p = &obj1; 
  
    // Early binding because fun1() is non-virtual 
    // in base 
    p->fun_1(); 
  
    // Late binding (RTP) 
    p->fun_2(); 
  
    // Late binding (RTP) 
    p->fun_3(); 
  
    // Late binding (RTP) 
    p->fun_4(); 
  
    // Early binding but this function call is 
    // illegal(produces error) becasue pointer 
    // is of base type and function is of 
    // derived class 
    // p->fun_4(5); 
} 

Output:

base-1
derived-2
base-3
base-4