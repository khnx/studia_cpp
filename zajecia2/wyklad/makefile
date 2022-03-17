all: clear main.o PersonClass.o main do clean

PersonClass.o: classes/PersonClass.cpp
	g++ -c -std=c++11 -Wall -Werror classes/PersonClass.cpp -o PersonClass.o -lm

main.o: main.cpp
	g++ -c -std=c++11 -Wall -Werror main.cpp -o main.o -lm

main: main.o classes/PersonClass.o
	g++ main.o classes/PersonClass.o -o main

do: main
	./main
	
clean:
	rm main
	rm main.o

clear:
	clear