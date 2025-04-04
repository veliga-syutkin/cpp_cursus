/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 05:14:11 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/04 15:26:42 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor
Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Zombie " << _name << " created." << std::endl;
}

// Default constructor
Zombie::Zombie()
{
	std::cout << "Nameless zombie created." << std::endl;
};

// Destructor
Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " destroyed." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _name << ": " << zombieSay << std::endl;
}

/* ************************************************************************** */
// Private methods

/* ************************************************************************** */
// Public methods

void Zombie::setName(std::string name)
{
	_name = name;
}

// std::string Zombie::getName(std::string name)
// {

// }
