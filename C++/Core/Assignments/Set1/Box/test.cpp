#include "pch.cpp"
#include<gtest/gtest.h>

TEST(Box, DefaultConstructor)
{
	Box b;
	EXPECT_EQ(0, b.length());
	EXPECT_EQ(0, b.height());
	EXPECT_EQ(0, b.breadth());

}
TEST(Box, ParameterizedConstructor_1)
{
	Box b(30);
	EXPECT_EQ(30, b.length());
	EXPECT_EQ(30, b.height());
	EXPECT_EQ(30, b.breadth());

}
TEST(Box, ParameterizedConstructor_2)
{
	Box b(10, 20, 30);
	EXPECT_EQ(10, b.length());
	EXPECT_EQ(20, b.height());
	EXPECT_EQ(30, b.breadth());

}
TEST(Box, CopyConstructor)
{
	Box b1(10, 20, 30);
	Box b(b1);
	EXPECT_EQ(10, b.length());
	EXPECT_EQ(20, b.height());
	EXPECT_EQ(30, b.breadth());

}
TEST(Box, Volume)
{
	Box b(10, 20, 30);
	EXPECT_EQ(6000, b.volume());

}

