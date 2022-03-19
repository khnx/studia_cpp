all: clear main.o Mixer.o main invoke

clear:
	clear

main.o: main.cpp
	g++ -std=c++11 -Wall -Werror -O3 -c main.cpp -o main.o

Mixer.o: classes/Mixer.cpp
	g++ -std=c++11 -Wall -Werror -O3 -c classes/Mixer.cpp -o classes/Mixer.o

main: main.o classes/Mixer.o
	g++ main.o classes/Mixer.o -o main

invoke: main
	./main