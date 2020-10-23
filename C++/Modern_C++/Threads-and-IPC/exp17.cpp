/*__promise example3_

Array of Promises are for creating multiple promises 
between threads

Here Multiple promise is between Thread1 and Main Thread

g++ exp17.cpp -lpthread && ./a.out

*/


#include <iostream>
#include <string>
#include <future>


#define print(msg) std::cout << msg << std::endl
#define str(i) std::to_string(i)

std::promise<int> prr[5];

void compute(){
  int sum;
  print("Thread-1");
  for(int i=0;i<=20;i++){
      sum+=i;
      if(i%5 == 0){
        print( "Compute-" + str(i/5) + ": " + str(sum) );
        prr[i/5].set_value(sum);
      }
   }  
}
 
int main() {

  print("Main");
  std::thread t1(compute);

  print("Getting Result..");  
  std::future<int> result[5];       // to store the result handler

  for(int i=0;i<5;i++)
  {
    result[i] = prr[i].get_future();
    print("Main-"+ str(i)+": " +str(result[i].get()) );
  }
  
  t1.join();   // Wait until all the promise is completed
  print("end");
  return 0;
}

/* Output

Main
Getting Result..
Thread-1
Compute-0: 0
Compute-1: 15
Compute-2: 55
Compute-3: 120
Compute-4: 210
Main-0: 0
Main-1: 15
Main-2: 55
Main-3: 120
Main-4: 210
end

*/