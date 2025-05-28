/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:26:58 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/28 14:06:24 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
Character::Character() : _inventoryIndex(0), _name("Nameless")
{
	for (int i = 0; i < 4; ++i)
		this->_inventory[i] = NULL;
	std::cout << TERMINAL_GREEN << "\tDefault constructor Character called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
Character::Character(const Character &other) : _inventoryIndex(other._inventoryIndex), _name(other._name)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	std::cout << TERMINAL_GREEN << "\tCopy constructor Character called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->_inventoryIndex = other._inventoryIndex;
		this->_name = other._name;
		for (int i = 0; i < 4; ++i)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
		std::cout << TERMINAL_GREEN << "\tAssignation operator Character called" << TERMINAL_RESET << std::endl;
	}
	return (*this);
}

// Destructor
Character::~Character()
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	std::cout << TERMINAL_GREEN << "\tDestructor Character called" << TERMINAL_RESET << std::endl;
}

/******************************************************************************/
/*-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-"*/
/*-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._*/
/*-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-"*/
/******************************************************************************/
//	Private methods

int	Character::_whereFreeSlot()
{
	for (int i = 0; i < 4; ++i)
		if (!_inventory[i])
			return (i);
	return (-1);
}

/* ************************************************************************** */
//	Protected methods

/* ************************************************************************** */
//	Public methods

Character::Character(std::string const &name) : _inventoryIndex(0), _name(name)
{
	for (int i = 0; i < 4; ++i)
		this->_inventory[i] = NULL;
	std::cout << TERMINAL_GREEN << "\tConstructor Character with name called" << TERMINAL_RESET << std::endl;
}


const std::string& Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	int _inventoryParser = _whereFreeSlot();
	if (_inventoryParser < 0)
		return ;
	_inventory[_inventoryParser] = m;	// Clone the materia to store it
	std::cout << TERMINAL_YELLOW << _name << " equips " << m->getType() << " at slot " << _inventoryParser + 1 << "th" << TERMINAL_RESET << std::endl;
}

void Character::unequip(int idx)
{
	std::string tmp;

	if (idx < 0 || idx >= 4 || !_inventory[idx])
		return ;
	else
		tmp = _inventory[idx]->getType(), _inventory[idx] = NULL;
	std::cout << TERMINAL_YELLOW << _name << " throws away materia at index " << idx << TERMINAL_RESET << std::endl;
	std::cout << TERMINAL_YELLOW << "It was " << tmp << TERMINAL_RESET << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
		return ;
	_inventory[idx]->use(target);
}

AMateria* Character::getMateriaPtr(int idx) const
{
	if (idx < 0 || idx >= 4)
		return (NULL);
	return (_inventory[idx]);
}