//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"

class Complex
{
private:
	int m_real,m_imag;
public:
	Complex();
	Complex(int, int);
	Complex(const Complex&);
	Complex operator + (const Complex&);
	Complex operator - (const Complex&);
	Complex operator * (const Complex&);
	Complex operator ++ (); //pre
	Complex operator ++ (int); //post
	Complex operator == (const Complex&);
	int get_mreal();
	int get_mimag();
	void display();


};