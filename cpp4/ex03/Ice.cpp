/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/05/27 08:07:43 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
Ice::Ice() : AMateria("ice")
{
	std::cout << TERMINAL_GREEN << "\tDefault constructor Ice called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << TERMINAL_GREEN << "\tCopy constructor Ice called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
		std::cout << TERMINAL_GREEN << "\tAssignation operator Ice called" << TERMINAL_RESET << std::endl;
	}
	return (*this);
}

// Destructor
Ice::~Ice()
{
	std::cout << TERMINAL_GREEN << "\tDestructor Ice called" << TERMINAL_RESET << std::endl;
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

AMateria *Ice::clone() const
{
	std::cout << TERMINAL_GREEN << "\tClone method Ice called" << TERMINAL_RESET << std::endl;
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << TERMINAL_BLUE << "* shoots an ice bolt at " << target.getName() << " *" << TERMINAL_RESET << std::endl;
}