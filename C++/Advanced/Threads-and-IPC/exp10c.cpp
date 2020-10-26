/*__unique_lock example 2__

This program is for unique_lock to understand 
the transfer of ownership and scope

Scenario:
T1 scope of Lock is within for loop
    print is critical section
T2 scope of lock is for complete for loop
    for loop is critical section

T2 has the higher scope



*/
// g++ exp10c.cpp -lpthread && ./a.out

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



void inc(){
    std::unique_lock<std::mutex> key(m1,std::defer_lock);   
    print("Thread1--Increase");    
    for(int i=0;i<max;i++){  // Critical Section  
        std::unique_lock<std::mutex> lck(std::move(key));       // transfer of ownership to for loop scope
        print("T1-"+str(++val)) ;   
      //threadSleep(1);     
    }
}


void dec(){
    std::unique_lock<std::mutex> key(m1,std::defer_lock);  
    //std::unique_lock<std::mutex> key2(m2,std::defer_lock); 
    print("Thread2--Decrease");
    key.lock();                         // for loop is critical section here
    print("Thread2--start");
    for(int i=0;i<max;i++){
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

/* Output When both threads are scheduled concurrent
Main-- Welcome
Thread1--Increase           --> Thread1 started
Thread2--Decrease           --> Thread2 started and thread 1 is out of core
Thread2--start              --> T2 locked for loop
T1-4T2-3                    --> Thread 1 scheduled and Thread 2 also running parallel ,now after t1 lock is done t2 lock is active
T2-2                        --> Thread2 is continued  bcz it has the higher level of lock scope  and thread 1 is waiting
T2-1

T1-2
T1-3
Final Val:3
Main-- End



observation :

within for loop
T1 - lock and unlock
T2 - lock and finishes T2 and makes t1 wait


*/