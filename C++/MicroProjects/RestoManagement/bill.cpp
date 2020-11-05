#include "customer_order.h"
#include "bill.h"

#include <list>
#include <iterator>


bool Bill::addOrder(long int num,std::string name,std::string loc,bool avail,int ord,int quan,std::string addr,int pr)
{
	order.push_back(Customer_order(num, name, loc, avail, ord, quan, addr, pr));
	return true;
}

bool Bill::removeOrder(int ord_id)
{
	std::list<Customer_order> :: iterator iter;

   	for(iter=order.begin();iter!=order.end();iter++)
    	{
        	if(iter-> getOrderId()==ord_id)
        	{
           	order.erase(iter);
           	return true;
        	}
    	}
    	return false;

}

Customer_order* Bill::findOrderById(int ord_id)
{
	std::list<Customer_order> :: iterator iter;

   	for(iter=order.begin();iter!=order.end();iter++)
    	{
        	if(iter->getOrderId()== ord_id)
        	{
           		return &(*iter);
        	}
    	}
    	return NULL;
}



int Bill::countAll()
{
	return order.size();
}
