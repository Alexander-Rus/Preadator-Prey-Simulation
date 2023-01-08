/*
 * Ant.h
 *
 *  Created on: Feb 25, 2017
 *      Author: anrus
 */

#ifndef ANT_H_
#define ANT_H_

#include "Organism.h"

// This is a subclass of organism that implements an ant.
class Ant: public Organism {
private:
	static int antsCreated;
	static int antsAlive;
	virtual void breed();
public:
	Ant(int x, int y);
	virtual ~Ant() { antsAlive--; }
	virtual void move();
	virtual char showSymbol() { return 'o'; }
	static void printSummary();
	static void moveAll();
	static int numAlive() { return antsAlive; }
	static int numCreated() { return antsCreated; }
};

#endif /* ANT_H_ */
