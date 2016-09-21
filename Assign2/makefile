PROG = assign2
CC = g++
CPPFLAGS = -g -Wall
OBJS = Main.o List.o Item.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)
Main.o :
	$(CC) -c Main.cpp
List.o : List.hpp
	$(CC) -c List.cpp
Item.o : Item.hpp
	$(CC) -c Item.cpp
clean:
	rm -f core $(PROG)

