#ifndef __TRIP_H
#define __TRIP_H

#include<string>

const double mile_rateINR = 10.0;
const double fSpeedInHr = 500;

class Trip{
protected :
std::string m_scrCity;
std::string m_dstCity;
double distMiles;   // Unit Miles

public:
// Constructors
Trip();
Trip(std::string,std::string,double);

//Operations
virtual double computeFare() ;
virtual double computeTravelTime() ;

// Getters
 virtual std:: string getOrigin();
 virtual std:: string getDestination();
 virtual double getDistance();

}; // Class ending


#endif
