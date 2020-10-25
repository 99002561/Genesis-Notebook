/* __class for Stack__

This class represents simple stack 
stack if of last in first out

g++ exp14a.cpp -lpthread && ./a.out

*/
#include <iostream>
#include <string>

#define print(msg) std::cout << msg << std::endl
#define str(i) std::to_string(i)


class Stack {
  int *m_arr;
  int maxlen;
  int m_ptr;
  public:

  Stack(int len):maxlen(len),m_ptr(-1) { 
    m_arr = new int[len];
  }

  ~Stack() {
    if(m_arr!=nullptr)
        delete[] m_arr;
  }

  void push(int val) {
    std::cout<< "push: " << val << std::endl; 
    m_arr[++m_ptr]=val;
  } 

  int pop() {
    return m_arr[m_ptr--];
  }

  bool isFull() const { return m_ptr==maxlen-1; }
  bool isEmpty()  const { return m_ptr==-1; }

};

int main(){
  Stack s1(5);      // stack of 5 elements for integer

  std::cout << std::boolalpha;  // 1/0 ot true/false

  print(s1.isEmpty()); // Initially
  s1.push(1);
  s1.push(2);
  std::cout<<"Stack Status after 5 elements push: " << s1.isFull() << std::endl ;
  s1.push(3);
  s1.push(4);
  s1.push(5);
  std::cout<<"Stack Status after 5 elements push: " << s1.isFull() << std::endl ;
  print("Stack:");
  for(int i=0;i<5;i++)
    print(s1.pop());
  
}


/* Output

true
push: 1
push: 2
Stack Status after 5 elements push: false
push: 3
push: 4
push: 5
Stack Status after 5 elements push: true
Stack:
5
4
3
2
1


*/

