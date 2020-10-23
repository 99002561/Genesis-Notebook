/* __example Problem of synchronization__

Observe Producer and Consumer threads are not in sync
ie. Consumer is starting before the Producer is started

g++ pb3.cpp -lpthread && ./a.out
*/

#include <iostream>
#include <thread>
#include <string>
#include <mutex>

std::chrono::microseconds delay(1000);
constexpr int max =5; 

#define print(msg) std::cout << msg << std::endl
#define str(x) std::to_string(x)
#define threadSleep std::this_thread::sleep_for(delay)

int val = 5;   // Shared Resource for both the threads
std::mutex m1;    // Declared Globally

void producer(){
    print("Thread Producer"); 
    threadSleep; 
    m1.lock();                    // Locking Loop      
    for(int i=0;i<=max;i++){
    print("P--"+str(++val)) ;        // Critical part   
    threadSleep;      
    }
    m1.unlock();                  //Unlock to for other threads
}

void consumer(){
    print("Thread Consumer");
    m1.lock(); 
    for(int i=0;i<=max;i++){
    print("C--"+str(val--)) ;  
    threadSleep; 
    }
    m1.unlock();
}

int main(){
    print("Main-- Welcome");
    std::thread t1(producer);    // Created Thread1 for fsample
    std::thread t2(consumer); // 2nd Parallel Thread
    t1.join();
    t2.join();
   // print("Final Val:"+str(val));
    print("End");
    return 0;

}

/* output-

Main-- Welcome
Thread Producer
Thread Consumer
C--5
C--4
C--3
C--2
C--1
C--0
P--0
P--1
P--2
P--3
P--4
P--5
End


Soln:
* Condition Variable is used
* consumer thread should wait until it gets control from the producer thread

*/