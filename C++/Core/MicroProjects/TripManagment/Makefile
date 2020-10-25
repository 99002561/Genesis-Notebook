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
