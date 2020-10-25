//
// pch.cpp
// Include the standard header and generate the precompiled header.
//

#include "pch.h"
#include<iostream>
distance::distance() :feet(0), inch(0) {}

distance::distance(int x, int y) : feet(x), inch(y) {}

distance distance::operator+(const distance& d1)
{
	distance temp;
	temp.feet = d1.feet + feet;
	temp.inch= d1.inch + inch;
	temp.feet = temp.feet + (temp.inch / 12);
	temp.inch = temp.inch % 12;
	return temp;

}
distance distance::operator-(const distance& d1)
{
	distance temp;
	int a, b;
	a = (d1.feet * 12) + d1.inch;
	b = feet * 12 + inch;
	//temp.feet = d1.feet - feet;
	temp.inch = a-b;
	temp.feet =(temp.inch / 12);
	temp.inch = temp.inch-(temp.feet*12);
	return temp;
}
distance distance::operator+(int a)
{
	distance temp;
	temp.feet =a + feet;
	temp.inch = a + inch;
	temp.feet = temp.feet + (temp.inch / 12);
	temp.inch = temp.inch % 12;
	return temp;
}
distance distance::operator-(int x)
{
	distance temp;
	int a, b;
	a = (x * 12) + x;
	b = feet * 12 + inch;
	//temp.feet = d1.feet - feet;
	temp.inch = a - b;
	temp.feet = (temp.inch / 12);
	temp.inch = temp.inch - (temp.feet * 12);
	return temp;
}

distance distance::operator++()
{
	distance temp;
	temp.feet = feet;
	temp.inch =inch + 1;
	if (temp.inch >=12)
	{
		temp.feet = temp.feet + 1;
		temp.inch = 0;
	}
	return temp;
}
distance distance::operator++(int dummy)
{

	distance temp;
	temp.feet = feet;
	temp.inch = inch;
	if (inch >= 12)
	{
		feet = feet + 1;
		inch = 0;
	}
	
	return temp;
}
bool distance::operator==(const distance& d1)
{
	if (d1.feet == feet && d1.inch == inch)
		return true;
	else
		return false;
}
bool distance::operator<(const distance& d1)
{
	if (d1.feet > feet && d1.inch > inch)
		return true;
	else
		return false;
}
bool distance::operator>(const distance& d1)
{
	if (d1.feet < feet && d1.inch < inch)
		return true;
	else
		return false;
}
void distance::display()
{
	std::cout << "distance is:" << feet << "feets &" << inch << " inces.";
}
int distance::get_feet()
{
	return feet;
}
int distance::get_inch()
{
	return inch;
}
