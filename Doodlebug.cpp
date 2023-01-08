/*
 * Doodlebug.cpp
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
#include "Doodlebug.h"

using std::cout;
using std::cin;
using std::endl;

extern matrix *GridPtr;
extern 	int GridSize;
extern  int TimeStep;
const int BREED_THRESHOLD = 8;
int Doodlebug::doodlebugsCreated = 0;
int Doodlebug::doodlebugsAlive = 0;

Doodlebug::Doodlebug(int x, int y) {
	this->x = x;
	this->y = y;
	doodlebugsCreated++;
	doodlebugsAlive++;
	completedTimeStep = TimeStep;
	breedCounter = 0;
	starvationCounter = 0;
}

/* Eat an ant if there is one in an adjacent cell. Otherwise move to an empty
 * cell randomly. Remove the doodlebug if its starves.
 */
void Doodlebug::move() {

	// If a doodlebug was just born, don't move it.
	if (completedTimeStep == TimeStep) {
		return;
	}

	// See if there is an adjacent ant.
	int antDirection = getAntCell();

	if (antDirection != -1) {
		// Eat the adjacent ant and move to its cell.
		updateLocation(antDirection);
		delete (*GridPtr)[x][y];
		(*GridPtr)[x][y] = this;
		starvationCounter = -1;
	}
	else {
		// Check if the doodlebug has starved to death.
		if (starvationCounter >= 2) {
			delete (*GridPtr)[x][y];
			(*GridPtr)[x][y] = NULL;
			return;
		}

		// There is no ant to eat, so the doodlebug just moves.
		int direction = getEmptyCell();

		if (direction != -1) {
			updateLocation(direction);
			(*GridPtr)[x][y] = this;
		}
	}

	completedTimeStep = TimeStep;
	breedCounter++;
	starvationCounter++;

	// If it is time to breed, try to create a new doodlebug.
	if (breedCounter >= BREED_THRESHOLD) {
		breed();
	}
}

// Print statistics.
void Doodlebug::printSummary() {
	cout << "Total Number of Doodlebugs Created:  " << doodlebugsCreated;
	cout << ", Doodlebugs Remaining:  " << doodlebugsAlive << endl;
}

// Scan the grid and move any doodlebugs that are found.
void Doodlebug::moveAll() {
	for (int x = 0; x < GridSize; x++) {
		for (int y = 0; y < GridSize; y++) {
			Organism *org = (*GridPtr)[x][y];
			if (org != NULL) {
				if (dynamic_cast<Doodlebug *>(org)) {
					org->move();
				}
			}
		}
	}
}

// If there is an open space for breeding, create a new doodlebug.
void Doodlebug::breed() {

	int newX = x, newY = y;
	if (getBreedLocation(newX, newY)) {
		(*GridPtr)[newX][newY] = new Doodlebug(newX, newY);
		breedCounter = 0;
	}
}

// Check if a cell contains an ant.
bool Doodlebug::isAnt(Organism *oPtr) {
	if (dynamic_cast<Ant *>(oPtr)) {
		return true;
	}
	return false;
}

// Return the direction of an ant that can be eaten. Or -1 if no adjacent ants.
int Doodlebug::getAntCell() {
	std::deque<int> antCells;

	// Up
	if (((y - 1) >= 0 ) && isAnt((*GridPtr)[x][y - 1])) {
		antCells.push_back(UP);
	}
	// Right
	if (((x + 1) < GridSize) && isAnt((*GridPtr)[x + 1][y])) {
		antCells.push_back(RIGHT);
	}
	// Down
	if (((y + 1) < GridSize) && isAnt((*GridPtr)[x][y + 1])) {
		antCells.push_back(DOWN);
	}
	// Left
	if (((x - 1) >= 0) && isAnt((*GridPtr)[x - 1][y])) {
		antCells.push_back(LEFT);
	}

	if (antCells.empty()) {
		return -1;
	}

	int index = rand() % antCells.size();
	int direction = antCells[index];

	return direction;
}
