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
MateriaSource::MateriaSource() : _indexMateria(0)
{
	for (int i = 0; i < 4; ++i)
		this->_materia[i] = NULL; // Initialize all materia pointers to NULL
	std::cout << TERMINAL_GREEN << "\tDefault constructor MateriaSource called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource &other) : _indexMateria(other._indexMateria)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other._materia[i])
			this->_materia[i] = other._materia[i]->clone();
		else
			this->_materia[i] = NULL;
	}
	std::cout << TERMINAL_GREEN << "\tCopy constructor MateriaSource called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (other._materia[i])
			{
				_materia[i] = other._materia[i]->clone(); // Clone the materia from the other object
				delete other._materia[i]; // Clean up the original materia to avoid memory leaks
			}
			else
				_materia[i] = NULL; // Set to NULL if no materia exists
		}
		std::cout << TERMINAL_GREEN << "\tAssignation operator MateriaSource called" << TERMINAL_RESET << std::endl;
	}
	return (*this);
}

// Destructor
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (_materia[i])
			delete _materia[i]; // Clean up each materia in the array
		_materia[i] = NULL; // Set to NULL after deletion
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
	if (_indexMateria < 5)
	{
		_materia[_indexMateria] = m->clone(); // Clone the materia to store it
		_indexMateria++;
	}
	else
	{
		std::cout << "\tMateriaSource is full, cannot learn more Materia." << std::endl;
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < _indexMateria; ++i)
		if (_materia[i] && _materia[i]->getType() == type)
			return (_materia[i]->clone()); // Return a clone of the requested materia
	return (NULL); // If no matching materia found, return NULL
}
