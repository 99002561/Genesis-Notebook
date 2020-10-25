#include "pch.h"

TEST(mytime, ptest) {
	mytime x(12, 10, 5);
	mytime y(2, 50, 6);
	mytime res = x + y;
  EXPECT_EQ(15, res.h);
  EXPECT_EQ(0, res.m);
  EXPECT_EQ(11, res.s);

  EXPECT_TRUE(true);
}

TEST(mytime, stest) {
	mytime x(12, 10, 5);
	mytime y(2, 50, 6);
	mytime res = x - y;
	EXPECT_EQ(9, res.h);
	EXPECT_EQ(19, res.m);
	EXPECT_EQ(59, res.s);

	EXPECT_TRUE(true);
}
TEST(mytime, dptest) {
	mytime x(12, 0, 55);
	mytime res = x+6;
	EXPECT_EQ(12, res.h);
	EXPECT_EQ(1, res.m);
	EXPECT_EQ(1, res.s);
	EXPECT_TRUE(true);
}
TEST(mytime, dstest) {
	mytime x(12, 0, 0);
	mytime res = x -10;
	EXPECT_EQ(11, res.h);
	EXPECT_EQ(59, res.m);
	EXPECT_EQ(50, res.s);
	EXPECT_TRUE(true);
}
TEST(mytime, pretest) {
	mytime x(11, 59, 59);
	mytime res=++x;
	EXPECT_EQ(12, res.geth());
	EXPECT_EQ(0, res.getm());
	EXPECT_EQ(0, res.getsec());
	EXPECT_TRUE(true);
}