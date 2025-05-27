/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/05/27 08:07:43 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
Cure::Cure() : AMateria("cure")
{
	std::cout << TERMINAL_GREEN << "\tDefault constructor Cure called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << TERMINAL_GREEN << "\tCopy constructor Cure called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
		std::cout << TERMINAL_GREEN << "\tAssignation operator Cure called" << TERMINAL_RESET << std::endl;
	}
	return (*this);
}

// Destructor
Cure::~Cure()
{
	std::cout << TERMINAL_GREEN << "\tDestructor Cure called" << TERMINAL_RESET << std::endl;
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

AMateria *Cure::clone() const
{
	std::cout << TERMINAL_BOLD_WHITE << "\tClone method Cure called" << TERMINAL_RESET << std::endl;
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << TERMINAL_BOLD_WHITE << "* heals " << target.getName() << "'s wounds *" << TERMINAL_RESET << std::endl;
}
