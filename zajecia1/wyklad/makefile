all: clear main.o main invoke

clear:
	clear

main.o: main.cpp
	g++ -std=c++11 -Wall -Werror -O3 -c main.cpp -o main.O3

main: main.o
	g++ main.o -o main

invoke: main
	./main