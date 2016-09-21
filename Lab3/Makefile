
CC=g++
CFLAGS=-c -g -Wall

SOURCES = Ant.cpp Critter.cpp Grid.cpp Main.cpp
HEADERS = Ant.hpp Critter.hpp Grid.hpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE = critter

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f ${OBJECTS] ${EXECUTABLE]
