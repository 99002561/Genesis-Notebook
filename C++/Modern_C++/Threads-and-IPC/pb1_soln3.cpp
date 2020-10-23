/* __Problem1 Solution__Mutex

  Here Thread Syncronization is applied for loop overlap

  std::mutex m1  // Declared Globally
  m1.lock()
  forLoop(){
    ....
  }
  m2.unlock()

 g++ pb1_soln3.cpp -lpthread && ./a.out

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

void inc(){
    print("Thread Increase");  
    m1.lock();                    // Locking Loop      
    for(int i=0;i<=max;i++){
    print("T1--"+str(++val)) ;        // Critical part        
    }
    m1.unlock();                  //Unlock to for other threads
}

void dec(){
    print("Thread Decrease");
    m1.lock(); 
    for(int i=0;i<=max;i++){
    print("T2--"+str(--val)) ;  
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

/* output-

Main-- Welcome
Thread Increase
T1--6
T1--7
T1--8
T1--9
Thread DecreaseT1--10
T1--11
T1--12
T1--13
T1--14
T1--15
T1--16

T2--15
T2--14
T2--13
T2--12
T2--11
T2--10
T2--9
T2--8
T2--7
T2--6
T2--5
Final Val:5
End

*/