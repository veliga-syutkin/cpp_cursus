/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:28:30 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/24 15:10:01 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
ScavTrap::ScavTrap() : ClapTrap("Default ScavTrap")
{
    std::cout << TERMINAL_BOLD_GREEN << "\tDefault constructor Scav called" << TERMINAL_RESET << std::endl;
	this->_hp = 100;
	this->_energy = 50;
	this->_attack_damage = 20;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << TERMINAL_BOLD_GREEN << "\tCopy constructor Scav called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_energy = other._energy;
		this->_attack_damage = other._attack_damage;
		std::cout << TERMINAL_BOLD_GREEN << "\tAssignation operator Scav called" << TERMINAL_RESET << std::endl;
    }
    return *this;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << TERMINAL_BOLD_GREEN << "\tDestructor Scav called" << TERMINAL_RESET << std::endl;
}

//############################################################################//
/* ************************************************************************** */
//	Private methods

/* ************************************************************************** */
//	Protected methods

/* ************************************************************************** */
//	Public methods

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << TERMINAL_BOLD_GREEN << "\tConstructor Scav with name parameter called" << TERMINAL_RESET << std::endl;
	this->_hp = 100;
	this->_energy = 50;
	this->_attack_damage = 20;
}

void ScavTrap::attack(const std::string &target)
{
	if (!isAble())
		return;
	std::cout << TERMINAL_BOLD_YELLOW << "ScavTrap " << _name << " attacks " << target
			  << ", causing " << _attack_damage << " points of damage!" << TERMINAL_RESET << std::endl;
	_energy--;
}

void ScavTrap::guardGate()
{
	if (!isAble())
		return;
	std::cout << TERMINAL_BOLD_CYAN << "ScavTrap " << _name << " is now in Gate Keeper mode!" << TERMINAL_RESET << std::endl;
}