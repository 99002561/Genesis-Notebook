#ifndef POSTPAID_H_INCLUDED
#define POSTPAID_H_INCLUDED

#ifndef __POSTPAID_H
#define __POSTPAID_H

#include<string>


#include "customer.h"

class PostpaidCustomer : public CustomerBase
 {
  public:

  PostpaidCustomer();
  PostpaidCustomer(int id,std::string name,std::string phn,double bal);
  PostpaidCustomer(int id,std::string name,std::string phn);

  void credit(double);           //recharge or billPay
  void makeCall(double);

  /*
  double getBalance();
  int getCustomerId();
  std:: string getCustomerName();
  std:: string getPhone();
 */

};

#endif

#endif // POSTPAID_H_INCLUDED
