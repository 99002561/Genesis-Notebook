/* __example 15__Call function asynchronously

* future header
  fn(args){}
  std::async(fn,args)
* This creates threads to call fn(with args as arguments) 
* it returns without waiting for completion of fn is 
* The value returned by fn can be accessed through the future object 
* here the shared state contains are returned by fn
* return declaration: std::future<functionReturn type>
* return getting (by calling its member future::get)

std::future<int> result1;   // future object as return type
result.get();               // waits(as join) and returns fn result in future type

g++ exp15a.cpp -lpthread && ./a.out

*/


#include <iostream>
#include <string>
//#include <thread>
#include <future>

#define print(msg) std::cout << msg << std::endl
#define str(i) std::to_string(i)

int sumArray(int *arr,int len){
    int sum=0;
    for(int i=0;i<len;i++)
        sum+=arr[i];
    return sum;
}   


int main(){
print("Main");
int arr[10] = {1,2,3,4,5,6,7,8,9,10};

std::future<int> result;
result= std::async(sumArray, arr ,10);

print("Results Computing...");
print("Result: " + str(result.get()));

print("end");


}

/* Output

Main
Results Computing...
Result: 55
end

*/