/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/05/26 15:35:19 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << TERMINAL_GREEN << "\tDefault constructor WrongAnimal called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) // Copy the type from the other WrongAnimal
{
	std::cout << TERMINAL_GREEN << "\tCopy constructor WrongAnimal called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		this->type = other.type; // Assuming type is a member variable
		std::cout << TERMINAL_GREEN << "\tAssignation operator WrongAnimal called" << TERMINAL_RESET << std::endl;
	}
	return *this;
}

// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << TERMINAL_GREEN << "\tDestructor WrongAnimal called" << TERMINAL_RESET << std::endl;
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

WrongAnimal::WrongAnimal(const std::string &type_) : type(type_)
{
	std::cout << TERMINAL_GREEN << "\tConstructor with type WrongAnimal called" << TERMINAL_RESET << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << TERMINAL_YELLOW << "WrongAnimal makes a sound!" << TERMINAL_RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}