LIB=src
all:test.o
	gcc test.o -o all.out -static -L$(LIB) -lbitmask -lmyutils -lmystring

test.o:
	gcc -c test.c

clean:
	rm -rf *.o *.out
