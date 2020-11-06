#include "iobject.h"
#include "wobject.h"
#include "objectdb.h"
#include <gtest/gtest.h>
namespace {

class ObjectDbTest : public ::testing::Test {

protected:
  void SetUp() { 
    objects.addObject(3,4,    100);     //5
    objects.addObject(-4,3,   150);     //5
    objects.addObject(-8,-15, 110);     //17
    objects.addObject(-12,5,  180);     //13
    objects.addObject(30,40,  200);     //50
    objects.addObject(20,15,  140);     //25
    objects.addObject(8,6,    120);     //10
    objects.addObject(-15,20, 160);     //25
    objects.addObject(-4,-3,  190);     //5
    objects.addObject(-6,8,   210);     //10
  }
  void TearDown() {}
  ObjectDb objects;
};

TEST_F(ObjectDbTest, AddObjectTest) {
  objects.addObject(6,8, 210);
  EXPECT_EQ(11, objects.countAll());
}
TEST_F(ObjectDbTest, RemoveObjectTest) {
  objects.removeObject(8,6);
  EXPECT_EQ(9, objects.countAll());
}
TEST_F(ObjectDbTest, CountAllTest) {             
  EXPECT_EQ(10, objects.countAll());
}
TEST_F(ObjectDbTest, ComputationalTest) {  
  int maxDistance  = objects.findMaxDistanceFromOrigin();
  int count = objects.countObjectsByQuadrant(Q2);
  double wmin = objects.findMinWeight();
  EXPECT_EQ(50, maxDistance);
  EXPECT_EQ(4, count);
  EXPECT_EQ(100, wmin);
}

TEST_F(ObjectDbTest, CountByColorTest) {

  int countFive = objects.countObjectsOnCircleBoundary(5);
  int countTen  = objects.countObjectsOnCircleBoundary(10);
  EXPECT_EQ(3, countFive);
  EXPECT_EQ(2, countTen);
}
TEST_F(ObjectDbTest, AnotherDbTest) {
  objects.addObject(15,12,80);
  objects.addObject(10,5, 270);
  EXPECT_EQ(12, objects.countAll());
  EXPECT_EQ(6,  objects.countObjectsByQuadrant(Q1));
  EXPECT_EQ(80, objects.findMinWeight());
}

} // namespace

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}