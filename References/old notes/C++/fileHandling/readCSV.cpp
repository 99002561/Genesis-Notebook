#include "importDataset.h"

int main()
{
//importDataset("bankDatabase.csv");
std::list<MoneyRemittance> l_mrCust = importDataset("bankDatabase.csv");
std::list<MoneyRemittance> :: iterator iter;

    for(iter=l_mrCust.begin();iter!=l_mrCust.end();iter++)   //Scan Database to find the customer
    {
        std::string tempLine = iter->getCustomerName();
        std::cout << tempLine << std::endl;
        
    }

}

//void displayList(std::list<>)