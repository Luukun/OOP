CC=g++
CFLAGS=-c

all: main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Record.o: Record.cpp
	$(CC) $(CFLAGS) Record.cpp

main: main.o Record.o
	$(CC) main.o Record.o -o main

clean:
	rm -rf *.o main