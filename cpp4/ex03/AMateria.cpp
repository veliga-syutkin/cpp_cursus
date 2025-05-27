/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/05/27 07:52:54 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
AMateria::AMateria(): _type("unknown")
{
	std::cout << TERMINAL_GREEN << "\tDefault constructor AMateria called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
AMateria::AMateria(const AMateria &other) : _type(other._type)
{
	std::cout << TERMINAL_GREEN << "\tCopy constructor AMateria called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		std::cout << TERMINAL_GREEN << "\tAssignation operator AMateria called" << TERMINAL_RESET << std::endl;
	}
	return (*this);
}

// Destructor
AMateria::~AMateria()
{
	std::cout << TERMINAL_GREEN << "\tDestructor AMateria called" << TERMINAL_RESET << std::endl;
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

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << TERMINAL_GREEN << "\tParameterized constructor AMateria called with type: " << type << TERMINAL_RESET << std::endl;
}

const std::string&	AMateria::getType() const
{
	return (this->_type);
}
