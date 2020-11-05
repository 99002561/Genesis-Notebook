#ifndef TRIPDB_H_INCLUDED
#define TRIPDB_H_INCLUDED
#include "trip.h"
#include "flighttrip.h"
#include <list>

class FlightTripDb
{
	std::list<FlightTrip> l_trip;
  public:
 	bool addTrip(std::string, std::string, std::string, std::string, int);
    	bool removeTrip(std::string);
    	FlightTrip* findTripById(std::string);
    	int countAll();
    	double computeMaxFare();
    	double computeMinTravelTime();
    	int countTripsByOperator(std::string);
  	
};

#endif
