CC=g++
CFLAGS=-c -std=c++11

all: main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

main: main.o
	$(CC) main.o -o main

clean:
	rm -rf *.o main