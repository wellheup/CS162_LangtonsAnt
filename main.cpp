/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/14/19
** Description: Prompts the user to start the LangtonsAnt program
** class then runs it if the user wishes to.
*********************************************************************/
#include <iostream>
#include <string>
#include "./langtonsAnt.hpp"
#include "./menuShell.hpp"

int main() {
	std::string startupText = "1. Start Langton's Ant simulation.",
		greeting = "Welcome to Phillip Wellheuser's Langon's Ant program. What would you like to do?";
	int plays = 0;

	while (initMenuSOrQ(greeting, startupText)== 1) { 
		
		if (plays > 0) {
			greeting = "Play again?";
		}
		LangtonsAnt myLangtonsAnt;
		plays++;
	}
  
}