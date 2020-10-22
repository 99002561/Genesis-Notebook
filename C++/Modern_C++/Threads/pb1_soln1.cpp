// __Problem1 Solution __Basic2
// g++ pb1_soln1.cpp -lpthread && ./a.out

#include <iostream>
#include <thread>
#include <string>
#include <mutex>

#define print(msg) std::cout << msg << std::endl
#define str(x) std::to_string(x)
constexpr int max =10000; 

int val = 100;   // Shared Resource for both the threads
std::mutex m1;    // Declared Globally

void inc(){
    print("Thread Increase");
    m1.lock();                 // Critical Section
    for(int i=0;i<=max;i++){
      val++;   
    }
 //   m1.unlock();
}

void dec(){
    print("Thread Decrease");
    m1.lock();  
    for(int i=0;i<=max;i++){
     val--;  
    }
    m1.unlock();
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

/*
Output :
This is Race Condition problem(uncertain results)
value of val variable is not same for every time of the program execution

* Not feasible Solutions
  Bus lock
  Disabling Threads

* Solution 1(Mutex or Semophore)
  
 
  m2.unlock()

* Solution 2(using atomic variable)
  std::atomic<int> val(100)

*/