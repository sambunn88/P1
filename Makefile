CC = g++
CFLAGS = -g -Wall 
TARGET = P1

all: p1

p1: scanner.o testScanner.o main.o
	$(CC) $(CFLAGS) scanner.o testScanner.o main.o -o P1

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp -o main.o

scanner.o: scanner.cpp scanner.h 
	$(CC) $(CFLAGS) -c scanner.cpp

testScanner.o: testScanner.cpp testScanner.h 
	$(CC) $(CFLAGS) -c testScanner.cpp

clean:
	rm -rf *.o P1  

