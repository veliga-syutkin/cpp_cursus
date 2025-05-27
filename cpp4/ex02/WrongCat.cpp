/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/05/26 15:35:19 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << TERMINAL_GREEN << "\tDefault constructor WrongCat called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) // Call the base class copy constructor
{
	std::cout << TERMINAL_GREEN << "\tCopy constructor WrongCat called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		std::cout << TERMINAL_GREEN << "\tAssignation operator WrongCat called" << TERMINAL_RESET << std::endl;
	}
	return *this;
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << TERMINAL_GREEN << "\tDestructor WrongCat called" << TERMINAL_RESET << std::endl;
}

/******************************************************************************/
/*-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-"*/
/*-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._*/
/*-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-"*/
/******************************************************************************/
//	Private methods

/* ************************************************************************** */
//	Protected methods

/* ************************************************************************** */
//	Public methods

void	WrongCat::makeSound() const
{
	std::cout << TERMINAL_YELLOW << "\tWrongCat makes sound: Meow!" << TERMINAL_RESET << std::endl;
}
