
CC=g++
CFLAGS=-c -g -Wall

SOURCES = Ant.cpp Grid.cpp Main.cpp
HEADERS = Ant.hpp Grid.hpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE = ant

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
