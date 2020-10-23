/*__promise example2_
To send the value to other threads when ever needed
i.e can send the Ack in between also
std::promise<void> p1;

g++ exp16b.cpp -lpthread && ./a.out

*/


#include <iostream>
#include <string>
#include <future>


#define print(msg) std::cout << msg << std::endl
#define str(i) std::to_string(i)

std::promise<void> ack;

void compute(){
  print("Thread-1");
  for(int i=0;i<3;i++)
    print("Hello..." + str(i));
  ack.set_value();   // send ack when the thread is completed

}
 
int main() {
  print("Main");
  std::thread t1(compute);  //Create a thread

  print("Getting Ack..."); 
  std::future<void> ackFuture = ack.get_future();
  ackFuture.wait();   // Wait until thread1 gives confirmation
  print("Thread1 Completed");

  t1.join(); // Wait until the thread finish
  print("Main - end");
  return 0;
}


/* Output

Main
Getting Ack...
Thread-1
Hello...0
Hello...1
Hello...2
Thread1 Completed           --->This is from Main Thread
Main - end

*/