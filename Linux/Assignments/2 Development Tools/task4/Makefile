tar: all out
LIB=src 
all:test.o 
	gcc test.o  -o all.out -L$(LIB) -lbitmask -lmyutils -lmystring

clean:
	rm -rf *.o *.out
	
out:
	LD_LIBRARY_PATH=src .\/all.out
