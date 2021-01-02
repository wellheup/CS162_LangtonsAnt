/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/14/19
** Description: Implements several functions useful for displaying
** menus with choice selection to users and utilizes input validation
** to make sure that the user's choices are valid selections for 
** the context of the menu.
*********************************************************************/
#include <string>
#include <iostream>
#include "menuShell.hpp"
#include "isValidInput.hpp"

/*********************************************************************
** Description: initMenu() takes in a string for the name of a program
** and asks the player if they'd like to run that program. Y will
** return a 1 and N will return an 2
*********************************************************************/
int initMenu(std::string programName) {
	int attempts = 0;
	bool validEntry = false;
	std::string userIn;
	std::cout << "Would you like to run "<< programName<< "? (Y/N)" << std::endl;
	while (validEntry == false) {
		if (attempts ==1) {
			std::cout << "Please enter Y or N to select a choice." << std::endl;
		}
		std::getline(std::cin, userIn);
		if (isYesNo(userIn)) {
			validEntry = true;
		}
		attempts++;
	}
	if (userIn == "Y" || userIn == "y") {
		return 1;
	}
	else if (userIn == "N" || userIn == "n") {
		return 2;
	}
	else {
		std::cout << "Error w/ user input: " << userIn << std::endl;
		return -1;
	}
}

/*********************************************************************
** Description: initMenuSOrQ() uses the first parameter to prompt the 
** user then the second to define the first selection as opposed to 
** a "Quit" option and returns a 1 or a 2
*********************************************************************/
int initMenuSOrQ(std::string startPrompt, std::string text1) {
	int attempts = 0, userChoice = 0;
	bool validEntry = false;
	std::string userIn;

	std::cout << startPrompt << std::endl;
	std::cout << text1 << std::endl;
	std::cout << "2. Quit." << std::endl;

	while (validEntry == false) {
		if (attempts ==1) {
			std::cout << "Please enter 1, or 2 to select a choice." << std::endl;
		}
		std::getline(std::cin, userIn);
		if (isInt(userIn)) {
			if (isIntInRange(userIn, 1, 2)) {
				validEntry = true;
			}
			else {
				//std::cout << "Please use one of the options provided." << std::endl;
			}
		}
		else {
			//std::cout << "Please enter an integer value." << std::endl;
		}
		attempts++;
	}

	if (validEntry) {
		userChoice = stoi(userIn);
		return userChoice;
	}
	else {
		std::cout << "Error w/ user input: " << userIn << std::endl;
		return -1;
	}
}

/*********************************************************************
** Description: choiceMenu1() uses the first parameter to prompt the
** user then the second to provide the first selection as opposed to a
** "Nevermind" option and returns a 1 or a 2
*********************************************************************/
int choiceMenu1(std::string startPrompt, std::string text1) {
	int attempts = 0, userChoice = 0;
	bool validEntry = false;
	std::string userIn;

	std::cout << startPrompt << std::endl;
	std::cout << text1 << std::endl;
	std::cout << "2. Nevermind, I'd rather not." << std::endl;

	while (validEntry == false) {
		if (attempts ==1) {
			std::cout << "Please enter 1 or 2 to select a choice." << std::endl;
		}
		std::getline(std::cin, userIn);
		if (isInt(userIn)) {
			if (isIntInRange(userIn, 1, 2)) {
				validEntry = true;
			}
			else {
				//std::cout << "Please use one of the options provided." << std::endl;
			}
		}
		else {
			//std::cout << "Please enter an integer value." << std::endl;
		}
		attempts++;
	}


	if (validEntry) {
		userChoice = stoi(userIn);
		return userChoice;
	}
	else {
		std::cout << "Error w/ user input: " << userIn << std::endl;
		return -1;
	}
}

/*********************************************************************
** Description: choiceMenu2() uses the first parameter to prompt the
** user then the others to provide the first selections as opposed to a
** "Nevermind" option and returns 1-3
*********************************************************************/
int choiceMenu2(std::string startPrompt, std::string text1, std::string text2) {
	int attempts = 0, userChoice = 0;
	bool validEntry = false;
	std::string userIn;

	std::cout << startPrompt << std::endl;
	std::cout << text1 << std::endl;
	std::cout << text2 << std::endl;
	std::cout << "3. Nevermind, I'd rather not." << std::endl;

	while (validEntry == false) {
		if (attempts ==1) {
			std::cout << "Please enter 1, 2, or 3 to select a choice." << std::endl;
		}
		std::getline(std::cin, userIn);
		if (isInt(userIn)) {
			if (isIntInRange(userIn, 1, 3)) {
				validEntry = true;
			}
			else {
				//std::cout << "Please use one of the options provided." << std::endl;
			}
		}
		else {
			//std::cout << "Please enter an integer value." << std::endl;
		}
		attempts++;
	}

	if (validEntry) {
		userChoice = stoi(userIn);
		return userChoice;
	}
	else {
		std::cout << "Error w/ user input: " << userIn << std::endl;
		return -1;
	}
}

/*********************************************************************
** Description: choiceMenu3() uses the first parameter to prompt the
** user then the others to provide the first selections as opposed to a
** "Nevermind" option and returns 1-4
*********************************************************************/
int choiceMenu3(std:: string startPrompt, std::string text1, std::string text2, std::string text3) {
	int attempts = 0, userChoice = 0;
	bool validEntry = false;
	std::string userIn;
	
	std::cout << startPrompt << std::endl; 
	std::cout << text1 << std::endl;
	std::cout << text2 << std::endl;
	std::cout << text3 << std::endl;
	std::cout << "4. Nevermind, I'd rather not." << std::endl;

	while (validEntry == false) {
		if (attempts == 1) {
			std::cout << "Please enter 1, 2, 3, or 4 to select a choice." << std::endl;
		}
		std::getline(std::cin, userIn);
		if (isInt(userIn)) {
			if (isIntInRange(userIn, 1, 4)) {
				validEntry = true;
			}
			else {
				//std::cout << "Please use one of the options provided." << std::endl;
			}
		}
		else {
			//std::cout << "Please enter an integer value." << std::endl;
		}
		attempts++;
	}
	
	if (validEntry) {
		userChoice = stoi(userIn);
		return userChoice;
	}
	else {
		std::cout << "Error w/ user input: " << userIn << std::endl;
		return -1;
	}
}

/*********************************************************************
** Description: choiceMenu4() uses the first parameter to prompt the
** user then the others to provide the first selections as opposed to a
** "Nevermind" option and returns 1-5
*********************************************************************/
int choiceMenu4(std::string startPrompt, std::string text1, std::string text2, std::string text3, std::string text4) {
	int attempts = 0, userChoice = 0;
	bool validEntry = false;
	std::string userIn;

	std::cout << startPrompt << std::endl;
	std::cout << text1 << std::endl;
	std::cout << text2 << std::endl;
	std::cout << text3 << std::endl;
	std::cout << text4 << std::endl;
	std::cout << "5. Nevermind, I'd rather not." << std::endl;

	while (validEntry == false) {
		if (attempts == 1) {
			std::cout << "Please enter 1, 2, 3, 4, or 5 to select a choice." << std::endl;
		}
		std::getline(std::cin, userIn);
		if (isInt(userIn)) {
			if (isIntInRange(userIn, 1, 5)) {
				validEntry = true;
			}
			else {
				//std::cout << "Please use one of the options provided." << std::endl;
			}
		}
		else {
			//std::cout << "Please enter an integer value." << std::endl;
		}
		attempts++;
	}

	if (validEntry) {
		userChoice = stoi(userIn);
		return userChoice;
	}
	else {
		std::cout << "Error w/ user input: " << userIn << std::endl;
		return -1;
	}
}

/*********************************************************************
** Description: chooseIntInRange() prompts the user with the first 
** parameter then compares user input to make sure it is an int 
** between the low and high values provided
*********************************************************************/
int chooseIntInRange(std::string startPrompt, int low, int high) {
	std::cout << startPrompt << std::endl;
	int attempts = 0, userChoice = 0;
	bool validEntry = false;
	std::string userIn;
	
	while (validEntry == false) {
		if (attempts == 1) {
			std::cout << "Please enter an integer between " << low << " and " << high << "." << std::endl;
		}
		std::getline(std::cin, userIn);
		if (isInt(userIn)) {
			if (isIntInRange(userIn, low, high)) {
				validEntry = true;
			}
			else {
				//std::cout << "Please enter an integer between" << low << " and " << high << "." << std::endl;
			}
		}
		else {
			//std::cout << "Please enter an integer value." << std::endl;
		}
		attempts++;
	}

	if (validEntry) {
		userChoice = stoi(userIn);
		return userChoice;
	}
	else {
		std::cout << "Error w/ user input: " << userIn << std::endl;
		return -1;
	}
}