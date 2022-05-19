BINARY=bin
CODEDIRS=. lib
INCDIRS=. ./include/

CC=g++
OPT=-O0
DEPFLAGS=-MP -MD
CFLAGS=-Wall -Werror -g $(foreach D,$(INCDIRS),-I$(D)) $(OPT) $(DEPFLAGS)

CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.cpp))

OBJECTS=$(patsubst %.cpp,%.o,$(CFILES))
DEPFILES=$(patsubst %.cpp,%.d,$(CFILES))

all:$(BINARY) invoke

$(BINARY):$(OBJECTS)
	$(CC) -o $@ $^

%.o:%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BINARY) $(OBJECTS) $(DEPFILES)

invoke: bin
	./bin