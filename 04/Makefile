CC = g++
FLAGS = -std=c++17 -Wall

all: obj

test:
	./obj

obj: Bigint.o  main.o
	$(CC) $(FLAGS) -o obj Bigint.o main.o
main.o: main.cpp Bigint.hpp
	$(CC) $(FLAGS) -c main.cpp
Bigint.o: Bigint.cpp Bigint.hpp
	$(CC) $(FLAGS) -c Bigint.cpp
clean:
	rm -rf *.o obj
