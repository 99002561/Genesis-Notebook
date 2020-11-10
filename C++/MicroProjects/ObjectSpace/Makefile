all.out : iobject.cpp wobject.cpp objectdb.cpp object-test.cpp objectdb-test.cpp
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
build: 
	g++ *.c* -o bin.out -lgtest -lgtest_main -lpthread
	./bin.out
run:
	./bin.out
clean:
	rm -rf *.out
