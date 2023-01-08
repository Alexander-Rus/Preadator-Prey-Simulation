all: PA6

CFLAGS = -Wall
CFLAGS_DEBUG = -g -O0 -Wall

PA6: PA6.o Organism.o Ant.o Doodlebug.o
	g++ $(CFLAGS) PA6.o Organism.o Ant.o Doodlebug.o -o PA6 

PA6.o: PA6.cpp
	g++ $(CFLAGS) -c PA6.cpp

Organism.o: Organism.cpp Organism.h
	g++ $(CFLAGS) -c Organism.cpp

Ant.o: Ant.cpp Ant.h
	g++ $(CFLAGS) -c Ant.cpp

Doodlebug.o: Doodlebug.cpp Doodlebug.h
	g++ $(CFLAGS) -c Doodlebug.cpp

clean:
	rm PA6 PA6.o Organism.o Ant.o Doodlebug.o




