CC = g++
FLAGS = -std=c++17 -Wall

all: obj

test:
	./obj

obj: allocator.o  main.o
	$(CC) $(FLAGS) -o obj allocator.o main.o
main.o: main.cpp allocator.hpp
	$(CC) $(FLAGS) -c main.cpp
allocator.o: allocator.cpp allocator.hpp
	$(CC) $(FLAGS) -c allocator.cpp
clean:
	rm -rf *.o obj
