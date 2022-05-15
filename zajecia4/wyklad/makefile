all: clear Szablon.o main.o main invoke

clear:
	clear

Szablon.o: class/Szablon.cpp
	g++ -std=c++11 -Werror -Wall -c -O3 class/Szablon.cpp -o class/Szablon.o

main.o: main.cpp
	g++ -std=c++11 -Werror -Wall -c -O3 main.cpp -o main.o

main: class/Szablon.o main.o
	g++ class/Szablon.o main.o -o main

invoke: main
	./main