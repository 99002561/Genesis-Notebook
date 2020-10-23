/* __Problem1 Solution__Mutex

Consumer is starting before the Producer is started

*/

#include <iostream>
#include <thread>
#include <string>
#include <mutex>

#define print(msg) std::cout << msg << std::endl
#define str(x) std::to_string(x)
constexpr int max =10; 

int val = 5;   // Shared Resource for both the threads
std::mutex m1;    // Declared Globally

void producer(){
    print("Thread Increase");  
    m1.lock();                    // Locking Loop      
    for(int i=0;i<=max;i++){
    print("T1--"+str(++val)) ;        // Critical part        
    }
    m1.unlock();                  //Unlock to for other threads
}

void consumer(){
    print("Thread Decrease");
    m1.lock(); 
    for(int i=0;i<=max;i++){
    print("T2--"+str(--val)) ;  
    }
    m1.unlock();
}

int main(){
    print("Main-- Welcome");
    std::thread t1(producer);    // Created Thread1 for fsample
    std::thread t2(dec); // 2nd Parallel Thread
    t1.join();
    t2.join();
    print("Final Val:"+str(val));
    print("End");
    return 0;

}

/* output-


*/