/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/14/19
** Description: Specifies LangtonsAnt class which creates a 2D array
** and manages a simulation of an ant moving through that array
** following the rules of the Langton's Ant simulation. Uses menuShell
** to manage user interaction.
*********************************************************************/
#ifndef LANGTONSANT_CPP
#define LANGTONSANT_CPP

class LangtonsAnt{
private:
	char** grid;

	int domain = 0, domainMin = 10, domainMax = 100,
		range = 0, rangeMin = 10, rangeMax = 100,
		stepsToDo = 0, defaultStepsToDo = 100, stepsToDoMin = 1, stepsToDoMax = 100000,
		antX = 0, defaultStartX = 5,
		antY = 0, defaultStartY = 5,
		failedSteps = 0,
		stepsCompleted = 0,
		runModeInt = 0;

	enum Direction {North, East, South, West};
	Direction facing= South;

	enum Mode {Standard=1, Custom, Random, Quit};
	Mode gameMode = Standard;

	std::string programName = "Langton's Ant",
		startPrompt = "How would you like to run Langton's Ant?",
		mode1 = "1. Standard (a 10x10 grid, 100 steps, starting at (5,5) facing South)",
		mode2 = "2. Custom (MAIN ASSIGNMENT, enter your own values.",
		mode3 = "3. Random (EXTRA CREDIT!) (maximum "+ std::to_string(stepsToDoMax)+" steps)";
	
	/*********************************************************************
	** Description: chooseGameMode presents menus of different ways to run
	** LangtonsAnt and updates the class's private attributes depending on
	** the user's choices
	*********************************************************************/
	void chooseRunMode();

	/*********************************************************************
	** Description: initGrid() initializes the 2D array for LangtonsAnt
	*********************************************************************/
	void initGrid();

	/*********************************************************************
	** Description: printGrid() prints the 2D array for LangtonsAnt in the
	** console with borders and current values
	*********************************************************************/
	void printGrid();

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
	void moveAnt();

	/*********************************************************************
	** Description: isSquareWhite() checks to see if the square at the
	** location provided is white and returns true if it is
	*********************************************************************/
	bool isSquareWhite(int x, int y);

	/*********************************************************************
	** Description: isValidLocation() checks to see if the location
	** provided is a valid location to move to and returns true if so
	*********************************************************************/
	bool isValidLocation(int x, int y);

	/*********************************************************************
	** Description: changeColor() changes the color of the square between
	** white and black for the square at the location provided
	*********************************************************************/
	void changeColor(int x, int y);

public:
	LangtonsAnt(){ //constructor function
		chooseRunMode();
		initGrid();
		printGrid();
		moveAnt();
	}

	~LangtonsAnt(){ 
		std::cout<< "\nEnding program.\n"<< std::endl;
		for(int i=0; i<domain; i++){
			delete [] grid[i];
			grid[i]= nullptr;
		}
		delete [] grid;
		grid= nullptr;
	}
};

#endif