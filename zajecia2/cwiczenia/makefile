all: clear main.o Tv.o main do

Tv.o: classes/Tv.cpp
	g++ -c -std=c++11 -Wall -Werror classes/Tv.cpp -o classes/Tv.o -lm

main.o: main.cpp
	g++ -c -std=c++11 -Wall -Werror main.cpp -o main.o -lm

main: main.o classes/Tv.o
	g++ main.o classes/Tv.o -o main

do: main
	./main

clear:
	clear