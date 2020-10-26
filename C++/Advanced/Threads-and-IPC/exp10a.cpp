/*__lock guard example__

* It is light wrap over the mutex which ownes and lockes mutex
* scope basis
    Lock is valid only in the defined scope
* lock within the scope and unlock when out of the scope(destructor)
* explicit unlock is not possible
* cant copy lock guard

* Implementation
#include 
std::mutex m1;
std::lock_guard<mutex> lck(m1)

g++ exp10a.cpp -lpthread && ./a.out

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

/* Method 1 
void inc(){
    print("Thread Increase");    
    for(int i=0;i<=max;i++){
      m1.lock();             // Locking val++ variable  
      print("I-"+str(++val)) ;        // Critical part 
      m1.unlock();         //Unlock Var
      threadSleep;
    }
}*/

void inc(){
    print("Thread1--Increase");    
    for(int i=0;i<=max;i++){  // Critical Section 
    std::lock_guard<std::mutex> lck(m1);   //valid only in for loop
      print("T1-"+str(++val)) ;   
      //threadSleep(1);     
    }
}


void dec(){
    print("Thread2--Decrease");
    for(int i=0;i<=max;i++){
    std::lock_guard<std::mutex> lck(m1);     
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

/* output- Without thread sleep
Main-- Welcome
Thread1--Increase       --> locked var
Thread2--Decrease       --> waiting for thread 1 to finish
T1-6                    --> thread 1 started again
T1-7
T1-8
T1-9
T1-10
T1-11
T2-10
T2-9
T2-8
T2-7
T2-6
T2-5
Final Val:5
End

* obs : Thread decrease scheduled before thread increase but it was 
waiting for thread inc to release the resource

* Ouput - with threadsleep

Thread1--Increase
T1-6
Thread2--Decrease        --> scheduled when t1 went to sleep
T1--sleep
T1-7
T1--sleep
T1-8
T1--sleep
T1-9
T1--sleep
T1-10
T1--sleep
T1-11
T1--sleep
T2-10
T2-9
T2-8
T2-7
T2-6
T2-5
Final Val:5
End




*/