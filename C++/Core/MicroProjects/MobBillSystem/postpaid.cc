#include "postpaid.h"
#include <iostream>

PostpaidCustomer::PostpaidCustomer(): CustomerBase(){ }
PostpaidCustomer::PostpaidCustomer(int id,std::string name,std::string phn,double bal): CustomerBase(id,name,phn,bal)
                                                                                                         {}


PostpaidCustomer::PostpaidCustomer(int id,std::string name,std::string phn): CustomerBase(id,name,phn){}


void PostpaidCustomer::credit(double amount)
{
     //billPay(amount);
      m_balance -= amount;
}
void PostpaidCustomer:: makeCall(double nmins)
{

    m_balance += nmins;
}

/*
int  PostpaidCustomer::getCustomerId()
{
    return m_custId;
}

std:: string  PostpaidCustomer:: getCustomerName()
{
    return m_custName;
}
std:: string  PostpaidCustomer::getPhone()
{
    return m_phone;
}
double  PostpaidCustomer:: getBalance()
{
    return m_balance;
}

*/
