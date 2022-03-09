all: clear main.o main do clean

main.o: main.cpp
	g++ -c -Wall -Werror main.cpp -o main.o

main: main.o
	g++ main.o -o main -lm

do: main
	./main

clean:
	rm main
	rm main.o

clear:
	clear