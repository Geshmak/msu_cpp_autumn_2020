CC = g++
FLAGS = -std=c++17 -Wall

all: prog

test:
	./prog

prog: progb.o  progm.o
	$(CC) $(FLAGS) -o prog progb.o progm.o
progm.o: progm.cpp progh.hpp
	$(CC) $(FLAGS) -c progm.cpp
progb.o: progb.cpp progh.hpp
	$(CC) $(FLAGS) -c progb.cpp
clean:
	rm -rf *.o prog
