#include "customer_order.h"
#include "restaurant.h"

Customer_order::Customer_order():Restaurant(){Oid=0;
Qty=0;
address="";
price=0;}
Customer_order::Customer_order(long int num,std::string name,std::string loc,bool avail,int ord,int quan,std::string addr,int pr): Restaurant(num,name,loc,avail){
Oid=ord;
Qty=quan;
address=addr;
price=pr;
}


/* int Customer_order:: findQty()
 {
 return (distance * mile_rateINR);
 }

 int Customer_order:: countOrder()
 {
  double temp = static_cast<double> (distance) /SpeedInHr;
  return temp * 60;
 }


*/


int Customer_order::getOrderId()
{
    return Oid;
}
int Customer_order::getQty()
{
    return Qty;
}

std:: string Customer_order::getAddress()
{
    return address;
}

int Customer_order::getPrice()
{
    return price;
}
