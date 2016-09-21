PROG = final
CC = g++
CPPFLAGS = -g -Wall
OBJS = Main.o Bridge.o Bridge2.o Engineering.o Game.o Holodeck.o Inventory.o Item.o Player.o Sickbay.o Space.o tenforward.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)
Main.o :
	$(CC) -c Main.cpp
Bridge.o : Bridge.hpp
	$(CC) -c Bridge.cpp
Bridge2.o : Bridge2.hpp
	$(CC) -c Bridge2.cpp
Engineering.o : Engineering.hpp
	$(CC) -c Engineering.cpp
Game.o : Game.hpp
	$(CC) -c Game.cpp
Holodeck.o : Holodeck.hpp
	$(CC) -c Holodeck.cpp
Inventory.o : Inventory.hpp
	$(CC) -c Inventory.cpp
Item.o : Item.hpp
	$(CC) -c Item.cpp
Player.o : Player.hpp
	$(CC) -c Player.cpp
Sickbay.o : Sickbay.hpp
	$(CC) -c Sickbay.cpp
Space.o : Space.hpp
	$(CC) -c Space.cpp
tenforward.o : tenforward.hpp
	$(CC) -c tenforward.cpp
clean:
	rm -f core $(PROG) $(OBJS)

