/* __example of synchronization__

Soln:
* Condition Variable is used
* consumer thread should wait until it gets control from the producer thread

Conditon variable wait
std::unique_lock<std::mutex> lck(m1);
cv.wait(lck,getStatus);

g++ pb3_soln.cpp -lpthread && ./a.out
*/

#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <condition_variable>

std::chrono::microseconds delay(1000);
constexpr int max =5; 

#define print(msg) std::cout << msg << std::endl
#define str(x) std::to_string(x)
#define threadSleep std::this_thread::sleep_for(delay)

int val = 5;   // Shared Resource for both the threads
std::mutex m1;    // Declared Globally

std::condition_variable cv;
bool ready = false;

bool getStatus(){
    return ready;
}


void producer(){
    print("Thread Producer"); 
    threadSleep; 
    // Creating Unique Lock 
    std::unique_lock<std::mutex> lck(m1);

    for(int i=0;i<=max;i++){
    print("P--"+str(++val)) ;        // Critical part   
    threadSleep;      
    }
    ready = true;
    cv.notify_one();
    print("Producer Thread - Thanks");
}

void consumer(){
    print("Thread Consumer");
    std::unique_lock<std::mutex> lck(m1);
   // cv.wait(lck,[] (){return ready;});   // waits untill ready is false
    
    cv.wait(lck,getStatus);
    print("Thread Consumer--start");    // runs when ready is true
    for(int i=0;i<=max;i++){
    print("C--"+str(val--)) ;  
    threadSleep; 
    }
    
}


int main(){
    print("Main-- Welcome");
    std::thread t1(producer);    // Created Thread1 for fsample
    std::thread t2(consumer); // 2nd Parallel Thread
    t1.join();
    t2.join();
   // print("Final Val:"+str(val));
    print("Main--End");
    return 0;

}

/* output-

Main-- Welcome
Thread Producer
Thread Consumer
P--6
P--7
P--8
P--9
P--10
P--11
Producer Thread - Thanks
Thread Consumer--start
C--11
C--10
C--9
C--8
C--7
C--6
Main--End

*/