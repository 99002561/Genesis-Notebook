//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"
#include<string>
class distance
{
public:
	int feet, inch;

public:
	distance();
	distance(int, int);
	distance operator+(const distance&);
	distance operator-(const distance&);

	distance operator+(int);
	distance operator-(int);
	distance operator++();
	distance operator++(int);
	bool operator==(const distance&);
	bool operator<(const distance&);
	bool operator>(const distance&);
	void display();
	int get_feet();
	int get_inch();


};