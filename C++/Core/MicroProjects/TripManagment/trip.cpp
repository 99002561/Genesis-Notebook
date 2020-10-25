#include "trip.h"

//Construtor
Trip::Trip(): m_scrCity(""),m_dstCity(""),distMiles(0.0){}
Trip::Trip(std::string scr,std::string dst,double dis):
 m_scrCity(scr),
 m_dstCity(dst),
 distMiles(dis){}


 // Getters

 //Operations
 double Trip:: computeFare()  {
 return (distMiles * mile_rateINR);
 }

 double Trip:: computeTravelTime()  {
 double temp = static_cast<double> (distMiles) /fSpeedInHr;
 return temp * 60;
 }


std:: string  Trip::getOrigin(){
return m_scrCity;
}
std:: string Trip::getDestination(){
return m_dstCity;
}
double Trip::getDistance(){
return distMiles;
}
