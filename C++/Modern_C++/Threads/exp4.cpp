// __ Data Driven Threads__

/*

void compute(std::string label) {
  std::cout << "Thread--" << label << "\n";
  for(int i=1;i<=max;i++) {
    std::cout << label << "--" << i << "\n";
    std::this_thread::sleep_for(delay);
  }

std::thread t1(std::bind(compute, "A"));
std::thread t2(std::bind(compute, "B"));


  


std::thread t1(std::bind(compute, "A"));
  //std::thread t2(std::bind(compute, "B"));
  std::thread t2(compute, "B");                 //also works
  std::thread t3([]() {
    compute("C");
  });


  */
