// __Example 2__Basic2
// g++ pb1.cpp -lpthread && ./a.out

#include <iostream>
#include <thread>
#include <string>

#define print(msg) std::cout << msg << std::endl
#define str(x) std::to_string(x)
constexpr int max =10000; 

int val = 100;   // Shared Resource for both the threads

void inc(){
    print("Thread Increase"); 
    for(int i=0;i<=max;i++){
      val++;   
    }
}

void dec(){
    print("Thread Decrease");
    for(int i=0;i<=max;i++){
     val--;  
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

/*
Output :
This is Race Condition problem(uncertain results)
value of val variable is not same for every time of the program execution

* Not feasible Solutions
  Bus lock
  Disabling Threads

* Solution 1(Mutex or Semophore)
  std::mutex m1
  m1.lock()
  m2.unlock()

* Solution 2(using atomic variable)
  std::atomic<int> val(100)

*/