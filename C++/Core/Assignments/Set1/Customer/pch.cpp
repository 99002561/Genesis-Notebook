//
// pch.cpp
// Include the standard header and generate the precompiled header.
//

#include "pch.h"
#include<iostream>
customer::customer() :
    customerId(0), customerName(""), balance(0) {

}
customer::customer(int id, std::string name, double bal) :
    customerId(id), customerName(name), balance(bal) {

}
customer::customer(const customer& ref) :
    customerId(ref.customerId), customerName(ref.customerName),
    balance(ref.balance) {

}
void customer::credit(double amount) {
    balance += amount;
}

double customer::getbalance()  {
    return balance;
}
void customer::display() {
    std::cout << customerId << "," << customerName << ","
        << balance << "\n";
}
