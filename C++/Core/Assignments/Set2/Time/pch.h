//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"
#include<string>
class mytime
{
public:

	int h, m, s;
public:
	mytime();
	mytime(int, int, int);
	mytime(int, int);
	mytime operator+(const mytime&);
	mytime operator-(const  mytime&);

	mytime operator+(int);
	mytime operator-(int);
	mytime operator++();
	mytime operator++(int);
	bool operator==(const mytime&);
	bool operator<(const mytime&);
	bool operator>(const mytime&);
	void display();
	int geth();
	int getm();
	int getsec();

};
