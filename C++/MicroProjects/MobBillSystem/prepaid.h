#ifndef PREPAID_H_INCLUDED
#define PREPAID_H_INCLUDED


#include<string>


#include "customer.h"

class PrepaidCustomer : public CustomerBase
 {

  public:

  PrepaidCustomer();
  PrepaidCustomer(int,std::string,std::string,double);
  PrepaidCustomer(int,std::string,std::string);

  void credit(double);           //recharge or billPay
  void makeCall(double);

  /*double getBalance();
  int getCustomerId();
  std:: string getCustomerName();
  std:: string getPhone(); */


};

#endif // PREPAID_H_INCLUDED
