"Made by me"

# Checklists
* Cutomer Base
  * Customer.h (Skeleton code)
    * define call rate
    * Create Customer baseclass 
      - Private datamembers
      - Constructor (Settor)
      - Virtual functions as operation members
          credit,makeCall 
      - getter for all datamembers
  * Customer.cpp (Prototype)
    * Define Class Members -Constructor ,Operations and Getters

* Prepaid using derived rather than enum
* Postpaid.h
    * Derived class of Customer

# Ubuntu Commands
  $ g++ customer_test.cpp -c
  $ g++ customer.cpp -c
  $ g++ postpaid.cpp -c
  $ g++ prepaid.cpp -c
  $ g++ customer_test.cpp customer.cpp postpaid.cpp prepaid.cpp -c
  $ g++ customer_test.o customer.o postpaid.o prepaid.o -lgtest -lgtest_main -lpthread -o out

# Changes required
* Derived Functions overriding removal if everything is same


# Problem Statement

* In this problem you are expected to implement a solution for "mobile billing system" with certain operations on "prepaid, postpaid customers"
* A Customer can be associated with 
*    - data members like customer id, name, phone number, initial balance
     - suitable constructor
*    - suitable abstract operations like makeCall, credit (billpay/recharge)
* A Customer can be specialized as Prepaid, Postpaid customers as follows
*    - additional data members if any
*    - suitable constructors for derived classes
*    - override necessary operations here, assume call rate of 1 for makeCall       
       implementation.
* You must strongly exhibhit polymorphic design aspects with above classes
* Use upcasted pointers/references and dynamic binding to demonstrate runtime polymorphism
* Implement another class say BillingSolution with collection of prepaid customer 
  objects 
* using suitable data set (right STL container)
* Implement some operations on collection of Prepaid Customers as per following test 
  calls
*    - addCustomer(1001,"Lippman", "9845012345", 1000);
*    - removeCustomer(1001)
*    - findCustomerById(1003);
*    - findCustomerByPhone("9845012347");
*    - findAverageBalance()
*    - findMaxBalance()
*    - countByMinBalance(320)
*    - countAll()
* Please demonstrate your knowledge of iterators while implementing above operations 
* Please provide optimal business logic in specified functions without any redundancy
* Core functions should be detached from console i/o and suitable for testable approach
* Please ensure that your implementation aligns with test code provided, your code will be validated with some more test cases at backend
* Provide solution in terms of multiple files with clean hierarchy of header, source files 
* Follow the best practices of C++ & clean coding practices while implementing
* Please follow good coding style and meaningful names
* Your code shouldn't be crashed and no memory leaks/heap errors are expected from your code
* Your code will be validated against following code quality parameters
  * Code Style - googlestyle (clang-formar/AStyle)
  * Static ANalysis - cppcheck)
  * Heap Analysis - valgrind
* Please add class diagram if time permits at end
* You may demonstrate RTTI features like dynamic_cast, typeid (this may not relate 
  with collection of objects listed below, can be independent test code in 
  main)..Optional

