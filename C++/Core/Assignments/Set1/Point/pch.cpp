//
// pch.cpp
// Include the standard header and generate the precompiled header.
//

#include "pch.h"
#include<iostream>
using namespace std;

Point::Point() :x(0), y(0) { }
Point::Point(int a,int b) : x(a), y(b) { }
Point::Point(const Point& ref) : x(ref.x), y(ref.y) { }
bool Point::isorigin()
{
	if (x == 0 && y == 0)
		return true;
	else
		return false;

}
int Point::distancefromorigin()
{
	int result;
	result = sqrt((x * x) + (y * y));
	return result;
}
bool Point::isonXaxis()
{
	if (y == 0)
		return true;
	else
		false;
}
bool Point::isonYaxis()
{
	if (x == 0)
		return true;
	else
		false;
}
void Point::display()
{
	std::cout << "x is:" << x << "y is:" << y;
}
quadrant Point::Quadrant()
{
	if (x > 0 && y > 0)
	{
		return q1;
	}
	if (x > 0 && y < 0)
	{
		return q4;
	}
	if (x < 0 && y > 0)
	{
		return q2;
	}
	if (x < 0 && y < 0)
	{
		return q3;
	}

}
