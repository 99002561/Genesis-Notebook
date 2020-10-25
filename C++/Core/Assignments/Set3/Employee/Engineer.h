#ifndef __ENGINEER_H
#define __ENGINEER_H

#include "Employee.h"

class Engineer : public Employee {
  int m_projCode;
  public:
  Engineer(std::string, std::string , double ,int ,int );
  int payroll();
  int appraisal(int);
  void display();
};

#endif

