all: clear main.o main do clean

main.o: main.cpp
	g++ -c -Wall -Werror main.cpp -o main.o

main: main.o
	g++ -Wall -Werror main.o -o main

do: main
	./main

clean:
	rm main
	rm main.o

clear:
	clear