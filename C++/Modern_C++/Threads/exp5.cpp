
/* __Basis Threads__
1. Create Thread Handler(Declaration)
2. Syncronise Threads(by Join)

g++ thread.cpp -lpthread && ./a.out

*/





//__Lamda Function for Thread__




//__Multiple Threads___

#include <iostream>
#include <thread>
#include <chrono>
#include <string>  

//___Alias Names__
#define print(msg) std::cout << msg << std::endl
#define str(i) std::to_string(i)

// Global Variables
constexpr int max =5;
std::chrono::milliseconds delay(1000);

void print_range(int start,int end) {
  std::cout << "printing range from:" << start << "to:" << end << "\n";
  for(int i=start;i<=end;i++) {
    std::cout << i << "\n";
    std::this_thread::sleep_for(delay);
  }
}
int main() {
  std::cout << "Main -- Welcome\n";
  int start,end,i;
  int n=10;
  std::thread tarr[n];//default ctor
  for(int i=0;i<n;i++) {            // Creating Threads
    start = i*10+1;
    end = start+10;
    tarr[i] = std::thread(print_range,start,end);
  }
  for(i=0;i<n;i++)      // Threads 
    tarr[i].join();
  return 0;
}
