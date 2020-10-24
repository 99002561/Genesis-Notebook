#include "pch.h"

TEST(distance, ptest) {
	distance p1(10, 5);
	distance p2(12, 6);
	distance res = p1 + p2;
	EXPECT_EQ(22, res.get_feet());
	EXPECT_EQ(11, res.get_inch());
  EXPECT_TRUE(true);
}

TEST(distance, stest) {
	distance p1(13, 7);
	distance p2(12, 6);
	distance res = p1 - p2;
	EXPECT_EQ(-1, res.get_feet());
	EXPECT_EQ(-1, res.get_inch());
	EXPECT_TRUE(true);
}
TEST(distance, posttest) {
	distance p1(1, 5);
	distance res = p1++;
	EXPECT_EQ(1, res.get_feet());
	EXPECT_EQ(5, res.get_inch());
	EXPECT_TRUE(true);
}
TEST(distance, pretest) {
	distance p1(10,11);
	distance res =++p1;
	EXPECT_EQ(11, res.get_feet());
	EXPECT_EQ(0, res.get_inch());
	EXPECT_TRUE(true);
}