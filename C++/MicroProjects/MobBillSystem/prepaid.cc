#include "prepaid.h"


PrepaidCustomer::PrepaidCustomer():CustomerBase(){}
PrepaidCustomer::PrepaidCustomer(int id,std::string name,std::string phn,double bal): CustomerBase(id,name,phn,bal){}
PrepaidCustomer::PrepaidCustomer(int id,std::string name,std::string phn):CustomerBase(id,name,phn){}

void PrepaidCustomer:: credit(double amount)           //recharge or billPay
{
   m_balance += amount;
}
void PrepaidCustomer:: makeCall(double nmins)
{
   m_balance -= nmins*call_rate;
}

/*
int  PrepaidCustomer::getCustomerId()
{
    return m_custId;
}

std:: string  PrepaidCustomer:: getCustomerName()
{
    return m_custName;
}
std:: string  PrepaidCustomer::getPhone()
{
    return m_phone;
}
double  PrepaidCustomer:: getBalance()
{
    return m_balance;
}

*/
