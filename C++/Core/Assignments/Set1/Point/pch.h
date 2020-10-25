//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"
#include<string>
enum quadrant { q1, q2, q3, q4 };
class Point {
	int x, y; // ideally to be of string type
	std::string customerName;
	double balance;

public:
	Point();
	Point(int, int);
	Point(const Point&);
	bool isorigin();
	bool isonXaxis();
	bool isonYaxis();
	int distancefromorigin();
	quadrant Quadrant();
		void display();
};
