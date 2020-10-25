
#include "trip.h"
#include "flighttrip.h"
#include "tripdb.h"
#include <gtest/gtest.h>
namespace {

class FlightTripDbTest : public ::testing::Test {

protected:
  void SetUp() { 
    trips.addTrip("Hyderabad", "Pune", "6E500", "Indigo", 350);
    trips.addTrip("Bengaluru", "Pune", "6E501","Indigo", 500);
    trips.addTrip("Hyderabad", "Chennai", "AI850","AirIndia", 400);
    trips.addTrip("Mumbai", "Bengaluru","SG301",  "Spicejet", 600);
    trips.addTrip("Bengaluru", "Delhi", "SG302","Spicejet", 1200);
    trips.addTrip("Pune", "Bengaluru","AI900",  "AirIndia", 550);
  }
  void TearDown() {}
  FlightTripDb trips;
};

TEST_F(FlightTripDbTest, AddTripTest) {
  trips.addTrip("Chennai","Delhi", "SG304","Spicejet", 1300);
  EXPECT_NE((Trip*)NULL, trips.findTripById("SG304"));
  EXPECT_EQ(7, trips.countAll());
}
TEST_F(FlightTripDbTest, RemoveTripTest) {
  trips.removeTrip("6E501");
  EXPECT_EQ(NULL, trips.findTripById("6E501"));
  EXPECT_EQ(5, trips.countAll());
}
TEST_F(FlightTripDbTest, CountTest) {             //Just After Setup
  EXPECT_EQ(6, trips.countAll());
}
TEST_F(FlightTripDbTest, CountByOperatorTest) {  //Just After Setup
  int count = trips.countTripsByOperator("Indigo");
  EXPECT_EQ(2, count);
}
TEST_F(FlightTripDbTest, MaxFareTest) {           //Just After Setup
  double maxFare = trips.computeMaxFare();
  double minTime = trips.computeMinTravelTime();
  EXPECT_EQ(12000, maxFare);         //For trip with distance of 1200 miles
  EXPECT_EQ(42, minTime);            //For trip with distance of 350 miles   
}
TEST_F(FlightTripDbTest, AnotherTest) {         //Just After Setup
  trips.addTrip("Chennai","Delhi","SG308", "Spicejet", 1300);
  trips.addTrip("Chennai","Bengaluru", "AI848", "AirIndia", 200);
  int count = trips.countTripsByOperator("Spicejet");
  double maxFare = trips.computeMaxFare();
  double minTime = trips.computeMinTravelTime();
  EXPECT_EQ(8, trips.countAll());  
  EXPECT_EQ(3, count);  
  EXPECT_EQ(13000, maxFare);  
  EXPECT_EQ(24, minTime);  
}
} // namespace

/*int main(int argc,char **argv)
{
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}*/
