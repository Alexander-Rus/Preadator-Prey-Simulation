
/*
 * PA6.cpp
 *
 *  Created on: Feb 25, 2017
 *      Author: anrus, fagaziano
 */
//holds the main program, read input and initialize

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "Organism.h"
#include "Doodlebug.h"
#include "Ant.h"

using std::cout;
using std::cin;
using std::endl;

matrix *GridPtr;
int GridSize = 20;
int TimeStep;

// Show the current state of the grid.
void printGrid() {
	if (TimeStep == 0) {
		cout << "Time Step:  " << TimeStep << " (Initial Configuration)" << endl;
	}
	else {
		cout << "Time Step:  " << TimeStep << endl;
	}
	for (int y = 0; y < GridSize; y++) {
		for (int x = 0; x < GridSize; x++) {
			if ((*GridPtr)[x][y] == NULL) {
				cout << ".";
			}
			else {
				cout << (*GridPtr)[x][y]->showSymbol();
			}
		}
		cout << endl;
	}
}

// Search the grid for any organsism and delete them.
void freeMemory() {
	for (int y = 0; y < GridSize; y++) {
		for (int x = 0; x < GridSize; x++) {
			if ((*GridPtr)[x][y] != NULL) {
				delete (*GridPtr)[x][y];
			}
		}
		cout << endl;
	}
}

/* Create the inital board by puting the starting number of organisms
 * in random places. */
void initGrid(int gridSize, int numDoodleBugs, int numAnts) {

	for (int x = 0; x < gridSize; x++) {
		for (int y = 0; y < gridSize; y++) {
			(*GridPtr)[x][y] = NULL;
		}
	}

	int doobleBugsToplace = numDoodleBugs;
	while (doobleBugsToplace) {
		int x = rand()%gridSize;
		int y = rand()%gridSize;
		if ((*GridPtr)[x][y] == NULL) {
			(*GridPtr)[x][y] = new Doodlebug(x, y);
			doobleBugsToplace--;
		}
	}

	int antsToPlace = numAnts;
	while (antsToPlace) {
		int x = rand()%gridSize;
		int y = rand()%gridSize;
		if ((*GridPtr)[x][y] == NULL) {
			(*GridPtr)[x][y] = new Ant(x, y);
			antsToPlace--;
		}
	}
}


// The main function reads the arguments, runs the simulation, and prints the summaries.
int main(int argc, char *argv[]) {
	int numDoodleBugs = 5;
	int numAnts = 100;
	int time_steps = 1000;
	int seed = 1;
	int pause = 0;

	const int MINARGS = 1;

	// Checks to make sure the number of arguments is correct before running
	// anything else. If not correct, throws an error.
	if (argc < MINARGS) {
		cout << "Error. Invalid number of arguments." << endl;
		exit(-1);
	}

	if (argc > 1) {
		GridSize = atoi(argv[1]);
	}


	if (argc > 2) {
		numDoodleBugs = atoi(argv[2]);
	}

	if (argc > 3) {
		numAnts = atoi(argv[3]);
	}

	if (argc > 4) {
		time_steps = atoi(argv[4]);
	}

	if (argc > 5) {
		seed = atoi(argv[5]);
		if (seed == 0) {
			seed = time(NULL);
		}
	}
	srand(seed);

	if (argc > 6) {
		pause = atoi(argv[6]);
	}

	/* Declare the grid of the correct size. As a vector of vectors.
	 * See the typedef for the matrix in Organism.h.
	 */
	matrix grid(GridSize, std::vector<Organism*>(GridSize));
	GridPtr = &grid;

	initGrid(GridSize, numDoodleBugs, numAnts);

	/* Run the simulation by moving all the doodlebugs and ants for the correct
	 * number of steps.
	 */
	for (TimeStep = 0; TimeStep < time_steps; TimeStep++) {

		Doodlebug::moveAll();

		Ant::moveAll();

		if (pause > 0 && TimeStep % pause == 0) {
			printGrid();
			cout << "Press Enter to continue" << endl;
			getchar();
		}

		if (Doodlebug::numAlive() == 0 || Ant::numAlive() == 0) {
			break;
		}

	}

	// Print summary statistics.
	cout << "Command Line:  ";
	for (int i = 0; i < argc; i++) {
		cout << argv[i] << " ";
	}
	cout << endl;

	cout << "Number of Steps Simulated:  " << TimeStep << endl;
	Ant::printSummary();
	Doodlebug::printSummary();

	cout << endl << "FINAL CONFIGURATION " << endl;
	printGrid();
	freeMemory();
}

