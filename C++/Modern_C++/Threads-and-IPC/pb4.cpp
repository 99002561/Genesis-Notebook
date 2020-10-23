/* __class for Stack with sync problem__

* This class represents simple stack 
* stack if of last in first out
* Features:
  * Mutual Exclusion(Mutex) - to avoid race condition,
  * parallel push and push using threads
* Synchronisation problem

g++ pb4.cpp -lpthread && ./a.out

*/
#include <iostream>
#include <string>
#include <mutex>
#include <functional>
#include <thread>
#include <future>

std::chrono::milliseconds delay(1000);

#define print(msg) std::cout << msg << std::endl
#define str(i) std::to_string(i)
#define threadSleep std::this_thread::sleep_for(delay)

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
    threadSleep;
    m1.lock();
    std::cout<< "Push: " << val << std::endl; 
    m_arr[++m_ptr]=val;
    m1.unlock();
  } 

  int pop() {
    print("Thread-2");
    m1.lock();
    int val=m_arr[m_ptr--];
    m1.unlock();
    return val;
  }

  bool isFull() const { return m_ptr==maxlen-1; }
  bool isEmpty()  const { return m_ptr==-1; }

   void display(){
    print("Stack: ");
    for(int i=maxlen-1;i>=0;i--)
      print(m_arr[i]);
    }
  
  
};

int main(){
  print("Main");

  Stack s1(2);
  Stack *stackPtr = &s1;

  //std::thread t1(&Stack::push,stackPtr,2);
  std::thread t1(std::bind(&Stack::push,stackPtr,2));
  std::thread t2(std::bind(&Stack::pop,stackPtr));
  
  //std::thread t2(&Stack::pop,stackPtr);
  
  t1.join();
  t2.join();
  s1.display();

  print("Main end");

  return 0;
}

/*Ouput - 

Main
Thread-1
Thread-2
Push: 2
Stack: 
0
0
Main end
double free or corruption (out)
Aborted (core dumped)

Observation: Pop thread was scheduled 1st 
    * stack status was empty 
    * m_ptr = -2
    * next push thread is missed and the ouput is notpredectible

Solution: 
* pop should wait until the stack is filled and it should not 
    work when the stack is empty ie. underflow
* push should wait until the stack is vacant and not try to overflow
* implementation:
    CondtionVariables for both underfow and overflow condition

    push
    ocv.wait(lck, [=]{ return isVacancy(); }); 
    ucv.notify_one();

    pop
    ucv.wait(lck,[=]{ return !isEmpty(); }); 
    ocv.notify_one();


    where lck is unique lock over mutex
*/