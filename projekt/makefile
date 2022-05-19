all: clear ComplexN.o cPoint.o cVector.o main.o main invoke

clear:
	clear

ComplexN.o: classes/ComplexN.cpp
	g++ -std=c++11 -Werror -Wall -O3 -c classes/ComplexN.cpp -o obj/ComplexN.o

cVector.o: classes/cVector.cpp
	g++ -std=c++11 -Werror -Wall -O3 -c classes/cVector.cpp -o obj/cVector.o

cPoint.o: classes/cPoint.cpp
	g++ -std=c++11 -Werror -Wall -O3 -c classes/cPoint.cpp -o obj/cPoint.o

main.o: main.cpp
	g++ -std=c++11 -Werror -Wall -O3 -c main.cpp -o obj/main.o

main: obj/ComplexN.o obj/cVector.o obj/main.o
	g++ obj/ComplexN.o obj/cPoint.o obj/cVector.o obj/main.o -o main

invoke: main
	./main