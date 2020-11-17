CC = g++
FLAGS = -std=c++17 -Wall

all: obj

test:
	./obj

obj: format.o  main.o
	$(CC) $(FLAGS) -o obj format.o main.o
main.o: main.cpp format.hpp
	$(CC) $(FLAGS) -c main.cpp
Bigint.o: format.cpp format.hpp
	$(CC) $(FLAGS) -c format.cpp
clean:
	rm -rf *.o obj
