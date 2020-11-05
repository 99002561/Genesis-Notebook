#include"flighttrip.h"


 FlightTrip:: FlightTrip():
 Trip(){
     m_FID="";
     m_fOperator="" ;
  }

FlightTrip:: FlightTrip(std::string scr ,std::string dst,std::string id,std::string opr ,double dis):
Trip(scr,dst,dis) {
     m_FID=id;
     m_fOperator=opr;
 }

//Operations
 double FlightTrip:: computeFare()  {
 return (distMiles * mile_rateINR);
 }

 double FlightTrip:: computeTravelTime() {
  double temp = static_cast<double> (distMiles) /fSpeedInHr;
  return temp * 60;
 }

//getters
std:: string FlightTrip:: getOperator(){
  return m_fOperator;
}
std:: string FlightTrip:: getFlightNumber(){
    return m_FID;
}
