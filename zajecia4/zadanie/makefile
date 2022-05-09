all: clear main.o main invoke

clear:
	clear

main.o: main.cpp
	g++ -std=c++11 -Werror -Wall -c -O3 main.cpp -o main.o

main: main.o
	g++ main.o -o main

invoke: main
	./main