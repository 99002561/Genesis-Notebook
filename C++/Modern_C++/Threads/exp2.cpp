// __Example 2__Basic2 with for loop
//g++ thread.cpp -lpthread && ./a.out



#include <iostream>
#include <thread>

#define print(msg) std::cout << msg << std::endl
constexpr int max =5; 

void fsample(){
    print("Thread A"); 
    for(int i=0;i<=max;i++){
      print(i);   
    }
}

void gcompute(){
    print("Thread B");
    for(int i=0;i<=max;i++){
      print(i);   
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
