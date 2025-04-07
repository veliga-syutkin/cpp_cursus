/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:39:11 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/07 01:33:09 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Constructor
Weapon::Weapon()
{
	_type = "no weapon";
}

// Destructor
Weapon::~Weapon()
{
	;
}

// Private methods

// Public methods
const std::string &Weapon::getType() const
{
	return (_type);
}

void Weapon::setType(const std::string type)
{
	this->_type = type;
}

Weapon::Weapon(const std::string type) : _type(type)
{
	;
}
