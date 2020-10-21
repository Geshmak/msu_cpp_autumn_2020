CC = g++
FLAGS = -std=c++17 -Wall

all: obj

test:
	./obj

obj: parcer.o  main.o
	$(CC) $(FLAGS) -o obj parcer.o main.o
main.o: main.cpp parcer.hpp
	$(CC) $(FLAGS) -c main.cpp
parcer.o: parcer.cpp parcer.hpp
	$(CC) $(FLAGS) -c parcer.cpp
clean:
	rm -rf *.o obj
