#include "billing.h"
#include "customer.h"
#include "prepaid.h"
#include "postpaid.h"

#include <list>
#include <iterator>

void MobileBilling::addCustomer(int id,std::string name,std::string phn,double bal)
{
    cust.push_back(PrepaidCustomer(id,name,phn,bal));
}

void MobileBilling::removeCustomer(int id)
{
    std::list<PrepaidCustomer> :: iterator iter;

    for(iter=cust.begin();iter!=cust.end();iter++)
    {
        if(iter->getCustomerId()== id)
        {
           cust.erase(iter);
           break;
        }
    }
}

PrepaidCustomer* MobileBilling:: findCustomerById(int id)
{
     std::list<PrepaidCustomer> :: iterator iter;

    for(iter=cust.begin();iter!=cust.end();iter++)
    {
        if(id == iter->getCustomerId())
        {
            return &(*iter);
        }
    }
    return NULL;

}
PrepaidCustomer* MobileBilling:: findCustomerByPhone(std::string phn)
{
    std::list<PrepaidCustomer> :: iterator iter;

    for(iter=cust.begin();iter!=cust.end();iter++)
    {
        if( phn == iter->getPhone())
        {
            return &(*iter);
        }
    }

    return NULL;

}
double MobileBilling:: findAverageBalance()
{
    double sum=0;
    std:: list <PrepaidCustomer> :: iterator iter;
    for(iter=cust.begin();iter!=cust.end();iter++)
    {
        sum = sum+ iter-> getBalance();
    }

    return sum/cust.size();

}
double MobileBilling:: findMaxBalance()
{
    std:: list<PrepaidCustomer> :: iterator iter = cust.begin();
    auto maxBal  = iter->getBalance();
   // auto maxiter = iter;
    iter++;
    for(;iter!=cust.end();++iter)
    {
        if(maxBal < iter->getBalance())
        {
            maxBal = iter->getBalance();
           // maxiter = iter;
        }

    }
    return maxBal;

}

int MobileBilling:: countByMinBalance(double minval)
{
     int count=0;
   std::list <PrepaidCustomer> :: iterator iter;
   for(iter=cust.begin();iter!=cust.end();iter++)
   {
       if(iter->getBalance() >= minval)
        count++;
   }
   return count;
}

int MobileBilling:: countAll()
{
   return cust.size();
}
