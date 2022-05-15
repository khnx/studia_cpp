all: clear main.o main invoke

clear:
	clear

Zespolone.o: class/Zespolone.cpp
	g++ -std=c++11 -Werror -Wall -c -O3 class/Zespolone.cpp -o Zespolone.o

main.o: main.cpp
	g++ -std=c++11 -Werror -Wall -c -O3 main.cpp -o main.o

main: class/Zespolone.o main.o
	g++ -std=c++11 -Werror -Wall -O3 class/Zespolone.o main.o -o main

invoke: main
	./main