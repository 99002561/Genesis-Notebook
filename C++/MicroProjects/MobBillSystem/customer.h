#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include<string>


const double call_rate = 1.0;

class CustomerBase
{
 protected:

  int m_custId;
  std::string m_custName;
  std::string m_phone;
  double m_balance;


  public:

  CustomerBase();
  CustomerBase(int,std::string,std::string,double);
  CustomerBase(int,std::string,std::string);

  virtual void credit(double)=0;           //recharge or billPay
  virtual void makeCall(double)=0;

  double getBalance();
  int getCustomerId();
  std:: string getCustomerName();
  std:: string getPhone();

  void display();
};



#endif // CUSTOMER_H_INCLUDED
