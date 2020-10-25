

#ifndef __FlightTRIP_H
#define __FlightTRIP_H

#include<string>
#include"trip.h"


class FlightTrip: public Trip{
 protected:
 std::string m_FID;
 std::string m_fOperator;

 public:
 // Constructor
 FlightTrip();
 FlightTrip(std::string ,std::string,std::string ,std::string,double);

//Operations
 double computeFare() ;
 double computeTravelTime() ;

//getters
 std:: string getOperator();
 std::string getFlightNumber();

};

#endif
