#ifndef BILL_H_INCLUDED
#define BILL_H_INCLUDED


#include "customer_order.h"
//#include "restaurant.h"

#include <iostream>
#include <list>
#include <iterator>

class Bill
{
    std::list <Customer_order> order;

public:

   bool addOrder(long int num,std::string name,std::string loc,bool avail,int ord,int quan,std::string addr,int pr);
   bool removeOrder(int);
   Customer_order* findOrderById(int);
   //Customer_order* findOrderByAddress(std::string);

   int findQty();
   int countAll();
   void display();
};

#endif // BILL_H_INCLUDED
