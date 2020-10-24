#ifndef __TRAINEE_H
#define __TRAINEE_H

#include "Employee.h"

class Trainee : public Employee {
  std::string m_track;
  double score;
  public:
  Trainee(std::string, std::string, double ,std::string ,double );
  int payroll();
  int appraisal(int);
  void display();
};

#endif
