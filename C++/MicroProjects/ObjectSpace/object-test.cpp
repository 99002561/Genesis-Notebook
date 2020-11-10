#include "iobject.h"
#include "wobject.h"
#include <gtest/gtest.h>
namespace {

class ObjectTest : public ::testing::Test {

protected:
  void SetUp() { // override {
    ptr = new WObject(20,15,100); 
  }
  void TearDown() {
    delete ptr;
  }
  IObject *ptr;  
};

TEST_F(ObjectTest, DefaultConstructor) {
  WObject b1;
  EXPECT_EQ(0, b1.getX());
  EXPECT_EQ(0, b1.getY());
  EXPECT_EQ(0, b1.weight());
}
TEST_F(ObjectTest, ParameterizedConstructor) {
  WObject w1(-12, 5, 150); 
  EXPECT_EQ(-12, w1.getX());
  EXPECT_EQ(5, w1.getY());
  EXPECT_EQ(13, w1.distanceFromOrigin());
  EXPECT_EQ(Q2, w1.getQuadrant());
  EXPECT_EQ(150, w1.weight());
}
TEST_F(ObjectTest, ComputationTest) {
  EXPECT_EQ(25, ptr->distanceFromOrigin());
  EXPECT_EQ(Q1, ptr->getQuadrant());
}
TEST_F(ObjectTest, AnotherTest) {
  WObject w2(15,-8,180);  
  IObject *iptr = &w2;
  EXPECT_EQ(15, w2.getX());
  EXPECT_EQ(-8, w2.getY());
  EXPECT_EQ(180, w2.weight());
  EXPECT_EQ(17, iptr->distanceFromOrigin());
  EXPECT_EQ(Q4, iptr->getQuadrant());  
}
} // namespace

/*
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}*/