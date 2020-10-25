CC = g++
FLAGS = -std=c++17 -Wall

all: obj

test:
	./obj

obj: Matrix.o  main.o
	$(CC) $(FLAGS) -o obj Matrix.o main.o
main.o: main.cpp Matrix.hpp
	$(CC) $(FLAGS) -c main.cpp
Matrix.o: Matrix.cpp Matrix.hpp
	$(CC) $(FLAGS) -c Matrix.cpp
clean:
	rm -rf *.o obj
