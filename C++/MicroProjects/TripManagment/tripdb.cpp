#include "tripdb.h"
#include "flighttrip.h"

#include <list>
#include <iterator>

bool FlightTripDb::addTrip(std::string source, std::string destination, std::string flightNo, std::string a_operator, int a_distance)
{	
	l_trip.push_back(FlightTrip(source,destination,flightNo,a_operator,a_distance));
	return true;
}


bool FlightTripDb::removeTrip(std::string flightNumber)
{
	std::list<FlightTrip> :: iterator iter;

   	for(iter=l_trip.begin();iter!=l_trip.end();iter++)
    	{
        	if(iter->getFlightNumber()== flightNumber)
        	{
           	l_trip.erase(iter);
           	return true;
        	}
    	}
    	return false;
	
}

FlightTrip* FlightTripDb::findTripById(std::string trip_id)
{
	std::list<FlightTrip> :: iterator iter;

   	for(iter=l_trip.begin();iter!=l_trip.end();iter++)
    	{
        	if(iter->getFlightNumber()== trip_id)
        	{
           		return &(*iter);
        	}
    	}
    	return NULL;
}

int FlightTripDb::countAll()
{
	return l_trip.size();
}

double FlightTripDb::computeMaxFare()
{
	std::list<FlightTrip> :: iterator iter= l_trip.begin();
	double maxFair=iter->computeFare();

   	for(;iter!=l_trip.end();iter++)
    	{
        	 if(maxFair < iter->computeFare())
        	{
            		maxFair = iter->computeFare();
        	}	

    	}
	return maxFair;
}

double FlightTripDb::computeMinTravelTime()
{
	std::list<FlightTrip> :: iterator iter= l_trip.begin();
	double minTravelTime =iter->computeTravelTime();

   	for(;iter!=l_trip.end();iter++)
    	{
        	 if(minTravelTime > iter->computeTravelTime())
        	{
            		minTravelTime = iter->computeTravelTime();
        	}	

    	}
	return minTravelTime;
}

int FlightTripDb::countTripsByOperator(std::string a_operator)
{
	std::list<FlightTrip> :: iterator iter;
	int countTrips=0;

   	for(iter=l_trip.begin();iter!=l_trip.end();iter++)
    	{
        	if(iter->getOperator()== a_operator)
        	{
           		++countTrips;
        	}
    	}
    	return countTrips;
}

  	







