//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"
#include<string>
class customer {
	int customerId; // ideally to be of string type
	std::string customerName;
	double balance;

public:
	customer();
	customer(int, std::string, double);
	customer(const customer&);
	void credit(double);
	void makecall(std::string);
	double getbalance();
	void display();
};
