/*
 * Organism.h
 *
 *  Created on: Feb 25, 2017
 *      Author: anrus
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_
#include <vector>

// This is an abstract class for organisms of different types.
class Organism {
protected:
	int x;
	int y;
	int completedTimeStep;
	int breedCounter;
	int getEmptyCell();
	void updateLocation(int direction);
	virtual void breed() = 0;
	bool getBreedLocation(int& newX, int& newY);
public:
	Organism();
	virtual ~Organism(){};
	virtual void move() = 0;
	virtual char showSymbol() = 0;
};

// This is used to create the grid. As a vector of vectors of pointers to organisms.
typedef std::vector< std::vector<Organism*> > matrix;

// Constants to specify what direction organisms can move.
enum Direction { UP = 1, RIGHT = 2, DOWN = 3, LEFT = 4};

#endif /* ORGANISM_H_ */
