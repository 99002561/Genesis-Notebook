//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"


class Image
{
private:
	int m_x, m_y;
	int m_width, m_height;
public:
	Image();
	Image(int, int, int, int);
	Image(const Image&);
	void move(int, int);
	void scale(int);
	void resize(int, int);
	void display();
	int getm_x();
	int getm_y();
	int getm_width();
	int getm_height();
};

