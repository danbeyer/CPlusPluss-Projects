PROG = modD
CC = g++
CPPFLAGS = -g -Wall
OBJS = Main.o Grid.o Critter.o Ant.o Doodlebug.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)
Main.o :
	$(CC) -c Main.cpp
Grid.o : Grid.hpp
	$(CC) -c Grid.cpp
Critter.o : Critter.hpp
	$(CC) -c Critter.cpp
Ant.o : Ant.hpp
	$(CC) -c Ant.cpp
Doodlebug.o : Doodlebug.hpp
	$(CC) -c Doodlebug.cpp
clean:
	rm -f core $(PROG) $(OBJS)

