/*
 * Organism.cpp
 *
 *  Created on: Feb 25, 2017
 *      Author: anrus
 */

#include <deque>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <string>
#include "Ant.h"
#include "Organism.h"

using std::cout;
using std::cin;
using std::endl;

extern matrix *GridPtr;
extern 	int GridSize;

Organism::Organism() {
	x = 0;
	y = 0;
	completedTimeStep = 0;
	breedCounter = 0;
}

/* Looks at the four surrounding cells to find an empty one. If there is more than
*  one empty cell, it will randomly pick one of them and returns the direction to move.
*  If there are no empty cells it returns -1. */
int Organism::getEmptyCell() {
	std::deque<int> openCells;

	if (((y - 1) >= 0 ) && (*GridPtr)[x][y - 1] == NULL) {
		openCells.push_back(UP);
	}
	if (((x + 1) < GridSize) && (*GridPtr)[x + 1][y] == NULL) {
		openCells.push_back(RIGHT);
	}
	if (((y + 1) < GridSize) && (*GridPtr)[x][y + 1] == NULL) {
		openCells.push_back(DOWN);
	}
	if (((x - 1) >= 0) && (*GridPtr)[x - 1][y] == NULL) {
		openCells.push_back(LEFT);
	}

	if (openCells.empty()) {
		return -1;
	}

	int index = rand() % openCells.size();
	int direction = openCells[index];

	return direction;
}

// Moves an organism in the specified direction.
void Organism::updateLocation(int direction) {
	// Remove the organism from its current location in preparation for its movement.
	(*GridPtr)[x][y] = NULL;
	switch (direction) {
	case UP:
		y--;
		break;
	case RIGHT:
		x++;
		break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	default:
		cout << "Error unexpected direction" << endl;
		exit(-1);
	}
}

/* Find a location for an offspring to be born and return its coordinates
 * in newX and newY and return true. If there is no space return false.
 */
bool Organism::getBreedLocation(int& newX, int& newY) {
	int direction = getEmptyCell();
	if (direction == -1) {
		return false;
	}
	switch (direction) {
	case UP:
		newY--;
		break;
	case RIGHT:
		newX++;
		break;
	case DOWN:
		newY++;
		break;
	case LEFT:
		newX--;
		break;
	default:
		cout << "Error unexpected direction" << endl;
		exit(-1);
	}
	return true;
}
