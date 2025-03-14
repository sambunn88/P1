CC = g++
CFLAGS = -g -Wall 
TARGET = P0

all: p0

p0: scanner.o testScanner.o main.o
	$(CC) $(CFLAGS) scanner.o testScanner.o main.o -o P1

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp -o main.o

scanner.o: scanner.cpp scanner.h 
	$(CC) $(CFLAGS) -c buildTree.cpp

testScanner.o: testScanner.cpp testScanner.h 
	$(CC) $(CFLAGS) -c traversals.cpp

clean:
	rm -rf *.o P0 

