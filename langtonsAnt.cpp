/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/14/19
** Description: Implements LangtonsAnt class which creates a 2D array
** and manages a simulation of an ant moving through that array 
** following the rules of the Langton's Ant simulation. Uses menuShell
** to manage user interaction. 
*********************************************************************/
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "langtonsAnt.hpp"
#include "menuShell.hpp"

/*********************************************************************
** Description: chooseRunMode presents menus of different ways to run
** LangtonsAnt and updates the class's private attributes depending on
** the user's choices
*********************************************************************/
void LangtonsAnt::chooseRunMode() {
	runModeInt = choiceMenu3(startPrompt, mode1, mode2, mode3);

	if (runModeInt == Standard) {
		domain = domainMin+2;
		range = rangeMin+2;
		stepsToDo = defaultStepsToDo;
		antX = defaultStartX;
		antY = defaultStartY;
		facing = East;
	}
	else if (runModeInt == Custom) { 
		//several strings are provided in this section of code for use in prompting users. 
		//these strings are placed here so that they are easier to refer to 
		std::string chooseDomain = "Please enter an integer for the number of columns on the board between " + std::to_string(domainMin) + " and " + std::to_string(domainMax),
			chooseRange = "Please enter an integer for the number of rows on the board between " + std::to_string(rangeMin) + " and " + std::to_string(rangeMax);
		
		domain = chooseIntInRange(chooseDomain, domainMin, domainMax) + 2;
		range = chooseIntInRange(chooseRange, rangeMin, rangeMax) + 2;
		
		std::string chooseStepsToDo = "Please enter the number of steps to perform during simulation between " + std::to_string(stepsToDoMin) + " and " + std::to_string(stepsToDoMax);
		stepsToDo = chooseIntInRange(chooseStepsToDo, stepsToDoMin, stepsToDoMax);

		int tempDomain = domain - 2, tempRange = range - 2;
		std::string 
			chooseAntX = "Please enter the row to start the ant at from 1 to " + std::to_string(tempDomain),
			chooseAntY = "Please enter the column to start the ant at from 1 to " + std::to_string(tempRange);
		antX = chooseIntInRange(chooseAntX, 1, domain - 2);
		antY = chooseIntInRange(chooseAntY, 1, range - 2);

		std::string chooseFacing = "Which direction should the ant be facing at start?",
			facingNorth = "1. North",
			facingEast = "2. East",
			facingSouth = "3. South",
			facingWest = "4. West";

		int facingTemp = choiceMenu4(chooseFacing, facingNorth, facingEast, facingSouth, facingWest);
		if (facingTemp == North) {
			facing = North;
		}
		else if (facingTemp == East) {
			facing = East;
		}
		else if (facingTemp == South) {
			facing = South;
		}
		else if (facingTemp == West) {
			facing = West;
		}
		else
			facing = East;
	}
	else if (runModeInt == Random) { 
		//math for random is not simplified as it is then easier to break apart into 
		//the different elements of the equations that way
		unsigned seed;
		seed = time(0);
		srand(seed);
		
		domain = (rand() % (domainMax - domainMin + 1)) + domainMin + 2;
		range = (rand() % (rangeMax - rangeMin + 1)) + rangeMin + 2;
		stepsToDo = (rand() % (stepsToDoMax - stepsToDoMin + 1)) + stepsToDoMin;
		antX = (rand() % (domain - 2 - 1 + 1)) + 1;
		antY = (rand() % (range - 2 - 1 + 1)) + 1;

		int facingTemp = (rand() % (4 - 1 + 1)) + 1;
		if (facingTemp == North) {
			facing = North;
		}
		else if (facingTemp == East) {
			facing = East;
		}
		else if (facingTemp == South) {
			facing = South;
		}
		else if (facingTemp == West) {
			facing = West;
		}
		else
			facing = East;
	}
}

/*********************************************************************
** Description: initGrid() initializes the 2D array for LangtonsAnt
*********************************************************************/
void LangtonsAnt::initGrid() {
	grid = new char*[domain];
	for (int i = 0; i < domain; i++) {
		grid[i] = new char[range];
	}

	for (int i = 0; i < domain; i++) {
		for (int j = 0; j < range; j++) {
			if (i == 0 || i == domain - 1) {
				grid[i][j] = '|';
			}
			else if (j == 0 || j == range - 1) {
				grid[i][j] = '-';
			}
			else {
				grid[i][j] = ' ';
			}
		}
	}
}

/*********************************************************************
** Description: printGrid() prints the 2D array for LangtonsAnt in the 
** console with borders and current values
*********************************************************************/
void LangtonsAnt::printGrid() {
	for (int i = 0; i < range; i++) {
		std::cout << "\n";
		for (int j = 0; j < domain; j++) {
			if (i == antY && j == antX) {
				std::cout << "*" << " ";
			}
			else {
				std::cout << grid[j][i] << " ";
			}
		}
	}
}

/*********************************************************************
** Description: moveAnt() changes the color of the square the ant 
** currently resides if it's the first step, moves it 1 space in the 
** direction it is facing if it is valid (isValidLocation()), then 
** alters the direction the ant is facing depending on the color of 
** the new square (isSquareWhite()), changes the color of the new 
** square (changeColor()), increments the number of steps taken, and 
** prints the grid. If facing an invalid location, the ant turns 180
** degrees if it faces a wall for its next step and does not count 
** that step. 
*********************************************************************/
void LangtonsAnt::moveAnt() {
	while (stepsCompleted < stepsToDo) {
		if (stepsCompleted == 0) {
			changeColor(antX, antY);
		}
		if (facing == North) {
			if (isValidLocation(antX, antY - 1) == true) {
				antY--;
				if (isSquareWhite(antX, antY) == true) {
					facing = East;
				}
				else {
					facing = West;
				}
				changeColor(antX, antY);
				stepsCompleted++;
				printGrid();
			}
			else {
				facing = South;
				failedSteps++;
			}
		}
		else if (facing == East) {
			if (isValidLocation(antX + 1, antY) == true) {
				antX++;
				if (isSquareWhite(antX, antY) == true) {
					facing = South;
				}
				else {
					facing = North;
				}
				changeColor(antX, antY);
				stepsCompleted++;
				printGrid();
			}
			else {
				facing = West;
				failedSteps++;
			}
		}
		else if (facing == South) {
			if (isValidLocation(antX, antY + 1) == true) {
				antY++;
				if (isSquareWhite(antX, antY) == true) {
					facing = West;
				}
				else {
					facing = East;
				}
				changeColor(antX, antY);
				stepsCompleted++;
				printGrid();
			}
			else {
				facing = North;
				failedSteps++;
			}
		}
		else if (facing == West) {
			if (isValidLocation(antX - 1, antY) == true) {
				antX--;
				if (isSquareWhite(antX, antY) == true) {
					facing = North;
				}
				else {
					facing = South;
				}
				changeColor(antX, antY);
				stepsCompleted++;
				printGrid();
			}
			else {
				facing = East;
				failedSteps++;
			}
		}
		else
			std::cout << "error in moveAnt()" << std::endl;
	}
}

/*********************************************************************
** Description: isSquareWhite() checks to see if the square at the
** location provided is white and returns true if it is
*********************************************************************/
bool LangtonsAnt::isSquareWhite(int x, int y) {
	if (grid[x][y] == ' ') {
		return true;
	}
	else
		return false;
}

/*********************************************************************
** Description: isValidLocation() checks to see if the location 
** provided is a valid location to move to and returns true if so
*********************************************************************/
bool LangtonsAnt::isValidLocation(int x, int y) {
	if (grid[x][y] == '-' || grid[x][y] == '|') {
		return false;
	}
	else
		return true;
}

/*********************************************************************
** Description: changeColor() changes the color of the square between
** white and black for the square at the location provided
*********************************************************************/
void LangtonsAnt::changeColor(int x, int y) {
	if (grid[x][y] == ' ') {
		grid[x][y] = '#';
	}
	else if (grid[x][y] == '#') {
		grid[x][y] = ' ';
	}
	else
		std::cout << "Error with changeColor()" << std::endl;
}
