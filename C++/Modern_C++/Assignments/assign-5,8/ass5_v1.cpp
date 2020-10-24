
/*__Assignment 5__

5. Write a program to implement two threads, where output from both threads will 
   come,with switching after every 5 iterations.
* Two Threads Created
* 


   g++ ass5.cpp -lpthread && ./a.out


*/

#include <iostream>
#include <string>
#include <future>
#include <condition_variable>
#include <chrono>


std::chrono::milliseconds delay(1000);

#define print(msg) std::cout << msg << std::endl
#define str(i) std::to_string(i)
#define threadSleep std::this_thread::sleep_for(delay)

std::mutex m1;
std::condition_variable cv1;
std::condition_variable cv2;
bool t1_flag = true;    // resume t1 if this flag is true
bool t2_flag =false;      // resume t2 if this flag is true

constexpr int max = 20;
int iter=1;


void producer(){

  std::unique_lock<std::mutex> lck(m1);

    while(iter<max){
        cv2.wait(lck,[](){return t1_flag;});            // Blocking Statement

        if(iter>max)                            // this is conditional statement
            break;
        
        print("Thread-1");
      

        for(int i=iter;i<=iter+4;i++){
        print("T1: "+ str(i));
        }
        iter += 5;

        t2_flag=true;           // here thread2 is released
        cv1.notify_one();      // Thread 2 starts
        t1_flag = false;       // wait for thread2 and block t1
   }


}

void consumer(){

std::unique_lock<std::mutex> lck(m1);


    while(iter<max){
        cv1.wait(lck,[](){return t2_flag;}); // wait until ready is false 

        if(iter>max)
            break;

        print("Thread-2");

        for(int i=iter+1;i<=iter+4;i++){
        print("T2: "+ str(i));
        }

        iter += 5;

        t1_flag=true;       // Thread 1 is released
        cv2.notify_one();      // thread 1 is started
        t2_flag=false;          // thread 2 is waiting for thread 1
    }

}

int main(){

print("Main-Start");

std::thread t1(producer);
std::thread t2(consumer);

t1.join();
t2.join();

print("Main-end");
return 0;

}