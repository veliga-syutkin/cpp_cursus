/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/05/27 07:52:54 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
MateriaSource::MateriaSource() : _materia(NULL)
{
	std::cout << TERMINAL_GREEN << "\tDefault constructor MateriaSource called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource &other) : _materia(other._materia)
{
	std::cout << TERMINAL_GREEN << "\tCopy constructor MateriaSource called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		if (_materia)
			delete _materia; // Clean up existing materia if any
		_materia = other._materia; // Copy the materia from the other instance
		std::cout << TERMINAL_GREEN << "\tAssignation operator MateriaSource called" << TERMINAL_RESET << std::endl;
	}
	return (*this);
}

// Destructor
MateriaSource::~MateriaSource()
{
	if (_materia)
	{
		delete _materia; // Clean up materia if it exists
		_materia = NULL; // Set pointer to NULL to avoid dangling pointer
	}
	std::cout << TERMINAL_GREEN << "\tDestructor MateriaSource called" << TERMINAL_RESET << std::endl;
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

void	MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return;
	if (_materia)
		delete (_materia);
	_materia = m->clone(); // Clone the materia to store it
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	if (!_materia)
}
