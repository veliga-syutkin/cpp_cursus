/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 23:47:19 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/07 02:32:52 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

// Constructor
Human::Human()
{
	;
}

// Destructor
Human::~Human()
{
	;
}

/* ************************************************************************** */
// Private methods

Human::Human(const std::string name, Weapon &weapon) : _name(name), _weapon(&weapon)
{
	;
}

Human::Human(const std::string name) : _name(name), _weapon(NULL)
{
	;
}

/* ************************************************************************** */
// Public methods

const std::string &Human::getName() const
{
	return (_name);
}

void Human::setName(std::string name)
{
	this->_name = name;
}

void Human::attack()
{
	if (_weapon)
		std::cout << this->getName() << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << this->getName() << " has nothing to attack with, so he goes sleep." << std::endl;
}

void Human::setWeapon(Weapon *weapon)
{
	_weapon = weapon;
}
