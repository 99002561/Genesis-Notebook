/* __Basis Threads__
1. Create Thread Handler(Declaration)
2. Syncronise Threads(by Join)

g++ thread.cpp -lpthread && ./a.out

*/

// __Example 1__ Task Driven Thread

#include <iostream>
#include <thread>

#define print(msg) std::cout << msg << std::endl

void fsample(){
    print("Thread A"); 
}

void gcompute(){
    print("Thread B");
}

int main(){
    print("Main-- Welcome");
    std::thread t1(fsample);    // Created Thread1 for fsample
    std::thread t2(gcompute); // 2nd Parallel Thread
    t1.join();
    t2.join();   // Thread Sync
    print("Thankyou");
    return 0;

}
