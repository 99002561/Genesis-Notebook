//__Example3__ Basic with Delay
#include <iostream>
#include <thread>
#include <chrono>
#include<string>  

constexpr int max =5;

#define print(msg) std::cout << msg << std::endl
#define str(i) std::to_string(i)

std::chrono::milliseconds delay(1000);
//std::chrono::duration<int,std::milli> delay(1000);


void fsample(){
    print("Thread A"); 
    for(int i=0;i<=max;i++){
      print("A-" + str(i));   
      std::this_thread::sleep_for(delay);
    }
}

void gcompute(){
    print("Thread B");
    for(int i=max;i>=0;i--){
      print("B-" + str(i));   
      std::this_thread::sleep_for(delay); 
    }
}

int main(){
    print("Main-- Welcome");
    std::thread t1(fsample);    // Created Thread1 for fsample
    std::thread t2(gcompute); // 2nd Parallel Thread
    t1.join();
    t2.join();
    print("Thankyou");
    return 0;

}