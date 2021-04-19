CC=g++

all: test

test: test.o allocator.o
	$(CC) -o test test.o allocator.o

test.o: test.cpp allocator.h
	$(CC) -c test.cpp

allocator.o: allocator.cpp allocator.h
	$(CC) -c allocator.cpp

clean:
	rm -rf test *.o