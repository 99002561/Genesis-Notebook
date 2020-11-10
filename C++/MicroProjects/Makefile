all: object-test.out objectdb-test.out
object-test.out: object-test.cpp wobject.cpp iobject.cpp 
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
objectdb-test.out: objectdb-test.cpp objectdb.cpp wobject.cpp iobject.cpp 
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread


