PROG = assign3
CC = g++
CPPFLAGS = -g -Wall
OBJS = Main.o Creature.o BabaYaga.o Barbarian.o BlueMen.o HarryPotter.o HelperFunctions.o Medusa.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)
Main.o :
	$(CC) -c Main.cpp
Creature.o : Creature.hpp
	$(CC) -c Creature.cpp
BabaYaga.o : BabaYaga.hpp
	$(CC) -c BabaYaga.cpp
Barbarian.o : Barbarian.hpp
	$(CC) -c Barbarian.cpp
BlueMen.o : BlueMen.hpp
	$(CC) -c BlueMen.cpp
HarryPotter.o : HarryPotter.hpp
	$(CC) -c HarryPotter.cpp
HelperFunctions.o : HelperFunctions.hpp
	$(CC) -c HelperFunctions.cpp
Medusa.o : Medusa.hpp
	$(CC) -c Medusa.cpp
clean:
	rm -f core $(PROG) $(OBJS)

