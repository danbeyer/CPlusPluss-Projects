PROG = mod3
CC = g++
CPPFLAGS = -g -Wall
OBJS = Main.o State.o HelperFunctions.o 

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)
Main.o :
	$(CC) -c Main.cpp
State.o : State.hpp
	$(CC) -c State.cpp
HelperFunctions.o : HelperFunctions.hpp
	$(CC) -c HelperFunctions.cpp
clean:
	rm -f core $(PROG) $(OBJS)

