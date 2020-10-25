#ifndef RESTAURANT_H_INCLUDED
#define RESTAURANT_H_INCLUDED

#include<string>
#include <iostream>
class Restaurant
{
    long int res_number;
    std::string res_name;
    std::string location;
    bool order_avail;

public:
    Restaurant();
    // ress_number,res_name,location,orderAvail
    Restaurant(long int,std::string,std::string,bool);

    virtual long int getResNo();
    virtual std::string getResName();
    virtual std::string getLocation();
    virtual bool getOrder_avail();
    void display();

};

#endif // RESTAURANT_H_INCLUDED
