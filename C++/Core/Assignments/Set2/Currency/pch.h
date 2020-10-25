//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"
class Currency
{
private:
	int m_rupees, m_paise;
public:
	Currency();
	Currency(int, int);
	Currency(const Currency&);
	Currency operator + (const Currency&);
	Currency operator - (const Currency&);
	Currency operator + (int);
	Currency operator - (int);
	Currency& operator ++ (); //pre
	Currency operator ++ (int); //post
	int operator == (const Currency&);
	int operator >(const Currency&);
	int operator <(const Currency&);
	int get_mrupees();
	int get_mpaise();
	void display();


};