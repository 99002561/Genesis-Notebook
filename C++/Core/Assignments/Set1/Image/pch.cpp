//
// pch.cpp
// Include the standard header and generate the precompiled header.
//

#include "pch.h"
#include<iostream>

using namespace std;
Image::Image() : m_x(0), m_y(0), m_width(0), m_height(0) { }
Image::Image(int x, int y, int width, int height) : m_x(x), m_y(y), m_width(width), m_height(height) { }

Image::Image(const Image& obj) : m_x(obj.m_x), m_y(obj.m_y), m_width(obj.m_width), m_height(obj.m_height) { }

void Image::move(int new_x, int new_y)
{
	m_x = new_x;
	m_y = new_y;
}

void Image::scale(int scale_parameter)
{
	m_width = m_width * scale_parameter;
	m_height = m_height * scale_parameter;
}

void Image::resize(int width_value, int height_value)
{
	m_width = m_width + width_value;
	m_height = m_height + height_value;
}
int Image::getm_x()
{
	return m_x;
}
int Image::getm_y()
{
	return m_y;
}
int Image::getm_width()
{
	return m_width;
}
int Image::getm_height()
{
	return m_height;
}
void Image::display()
{
	cout << "Index: " << "(X,Y) = (" << m_x << ", " << m_y << ")"<<endl;
		cout << "Image:" << "(width, height) = (" << m_width << ", " << m_height << ")" << endl;
}

