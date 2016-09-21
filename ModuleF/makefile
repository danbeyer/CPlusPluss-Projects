PROG = modF
CC = g++
CPPFLAGS = -g -Wall
OBJS = Main.o State.o HelperFunctions.o Queue.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)
Main.o :
	$(CC) -c Main.cpp
State.o : State.hpp
	$(CC) -c State.cpp
Queue.o : Queue.hpp
	$(CC) -c Queue.cpp
HelperFunctions.o : HelperFunctions.hpp
	$(CC) -c HelperFunctions.cpp
clean:
	rm -f core $(PROG) $(OBJS)

