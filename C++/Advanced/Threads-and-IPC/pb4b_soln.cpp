
/* __class for Stack(overcoming overflow)__

* This class represents simple stack 
* stack if of last in first out
* Features:
  * Mutual Exclusion(Mutex) - to avoid race condition,
  * parallel push and push using threads
  * push and pop operation snych 
    by Condition Variable  

g++ pb4b_soln.cpp -lpthread && ./a.out

*/
#include <iostream>
#include <string>
#include <mutex>
#include <functional>
#include <thread>
#include <future>
#include <condition_variable>

#define print(msg) std::cout << msg << std::endl
#define str(i) std::to_string(i)


class Stack {
  int *m_arr;
  int maxlen;
  int m_ptr;
  std::mutex m1;
  std::condition_variable ucv;
  std::condition_variable ocv;

  public:

  Stack(int len):maxlen(len),m_ptr(-1) { 
    m_arr = new int[len];
  }

  ~Stack() {
    if(m_arr!=nullptr)
        delete[] m_arr;
  }

  // Push should wait untill the stack if stack is full
  void push(int val) {
    print("Thread-Push");
    std::unique_lock<std::mutex> lck(m1);
    ocv.wait(lck, [=]{ return isVacancy(); });    //wait if the stack is full
    m_arr[++m_ptr]=val;
    std::cout<< "Push: " << val << std::endl; 
    ucv.notify_one();
    
  } 

  // Pop should wait untill the stack is empty

  int pop() {
    print("Thread-Pop");
    std::unique_lock<std::mutex> lck(m1);
    ucv.wait(lck,[=]{ return !isEmpty(); });   // wait if stack is empty
    int val=m_arr[m_ptr--];
    std::cout<< "Pop: " << val << std::endl; 
    ocv.notify_one();
    return val;
  }

  bool isFull() const { return m_ptr==maxlen-1; }
  bool isVacancy() const { return m_ptr<maxlen-1; }
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
  
  print("Normal Push -- start");
  s1.push(1);
  s1.push(2);
  s1.display();
  print("Normal Push -- end");

  
  //std::thread t1(&Stack::push,stackPtr,2);
  std::thread t1(std::bind(&Stack::push,stackPtr,3));
  std::thread t2(&Stack::pop,stackPtr);
  
  /*
  std::future<int> result = std::async(&Stack::pop,stackPtr);
  //std::thread t2(&Stack::pop,stackPtr);
  print("pop: "+str(result.get()));*/


  t1.join();
  t2.join();
  s1.display();


  print("Main end");

  return 0;
}

/* output preventing overflow


Main
Normal Push -- start
Thread-Push
Push: 1
Thread-Push
Push: 2
Stack: 
2
1
Normal Push -- end
Thread-Push
Thread-Pop
Pop: 2
Push: 3
Stack: 
3
1
Main end



*/