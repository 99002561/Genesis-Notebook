/*__unique_lock example1__

Notes:
* this is mutex ownership wrapper
* lock based on scope basis
* different locking strategies
    1. defer_lock
        dont lock the mutex while construction
        std::unique_lock<mutex> key(m1,defer_lock)
        key.lock and key.unlock 
    2. try_to_lock
        try to acquire ownership without blocking
    3. adopt_lock
        assume the calling thread has ownership of mutex
    4. default(same as lock_guard)        
        void foo() {
        std::unique_lock<std::mutex> lock(m);
        //m is locked here
        //Protected. Only one thread can be active here.
        //m is unlocked when foo ends
        }
* time- constrained locking
    1.try_loc_for
    2.try_lock-until
* recursive lock
* transfer of ownership(only move not copy)
* condition variable


This program is to understand the defualt locking s
g++ exp10b.cpp -lpthread && ./a.out

*/

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>

std::chrono::microseconds delay(1000);


#define print(msg) std::cout << msg << std::endl
#define str(x) std::to_string(x)
#define threadSleep(thrID) std::this_thread::sleep_for(delay);print("T"+str(thrID)+"--sleep")


constexpr int max =5; 

int val = 5;   // Shared Resource for both the threads
std::mutex m1;    // Declared Globally

void inc(){
    std::unique_lock<std::mutex> lck(m1);  
    print("Thread1--Increase");    
    for(int i=0;i<=max;i++){  // Critical Section 
      print("T1-"+str(++val)) ;   
      //threadSleep(1);     
    }
}


void dec(){
    std::unique_lock<std::mutex> lck(m1);  
    print("Thread2--Decrease");
    for(int i=0;i<=max;i++){
    print("T2-"+str(--val)) ;  
    }
}

int main(){
    print("Main-- Welcome");
    std::thread t1(inc);    // Created Thread1 for fsample
    std::thread t2(dec); // 2nd Parallel Thread
    t1.join();
    t2.join();
    print("Final Val:"+str(val));
    print("End");
    return 0;

}

/* output for default lock

Main-- Welcome
Thread1--Increase
T1-6
T1-7
T1-8
T1-9
T1-10
T1-11
Thread2--Decrease
T2-10
T2-9
T2-8
T2-7
T2-6
T2-5
Final Val:5
End






*/