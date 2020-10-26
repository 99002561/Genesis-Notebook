/*__Deadlock example__


Deadlock Scenario 1(2 Shared Resources)
    std::mutex m1;
    std::mutex m2;

    T1                  T2   
    m1.lock()           m2.lock
    delay()             m1.lock
    m2.lock()       

Notes:
* Multiple Mutex lock
    std::lock(m1,m2,m3....)
    here the lock is done sequentially if any one lock fails ,all the other locks in the pile are unlocked

* In some scenarios, we might require multiple resource (as given example of printer and scanner), so multiple locks will be required
* T1, T2 might need resources A & B, T2, T3 might require B & C, like that..so one lock may not apply for 
all resources (T1 & T4 might require A & D etc)
* one lock per resource


https://www.youtube.com/watch?v=ruYGFYTRbe8&ab_channel=CppNuts

Solution:
* using diff_lock and atomic lock
    std::unique_lock<std::mutex> u1(m1,std::def_lock)  //Global
    std::unique_lock<std::mutex> u2(m2,std::def_lock)
    std::lock(u1,u2)
    

 g++ pb2.cpp -lpthread && ./a.out
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


constexpr int max =3; 

int val = 3;   // Shared Resource for both the threads
std::mutex m1;    
std::mutex m2;    



void inc(){
    std::unique_lock<std::mutex> lck1(m1,std::defer_lock);   
    std::unique_lock<std::mutex> lck2(m2,std::defer_lock);
    print("Thread1--Increase");    
    std::lock(lck1,lck2);
    for(int i=0;i<=max;i++){  // Critical Section  
      print("T1-"+str(++val)) ;   
      //threadSleep(1);     
    }
}


void dec(){
    std::unique_lock<std::mutex> lck1(m1,std::defer_lock);  
    std::unique_lock<std::mutex> lck2(m2,std::defer_lock); 
    print("Thread2--Decrease");
    std::lock(lck1,lck2);
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
    print("Main-- End");
    return 0;
}

/* output

Main-- Welcome
Thread1--Increase
T1-4
T1-5
T1-6
T1-7
Thread2--Decrease
T2-6
T2-5
T2-4
T2-3
Final Val:3
Main-- End





*/