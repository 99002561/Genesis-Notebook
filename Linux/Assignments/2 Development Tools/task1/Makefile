target: all out clean
all:bitmask.o myutils.o test.o mystring.o 
	gcc bitmask.o myutils.o test.o mystring.o -o all.out

bitmask.o:
	gcc -c bitmask.c

myutils.o:
	gcc -c myutils.c

test.o:
	gcc -c test.c

mystring.o:
	gcc -c mystring.c

clean:
	rm -rf *.o *.out

out:
	.\/all.out
