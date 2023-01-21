CC=g++
CFLAGS=-c

all: main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Libs.o: Libs.cpp
	$(CC) $(CFLAGS) Libs.cpp

main: main.o Libs.o
	$(CC) main.o Libs.o -o main

clean:
	rm -rf *.o main