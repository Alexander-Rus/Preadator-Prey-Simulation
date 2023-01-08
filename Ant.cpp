/*
 * Ant.cpp
 *
 *  Created on: Feb 25, 2017
 *      Author: anrus
 */

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <deque>
#include "Organism.h"
#include "Ant.h"

using std::cout;
using std::cin;
using std::endl;

extern matrix *GridPtr;
extern 	int GridSize;
extern  int TimeStep;
const int BREED_THRESHOLD = 3;
int Ant::antsCreated = 0;
int Ant::antsAlive = 0;

Ant::Ant(int x, int y) {
	this->x = x;
	this->y = y;
	antsCreated++;
	antsAlive++;
	completedTimeStep = TimeStep;
	breedCounter = 0;
}

// Move an ant to an empty cell at random, and breed when appropriate.
void Ant::move() {

	// If an ant was just born, don't move it.
	if (completedTimeStep == TimeStep) {
		return;
	}

	// Move the ant if possible.
	int direction = getEmptyCell();

	if (direction != -1) {
		updateLocation(direction);
		(*GridPtr)[x][y] = this;
	}

	completedTimeStep = TimeStep;
	breedCounter++;

	// If it is time to breed, try to create a new ant.
	if (breedCounter >= BREED_THRESHOLD) {
		breed();
	}
}

// Print statistics.
void Ant::printSummary() {
	cout << "Total Number of Ants Created:  " << antsCreated;
	cout << ", Ants Remaining:  " << antsAlive << endl;
}

// Scan the grid and move any ants that are found.
void Ant::moveAll() {
	for (int x = 0; x < GridSize; x++) {
		for (int y = 0; y < GridSize; y++) {
			Organism *org = (*GridPtr)[x][y];
			if (org != NULL) {
				if (dynamic_cast<Ant *>(org)) {
					org->move();
				}
			}
		}
	}
}

// If there is an open space for breeding, create a new ant.
void Ant::breed() {

	int newX = x, newY = y;
	if (getBreedLocation(newX, newY)) {
		(*GridPtr)[newX][newY] = new Ant(newX, newY);
		breedCounter = 0;
	}
}
