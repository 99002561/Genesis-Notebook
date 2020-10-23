/* __Problem1 Solution__Mutex

  Here Thread Syncronization is applied for val variable inside the loop

  std::mutex m1  // Declared Globally
  m1.lock()
  val++
  m2.unlock()

 g++ pb1_soln1.cpp -lpthread && ./a.out

*/

#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <chrono>

std::chrono::microseconds delay(1000);


#define print(msg) std::cout << msg << std::endl
#define str(x) std::to_string(x)
#define threadSleep std::this_thread::sleep_for(delay)


constexpr int max =10; 

int val = 5;   // Shared Resource for both the threads
std::mutex m1;    // Declared Globally

void inc(){
    print("Thread Increase");    
    for(int i=0;i<=max;i++){
      m1.lock();             // Locking val++ variable  
      print("I-"+str(++val)) ;        // Critical part 
      m1.unlock();         //Unlock Var
      threadSleep;
    }
}

void dec(){
    print("Thread Decrease");
    for(int i=0;i<=max;i++){
    m1.lock();            
    print("D-"+str(--val)) ;  
    m1.unlock();
    threadSleep;
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

/* output- Val same for each iteration output without threadsleep
Here the resourse for thread 2 is locked until the thread1 is using

Main--Welcome
Thread Increase
I-6
Thread Decrease
I-7
I-8
I-9
I-10
I-11
I-12
I-13
I-14
I-15
I-16
D-15
D-14
D-13
D-12
D-11
D-10
D-9
D-8
D-7
D-6
D-5
Final Val:5
End

* Output soln(1b) - with Thread Sleep
Here one thread counters the other thread action

Main-- Welcome
Thread Increase
I-6
Thread Decrease
D-5
I-6
D-5
I-6
D-5
I-6
D-5
I-6
D-5
I-6
D-5
I-6
D-5
I-6
D-5
I-6
D-5
I-6
D-5
I-6
D-5
Final Val:5





*/