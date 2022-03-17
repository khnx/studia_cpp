all: clear main.o main do clean

main.o: main.cpp
	g++ -c -std=c++11 -Wall -Werror main.cpp -o main.o -lm

main: main.o
	g++ main.o -o main

do: main
	./main
	
clean:
	rm main
	rm main.o

clear:
	clear