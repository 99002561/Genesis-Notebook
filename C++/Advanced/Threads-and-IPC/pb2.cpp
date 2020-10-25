Deadlock Scenario 1(2 Shared Resources)
    std::mutex m1;
    std::mutex m2;

    T1                  T2   
    m1.lock()           m2.lock
    delay()             m1.lock
    m2.lock()                   

    Solution:
    * using diff_lock and atomic lock
    std::unique_lock<std::mutex> u1(m1,std::def_lock)  //Global
    std::unique_lock<std::mutex> u2(m2,std::def_lock)
    std::lock(u1,u2)
    