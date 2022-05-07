all: clear Nanobot.o main.o main invoke

clear:
	clear

main.o: main.cpp
	g++ -std=c++11 -Werror -Wall -c -O3 main.cpp -o main.o

Nanobot.o: class/Nanobot.cpp
	g++ -std=c++11 -Werror -Wall -c -O3 class/Nanobot.cpp -o class/Nanobot.o

main: class/Nanobot.o main.o
	g++ class/Nanobot.o main.o -o main

invoke: main
	./main