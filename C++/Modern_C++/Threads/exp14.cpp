
/*
Stack Example


*/
void push(int val) {
 std::unique_lock<std::mutex> ulck(m1);
    ocv.wait(ulck, [] { return !isFull(); }
    m_arr[++m_top]=m_val;
    ucv.notify_one();
  }
  int pop() {
    std::unique_lock<std::mutex> ulck(m1);
    ucv.wait(ulck, [] { return !isEmpty(); }
    int val=m_arr[m_top--];
    ocv.notify_one();
    return val;
  }