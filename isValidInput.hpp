/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/14/19
** Description: Prototypes several functions useful for input
** validation. Each function receives parameters and returns whether
** or not they are valid input with a bool value.
*********************************************************************/
#ifndef ISVALIDINPUT_HPP
#define ISVALIDINPUT_HPP

/*********************************************************************
** Description: isInt() takes a string parameter and returns true if
** the string contains only an integer.
*********************************************************************/ 
bool isInt(std::string userIn);

/*********************************************************************
** Description: isIntInRange() takes in a string parameter, and a low
** and high integer parameter then returns true only if the string
** is an integer between the low and high values.
*********************************************************************/
bool isIntInRange(std::string userIn, int low, int high);

/*********************************************************************
** Description: isDouble() takes a string parameter and returns true if
** the string contains only a numbers and only one decimal point
** within the string.
*********************************************************************/ 
bool isDouble(std::string userIn);

/*********************************************************************
** Description: isYesNo() takes a string parameter and returns true
** only if the string is a stand-alone Y or N character. Reference:
** http://www.cplusplus.com/reference/string/string/compare/
*********************************************************************/
bool isYesNo(std::string userIn);

#endif