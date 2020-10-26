# Concurrency and IPC
* concurrency in C++ ==> std::thread, std::async
* IPC techniques  ==> std::mutex, some locks, std::condition_variable etc.

## Threads
* sub tasks in a process
* Supported by C++11 standard
* Shared Resources
* Concurrency Executions
    All the threads can run simultaneously

### Applications
* Multiple Activity in YouTube,Browser
* Multiple Client Handling(Main Thread listening to clients)

### Categories Achieved:
* Task Driven Parallelism(Cookie functions are different,Data may or mayn't be same)
* Data Driven Parallelism(Cookie function is same,Data is Changed)
    Eg. Parallel Sum of large Array

### Constructor Accepts
* Normal Functions
* Lambda Expressions
* Function Objects(Class Members)
    * using lambda with capture [=] () { s1.push(val); }
    * For non static class member
        1. Create object pointer - Class * objPtr = obj Class();
        2. Thread creation Arguments - Pass member address ,object pointer and member arguments
            eg. std::thread t1(&Class::member,objPtr,memberArg);       
    * for static class member
            std::thread th(&class::member,arg);
* Binded Functions
    std::thread t1(std::bind(fn,arg))
    std::thread t1(std::bind(&class::member,objPtr,2));
        
### Types
* Threads are scheduled by OS default
* std::thread
        for running thread without return
* std::async
    for running thread with return value to a main thread
    std::promise
        for intermediate return from the thread

## IPC 
### Race Condition
    when Changes applied from multiple threads at the same time leads to race condition which effects in uncertain results

### Critical Section
    A program segment where it alters or uses the shared resources 
    * Entry Section - Allows/Blocks the Other threads
    * Exit Section

### Mutual Exclusion (Mutex)
* to avoid race condition,deadlock
* It prevents the simultaneous access to the shared resources
* it allows only one thread at one time to access the resource and other threads will be waiting
* Techniques
    * Semophores(no c++ support)
        For Multiple Shared Resource Access
    * Spinlocks(no c++ suppport)
    * Mutex
        for single Shared resources between the threads(using lock)
        * Lock Guard
        * Unique Lock
    * Atomic Variables(c++)
        Other Threads cant access this variable if this is used by one thread

### Signaling and Synchronization
* Semaphores(no c++ support)
* Condition Variable
* Co-ordinate the Communication between the inter threads if there is any condition needs to be satisfied
* it blocks other thread makes it to wait untill condition is achived
* it uses unique lock over mutex
#### Implementation Anology :
    Master Thread(controls slave thread)
    flag = true;
    cv.notify_one();

    Slave Thread (waiting for master thread)
    std::unique_lock<std::mutex> lck(m1);
    cv.wait(lck,conditionfn_ptr/lambdaFunction);

* http://www.cplusplus.com/reference/condition_variable/condition_variable/

### Dead lock   
    here if the T2 tries to lock resources that are later used by 
    Difference between the lock_guard and unique lock
    unique lock
