/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:08:20 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/24 18:16:39 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
DiamondTrap::DiamondTrap() : ClapTrap("DefaultDiamond_clap_name"), FragTrap(), ScavTrap() // Initialize ClapTrap with the name suffixed by "_clap_name"
{
	std::cout << TERMINAL_BOLD_YELLOW << "\tDefault constructor DiamondTrap called" << TERMINAL_RESET << std::endl;
	this->_name = "DefaultDiamond";
	this->_hp = FragTrap::_hp;
	this->_energy = ScavTrap::_energy;
	this->_attack_damage = FragTrap::_attack_damage;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other._name + "_clap_name"), FragTrap(other), ScavTrap(other._name) // Initialize ClapTrap with the name suffixed by "_clap_name"
{
	std::cout << TERMINAL_BOLD_YELLOW << "\tCopy constructor DiamondTrap called" << TERMINAL_RESET << std::endl;
	this->_name = other._name; // DiamondTrap's name
	this->_hp = other._hp; // FragTrap's HP
	this->_energy = other._energy; // ScavTrap's energy
	this->_attack_damage = other._attack_damage; // FragTrap's attack damage
}

// Assignment logic
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name; // DiamondTrap's name
		this->_hp = other._hp; // FragTrap's HP
		this->_energy = other._energy; // ScavTrap's energy
		this->_attack_damage = other._attack_damage; // FragTrap's attack damage
		std::cout << TERMINAL_BOLD_YELLOW << "\tAssignation operator DiamondTrap called" << TERMINAL_RESET << std::endl;
	}
	return *this;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << TERMINAL_BOLD_YELLOW << "\tDestructor DiamondTrap called" << TERMINAL_RESET << std::endl;
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

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap() // Initialize ClapTrap with the name suffixed by "_clap_name"
{
	this->_name = name;
	this->_hp = FragTrap::_hp;
	this->_energy = ScavTrap::_energy;
	this->_attack_damage = FragTrap::_attack_damage;
	std::cout << TERMINAL_BOLD_YELLOW << "\tConstructor DiamondTrap with name called: " << name << TERMINAL_RESET << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << TERMINAL_BOLD_YELLOW << "I am " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << TERMINAL_RESET << std::endl;
}
