/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/06/03 12:21:05 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
ScalarConverter::ScalarConverter()
{
	std::cout << TERMINAL_GREEN << "\tDefault constructor ScalarConverter called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
ScalarConverter::ScalarConverter(ScalarConverter &other)
{
	std::cout << TERMINAL_GREEN << "\tCopy constructor ScalarConverter called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
ScalarConverter &ScalarConverter::operator=(ScalarConverter &other)
{
	if (this != &other)
	{
		std::cout << TERMINAL_GREEN << "\tAssignation operator ScalarConverter called" << TERMINAL_RESET << std::endl;
	}
	return (*this);
}

// Destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << TERMINAL_GREEN << "\tDestructor ScalarConverter called" << TERMINAL_RESET << std::endl;
}

/******************************************************************************/
/*-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-"*/
/*-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._*/
/*-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-"*/
/******************************************************************************/
//	Private methods

bool	ScalarConverter::isFAtEnd(const std::string &str)
{
	// Check if the string ends with 'f' or 'F'
	if (str.back() == 'f' || str.back() == 'F')
		return (true);
	return (false);
}

bool	ScalarConverter::isDotBetweenDigits(const std::string &str)
{
	// Check if the string contains a dot between digits
	size_t dotPos = str.find('.');
	if (dotPos != std::string::npos)
		return (true);
	return (false);
}

bool	ScalarConverter::isValidString(const std::string &str)
{
	const std::string allowed = STR_ALLOWED;

	// Check if the string is a valid representation of a number
	if (str.empty())
		return (false);
	
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (allowed.find(str[i]) == std::string::npos)
            return false;
	}
	if (dotCounter(str) > 1)
		return (false);
	return (true);
}

int	ScalarConverter::dotCounter(const std::string &str)
{
	// Count the number of dots in the string
	int count = 0;
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] == '.')
			count++;
	}
	return (count);
}

/* ************************************************************************** */
//	Protected methods

/* ************************************************************************** */
//	Public methods
