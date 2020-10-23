/* __class for Stack__

* This class represents simple stack 
* stack if of last in first out
* Features:
  * Mutual Exclusion(Mutex) - to avoid race condition,
  * parallel push and push using threads
*Implementation:
  1. std::bind(&Stack::push, s1, val)
  2. [] () { s1.push(val) }
  3. std::thread()    //similar for bind syntax

g++ exp14b.cpp -lpthread && ./a.out

*/
#include <iostream>
#include <string>
#include <mutex>
#include <functional>
#include <thread>

#define print(msg) std::cout << msg << std::endl
#define str(i) std::to_string(i)

class Stack {
  int *m_arr;
  int maxlen;
  int m_ptr;
  std::mutex m1;

  public:

  Stack(int len):maxlen(len),m_ptr(-1) { 
    m_arr = new int[len];
  }

  ~Stack() {
    if(m_arr!=nullptr)
        delete[] m_arr;
  }

  void push(int val) {
    print("Thread-1");
    m1.lock();
    std::cout<< "push: " << val << std::endl; 
    m_arr[++m_ptr]=val;
    m1.unlock();
  } 

  int pop() {
    print("Thread-2");
    m1.lock();
    int val=m_arr[m_ptr--];
    std::cout<< "pop: " << val << std::endl; 
    m1.unlock();
    return val;
  }

  bool isFull() const { return m_ptr==maxlen-1; }
  bool isEmpty()  const { return m_ptr==-1; }
  
};

int main(){
  print("Main");

  Stack s1(2);

  // std::thread t1(std::bind(&Stack::push, s1, 2));
  // std::thread t1(funct,2);   // will not work

  std::thread t1([=] () { return s1.push; });
  //std::thread t2(s1.pop());
  

  
    t1.join();
 // t2.join();

  print("Main end");

  return 0;
}