/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 01:04:27 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/07 02:30:37 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Constructor
HumanB::HumanB(std::string name) : Human(name)
{
	;
}

HumanB::HumanB(std::string name, Weapon &weapon) : Human(name, weapon)
{
	;
}

//Destructor
HumanB::~HumanB()
{
	;
}

/* ************************************************************************** */
// Private methods

/* ************************************************************************** */
// Public methods

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}