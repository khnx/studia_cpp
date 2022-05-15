all: clear ComplexN.o cVectors.o main.o main invoke

clear:
	clear

ComplexN.o: classes/ComplexN.cpp
	g++ -std=c++11 -Werror -Wall -O3 -c classes/ComplexN.cpp -o obj/ComplexN.o

cVectors.o: classes/cVectors.cpp
	g++ -std=c++11 -Werror -Wall -O3 -c classes/cVectors.cpp -o obj/cVectors.o

main.o: main.cpp
	g++ -std=c++11 -Werror -Wall -O3 -c main.cpp -o obj/main.o

main: obj/ComplexN.o obj/cVectors.o obj/main.o
	g++ obj/ComplexN.o obj/cVectors.o obj/main.o -o main

invoke: main
	./main