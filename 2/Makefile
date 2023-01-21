CC=g++
CFLAGS=-c

all: main
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

String.o: String.cpp
	$(CC) $(CFLAGS) String.cpp

main: main.o String.o
	$(CC) main.o String.o -o main

clean:
	rm -rf *.o main