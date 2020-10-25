#ifndef __MANAGER_H
#define __MANAGER_H

#include "Employee.h"

class Manager : public Employee {
  int m_projCode;
  int m_reportees;
  public:
  Manager(std::string , std::string , double ,int ,int ,int );
  int payroll();
  int appraisal(int);
  void display();
};

#endif
