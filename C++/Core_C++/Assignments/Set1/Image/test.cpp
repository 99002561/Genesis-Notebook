#include "pch.h"

TEST(Image, DefaultConstructor)
{
	Image i;
	EXPECT_EQ(0, i.getm_x());
	EXPECT_EQ(0, i.getm_y());
	EXPECT_EQ(0, i.getm_width());
	EXPECT_EQ(0, i.getm_height());

}
TEST(Image, ParameterizedConstructor)
{
	Image i(120, 120, 250, 150);
	EXPECT_EQ(120, i.getm_x());
	EXPECT_EQ(120, i.getm_y());
	EXPECT_EQ(250, i.getm_width());
	EXPECT_EQ(150, i.getm_height());

}
TEST(Image, CopyConstructor)
{
	Image i(110, 150, 250, 200);
	Image j(i);
	EXPECT_EQ(110, j.getm_x());
	EXPECT_EQ(150, j.getm_y());
	EXPECT_EQ(250, j.getm_width());
	EXPECT_EQ(200, j.getm_height());

}
TEST(Image, Move)
{
	Image j(100, 100, 250, 200);
	j.move(50, 70);
	EXPECT_EQ(50, j.getm_x());
	EXPECT_EQ(70, j.getm_y());
	EXPECT_EQ(250, j.getm_width());
	EXPECT_EQ(200, j.getm_height());

}
TEST(Image, Scale)
{
	Image j(100, 100, 250, 200);
	j.scale(2);
	EXPECT_EQ(100, j.getm_x());
	EXPECT_EQ(100, j.getm_y());
	EXPECT_EQ(500, j.getm_width());
	EXPECT_EQ(400, j.getm_height());

}
TEST(Image, Resize)
{
	Image j(100, 100, 250, 200);
	j.resize(50, 100);
	EXPECT_EQ(100, j.getm_x());
	EXPECT_EQ(100, j.getm_y());
	EXPECT_EQ(300, j.getm_width());
	EXPECT_EQ(300, j.getm_height());

}