#ifndef CUSTOMER_ORDER_H_INCLUDED
#define CUSTOMER_ORDER_H_INCLUDED

#include<string>
#include "restaurant.h"

class Customer_order : public Restaurant
{
    int Oid;
    int Qty;
    std::string address; // Customer address
    int price;
public:
    Customer_order();
    //res_number,res_name,location,orderAvail
    Customer_order(long int,std::string,std::string,bool,int,int,std::string,int);
    int getOrderId();
    int getQty();
    std::string getAddress();
    int getPrice();

    int findQty();
    int countOrder(int);
};


#endif // CUSTOMER_ORDER_H_INCLUDED
