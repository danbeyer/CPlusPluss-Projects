PROG = mod2
CC = g++
CPPFLAGS = -g -Wall
OBJS = Main.o Stack.o Queue.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)
Main.o :
	$(CC) -c Main.cpp
Stack.o : Stack.hpp
	$(CC) -c Stack.cpp
Queue.o : Queue.hpp
	$(CC) -c Queue.cpp
clean:
	rm -f core $(PROG) $(OBJS)

