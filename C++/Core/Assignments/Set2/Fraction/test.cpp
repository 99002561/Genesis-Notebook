
#include "pch.h"
#include<iostream>
#include<gtest/gtest.h>
using namespace std;


TEST(Fraction_values, DefaultConstructor)
{
	Fraction f;
	EXPECT_EQ(0, f.get_mnumerator());
	EXPECT_EQ(0, f.get_mdenominator());
}
TEST(Fraction_values, ParameterizedConstructor)
{
	Fraction f(3,4);
	EXPECT_EQ(3, f.get_mnumerator());
	EXPECT_EQ(4, f.get_mdenominator());
}
TEST(Fraction_values, CopyConstructor)
{
	Fraction f(3, 4);
	Fraction f1(f);
	EXPECT_EQ(3, f1.get_mnumerator());
	EXPECT_EQ(4, f1.get_mdenominator());
}
TEST(Fraction_values, addition_overloading)
{
	Fraction f1(2, 3), f2(4, 5);
	EXPECT_EQ(22, (f1 + f2).get_mnumerator());
	EXPECT_EQ(15, (f1 + f2).get_mdenominator());
}
TEST(Fraction_values, substraction_overloading)
{
	Fraction f1(2, 3), f2(4, 5);
	EXPECT_EQ(-2, (f1 - f2).get_mnumerator());
	EXPECT_EQ(15, (f1 - f2).get_mdenominator());
}
TEST(Fraction_values, multiplication_overloading)
{
	Fraction f1(2, 3), f2(4, 5);
	EXPECT_EQ(8, (f1 * f2).get_mnumerator());
	EXPECT_EQ(15, (f1 * f2).get_mdenominator());
}
TEST(Fraction_values, inc_overloading)
{
	Fraction f1(2, 3);
	EXPECT_EQ(17, (f1 + 5).get_mnumerator());
	EXPECT_EQ(3, (f1 + 5).get_mdenominator());
}
TEST(Fraction_values, dec_overloading)
{
	Fraction f1(2, 3);
	EXPECT_EQ(-13, (f1 - 5).get_mnumerator());
	EXPECT_EQ(3, (f1 - 5).get_mdenominator());
}

TEST(Fraction_values, equality_overloading)
{
	Fraction f1(2, 3), f2(2, 3);
	EXPECT_EQ(0, f1 == f2); //equal

	Fraction f3(7, 9), f4(3, 10);//unequal
	EXPECT_EQ(1, f3 == f4);
}
TEST(Fraction_values, greaterop_overloading)
{
	Fraction f1(5, 6), f2(11, 45);
	EXPECT_EQ(0, f1 > f2); //greater

	Fraction f3(2, 3), f4(4, 5);//notgreater
	EXPECT_EQ(1, f3 > f4);
}
TEST(Fraction_values, lesserop_overloading)
{
	Fraction f1(11, 45), f2(5, 6);
	EXPECT_EQ(0, f1 < f2); //greater

	Fraction f3(4, 5), f4(2, 3);//notgreater
	EXPECT_EQ(1, f3 < f4);
}
/*
TEST(Fraction_values, simplify)
{
	Fraction f1(24,32);
	EXPECT_EQ(3, (f1.simplify()).get_mnumerator()); 
	EXPECT_EQ(4, (f1.simplify()).get_mdenominator());
}*/