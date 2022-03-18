all: clear main.o PersonClass.o main do

PersonClass.o: classes/PersonClass.cpp
	g++ -c -std=c++11 -Wall -Werror classes/PersonClass.cpp -o classes/PersonClass.o -lm

main.o: main.cpp
	g++ -c -std=c++11 -Wall -Werror main.cpp -o main.o -lm

main: main.o classes/PersonClass.o
	g++ main.o classes/PersonClass.o -o main

do: main
	./main

clear:
	clear