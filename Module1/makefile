PROG = mod1
CC = g++
CPPFLAGS = -g -Wall
OBJS = Main.o recs.o 

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)
Main.o :
	$(CC) -c Main.cpp
recs.o : recs.hpp
	$(CC) -c recs.cpp
clean:
	rm -f core $(PROG) $(OBJS)

