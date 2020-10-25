
# Make File(Comment int main in cpp)
all: all.out 
all.out : trip.o flighttrip.o tripdb.o trip-test.o tripdb-test.o
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
tripdb-test.o: tripdb-test.cpp trip.h flighttrip.h tripdb.h
	g++ $< -c
trip-test.o: trip-test.cpp trip.h flighttrip.h
	g++ $< -c
tripdb.o : tripdb.cpp tripdb.h flighttrip.h trip.h
	g++ $< -c
flighttrip.o : flighttrip.cpp flighttrip.h trip.h
	g++ $< -c    
trip.o : trip.cpp trip.h
	g++ $< -c
clean:
	rm -rf *.o *.out

# Ubuntu Commands

g++ trip-test.cpp trip.cpp flighttrip.cpp -c

g++ trip-test.o trip.o flighttrip.o  -lgtest -lgtest_main -lpthread -o out

g++ tripdb-test.cpp trip.cpp flighttrip.cpp tripdb.cpp -c

g++ tripdb-test.o trip.o flighttrip.o tripdb.o -lgtest -lgtest_main -lpthread -o out

./out
# Problem Statement

* In this problem you are expected to implement a solution for 
* flight trip management system with certain operations on 
* trip database
* A Trip can be associated with 
*    - data members like source city, destination city, 
       (distance metric - miles)
     - suitable constructor
*    - suitable abstract operations (pure virtual) like computeFare, computeTravelTime
* A Trip can be specialized as FlightTrip as follows
*    - additional data members like flight number, operator, 
       aerial distance between cities
*    - suitable constructor(s) for derived class
*    - override pure virtual functions computeFare, computeTravelTime. Consider that
*      fare calculation is INR 10 per mile and speed of 500 miles per hour for
*      travel time calculation.
* You must strongly exhibhit polymorphic design aspects with above classes
* Use upcasted pointers/references and dynamic binding to demonstrate runtime polymorphism
* Implement another class say FlightTripDatabase with collection of flight trips 
* using suitable data set (right STL container)
* Implement some operations on collection of flight trips as per following test calls
*    - addTrip("Bengaluru", "Mumbai", "6E123", 1000, "Indigo", 600)
*    - removeTrip("AI850")
*    - findTripById("SG302");
*    - countAll()
*    - computeMaxFare()
*    - computeMinTravelTime()
*    - countTripsByOperator("Indigo")
* Please provide optimal business logic in specified functions without any redundancy
* Core functions should be detached from console i/o and suitable for testable approach
* Please implement a simple test plan with suitable function calls in main 
* Provide solution in terms of multiple files with clean hierarchy of
* header, source files 
* Please add class diagram if time permits at end
* Follow the best practices of C++ & clean coding practices while implementing
* Please follow good coding style and meaningful names
* Your code shouldn't be crashed and no memory leaks/heap errors are expected from your code
* Your code will be validated against following code quality parameters
  * Code Style - googlestyle (clang-formar/AStyle)
  * Static ANalysis - cppcheck)
  * Heap Analysis - valgrind
* Please add class diagram at end
* Try to demonstrate RTTI features like dynamic_cast, typeid (this may not relate with 
* collection of objects or given test codelisted below, can be independent code) 
