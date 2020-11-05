#include "restaurant.h"
#include <iostream>


Restaurant::Restaurant():res_name(""),res_number(0),location(""),order_avail(""){}

Restaurant::Restaurant(long int num,std::string name,std::string add,bool avail):res_number(num),res_name(name),
                                                                                       location(add),
                                                                                      order_avail(avail){}
std:: string Restaurant::getResName()
{
    return res_name;
}                                                                             

long int Restaurant::getResNo() 
{
    return res_number;
}

std::string Restaurant::getLocation()
{
	return location;
}

bool Restaurant::getOrder_avail()
{
    return order_avail;
}
void Restaurant:: display()
{
    std:: cout << res_number <<","<< res_name<<"," << location << ","<< order_avail <<std::endl;
}
