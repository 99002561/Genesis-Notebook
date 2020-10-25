# Modern C++(Advanced)
* C++ 11/14 Language features

## Move Schematic
* [Trival Classes](https://www.geeksforgeeks.org/trivial-classes-c/)

## Pointers
* Smart Pointers

## STL
* STL Improvements

## Templates

## Lambdas and Callable elements

## Concurrency and IPC
1. Async 
  * Launch async

### Demos/Hands-on:-
* Thread callbacks a) normal functions b) using lambdas 
* Passing arguments to thread callbacks
  a) multiple arguments to std::thread constructor b) using std::bind b) lambdas
* Function objects as thread callbacks
* Array of thread instances
* Using delay in threads, providing time duration using chrono library
* Race condition demo , concurrent increment/decrement on global variable
* Mutex usage to avoid race conditions
* Atomic variables to avoid race conditions
* a) Secnario to generate deadlocks b) avoid deadlocks using std::unique_lock and std::lock
* Difference between unique_lock and lock_guard
* Async task demo -- simple function
* Recursive function using Async tasks
* Promise and Future demo to exchange some data
* Void future and promise (barrier)

### Additional:-
* Detachable threads
* Async launch policies
* Implementation of own shared pointer
* Basic Design aspects


## File Handling


## Exception Handling