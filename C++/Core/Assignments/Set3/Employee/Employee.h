#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

class IEmployee {
  public:
  virtual int payroll()=0;
  virtual int appraisal(int)=0;
};

class Employee:public IEmployee {
  protected:
  std::string m_empid;
  std::string m_name;
  double m_salary;
  int m_exp;
  public:
  Employee(std::string , std::string , double ,int);
  virtual void display() = 0;
};

#endif
