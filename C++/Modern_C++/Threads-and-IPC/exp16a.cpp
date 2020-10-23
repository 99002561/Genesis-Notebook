/*__promise example1_
To send the value to other threads when ever needed
i.e can send the data in between also

Declaration: This is done Globally or common
std::promise<int> p1;  

g++ exp16a.cpp -lpthread && ./a.out

*/


#include <iostream>
#include <string>
#include <future>


#define print(msg) std::cout << msg << std::endl
#define str(i) std::to_string(i)

std::promise<int> p1;

void compute(){
  print("Thread-1");
  p1.set_value(20);
  for(int i=0;i<20;i++)
    print("Hello..." + str(i));

}
 
int main() {
  print("Main");
  std::thread t1(compute);  //Create a thread

  print("Getting Result...");  
  std::future<int> result = p1.get_future();
  print("No of Intrs: " + str(result.get()));
  t1.join(); // Wait until the thread finish
  print("Main - end");
  return 0;
}


/* Output

Main
Getting Result...
Thread-1
Hello...0
Hello...1
Hello...2
Hello...3
Hello...4
Hello...5
Hello...6
Hello...7
Hello...8
Hello...9
Hello...10No of Intrs: 20       --> Value received in between
Hello...11
Hello...12
Hello...13
Hello...14
Hello...15
Hello...16
Hello...17
Hello...18
Hello...19

Main - end

*/