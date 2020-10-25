//
// pch.cpp
// Include the standard header and generate the precompiled header.
//

#include "pch.h"

using namespace std;

Box::Box() : m_length(0), m_height(0), m_breadth(0) {}
Box::Box(int x) : m_length(x), m_height(x), m_breadth(x) { }
Box::Box(int x, int y, int z) : m_length(x), m_height(y), m_breadth(z) { }
Box::Box(const Box& obj) : m_length(obj.m_length), m_height(obj.m_height), m_breadth(obj.m_breadth) { }

int Box::length()
{
	return m_length;
}
int Box::height()
{
	return m_height;
}

int Box::breadth()
{
	return m_breadth;
}
int Box::volume()
{
	return m_length * m_height * m_breadth;
}
void Box::display()
{
	cout << "(Length, Height, Breadth) = (" << m_length << ", " << m_height << "," << m_breadth << ")" << endl;

}

