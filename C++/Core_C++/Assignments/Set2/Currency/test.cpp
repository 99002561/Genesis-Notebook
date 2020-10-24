#include "pch.h"

#include<iostream>
#include<gtest/gtest.h>
using namespace std;


TEST(Complex_values, DefaultConstructor)
{
	Currency c;
	EXPECT_EQ(0, c.get_mrupees());
	EXPECT_EQ(0, c.get_mpaise());
}
TEST(Complex_values, ParameterizedConstructor)
{
	Currency c(20, 90);
	EXPECT_EQ(20, c.get_mrupees());
	EXPECT_EQ(90, c.get_mpaise());
}
TEST(Complex_values, CopyConstructor)
{
	Currency c(50, 80);
	Currency c1(c);
	EXPECT_EQ(50, c1.get_mrupees());
	EXPECT_EQ(80, c1.get_mpaise());
}
TEST(Complex_values, addition_overloading)
{
	Currency c1(20, 90), c2(50, 60);
	EXPECT_EQ(71, (c1 + c2).get_mrupees());
	EXPECT_EQ(50, (c1 + c2).get_mpaise());
}
TEST(Complex_values, subtraction_overloading)
{
	Currency c1(50, 90), c2(20, 60);
	EXPECT_EQ(30, (c1 - c2).get_mrupees());
	EXPECT_EQ(30, (c1 - c2).get_mpaise());
}
TEST(Complex_values, inc_overloading)
{
	Currency c1(20, 99);
	EXPECT_EQ(21, (c1 + 5).get_mrupees());
	EXPECT_EQ(4, (c1 + 5).get_mpaise());
}
TEST(Complex_values, dec_overloading)
{
	Currency c1(20, 14);
	EXPECT_EQ(20, (c1 - 1).get_mrupees());
	EXPECT_EQ(13, (c1 - 1).get_mpaise());
}

TEST(Complex_values, preinc_overloading)
{
	Currency c(25, 99);
	Currency res;
	res = ++c;
	EXPECT_EQ(26, res.get_mrupees());
	EXPECT_EQ(0, res.get_mpaise());
}
TEST(Complex_values, postinc_overloading)
{
	Currency c(25, 30);
	Currency res;
	res = c++;
	EXPECT_EQ(25, res.get_mrupees());
	EXPECT_EQ(30, res.get_mpaise());
}
TEST(Complex_values, equality_overloading)
{
	Currency c1(20, 35), c2(20, 35);
	EXPECT_EQ(0, c1 == c2); //equal

	Currency c3(7, 9), c4(3, 10);//unequal
	EXPECT_EQ(1, c3 == c4);
}
TEST(Complex_values, greaterop_overloading)
{
	Currency c1(5, 3), c2(2, 90);
	EXPECT_EQ(0, c1 > c2); //greater

	Currency c3(1, 10), c4(3, 90);//not greater
	EXPECT_EQ(1, c3 > c4);
}
TEST(Complex_values, lesserop_overloading)
{
	Currency c1(2, 3), c2(9, 70);
	EXPECT_EQ(0, c1 < c2); //lesser

	Currency c3(7, 9), c4(3, 10);//not lesser
	EXPECT_EQ(1, c3 < c4);
}
