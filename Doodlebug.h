/*
 * Doodlebug.h
 *
 *  Created on: Feb 25, 2017
 *      Author: anrus
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "Organism.h"

// This is a subclass of organism that implements a doodlebug.
class Doodlebug: public Organism {
private:
	static int doodlebugsCreated;
	static int doodlebugsAlive;
	virtual void breed();
	int getAntCell();
	bool isAnt(Organism *oPtr);
	int starvationCounter;
public:
	Doodlebug(int x, int y);
	virtual ~Doodlebug() { doodlebugsAlive--; }
	virtual void move();
	virtual char showSymbol() { return 'x'; }
	static void printSummary();
	static void moveAll();
	static int numAlive() { return doodlebugsAlive; }
	static int numCreated() { return doodlebugsCreated; }
};

#endif /* DOODLEBUG_H_ */
