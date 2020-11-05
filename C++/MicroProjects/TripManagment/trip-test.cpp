#include "trip.h"
#include "flighttrip.h"
#include <gtest/gtest.h>
namespace {

class TripTest : public ::testing::Test {

protected:
  void SetUp() { // override {
    ptr = new FlightTrip("Mumbai", "Delhi", "6E123", "Indigo", 800);
  }
  void TearDown() {
    delete ptr;
  }
  Trip *ptr;
};

TEST_F(TripTest, DefaultConstructor) {
  FlightTrip ft;
  EXPECT_EQ(0, ft.getFlightNumber().length());
  EXPECT_EQ(0, ft.getOrigin().length());
  EXPECT_EQ(0, ft.getDestination().length());
  EXPECT_EQ(0, ft.getOperator().length());
  EXPECT_EQ(0, ft.getDistance());
}
TEST_F(TripTest, ParameterizedConstructor) {
  FlightTrip *fptr = dynamic_cast<FlightTrip*>(ptr);
  EXPECT_STREQ("Mumbai", fptr->getOrigin().c_str());
  EXPECT_STREQ("Delhi", fptr->getDestination().c_str());
  EXPECT_STREQ("6E123", fptr->getFlightNumber().c_str());
  EXPECT_STREQ("Indigo", fptr->getOperator().c_str());
  EXPECT_EQ(800, fptr->getDistance());
}
TEST_F(TripTest, ComputationTest) {
  EXPECT_EQ(8000, ptr->computeFare());      //800 * 10, INR 10 for each mile
  EXPECT_EQ(96, ptr->computeTravelTime());  //96 mins, if speed in 500 miles per hr
}
TEST_F(TripTest, AnotherTest) {
  FlightTrip ft("Bengaluru", "Chennai", "SG401", "SpiceJet", 200);
  Trip *pt = &ft;
  EXPECT_STREQ("Bengaluru", ft.getOrigin().c_str());
  EXPECT_STREQ("Chennai", ft.getDestination().c_str());
  EXPECT_STREQ("SG401", ft.getFlightNumber().c_str());
  EXPECT_STREQ("SpiceJet", ft.getOperator().c_str());
  EXPECT_EQ(200, ft.getDistance());
  EXPECT_EQ(2000, pt->computeFare());        //200 * 10 = 2000
  EXPECT_EQ(24, pt->computeTravelTime());    //24 mins, if speed is 500 miles per hr
}
} // namespace

/*int main(int argc, char **argv) 
        {
            testing::InitGoogleTest(&argc, argv);
            return RUN_ALL_TESTS();
        }*/