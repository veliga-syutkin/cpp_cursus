/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:55:28 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/24 16:59:34 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
FragTrap::FragTrap() : ClapTrap("Default FragTrap")
{
	std::cout << TERMINAL_BOLD_MAGENTA << "\tDefault constructor Frag called" << TERMINAL_RESET << std::endl;
	this->_hp = 100;
	this->_energy = 100;
	this->_attack_damage = 30;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << TERMINAL_BOLD_MAGENTA << "\tCopy constructor Frag called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_energy = other._energy;
		this->_attack_damage = other._attack_damage;
		std::cout << TERMINAL_BOLD_MAGENTA << "\tAssignation operator Frag called" << TERMINAL_RESET << std::endl;
	}
	return *this;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << TERMINAL_BOLD_MAGENTA << "\tDestructor Frag called" << TERMINAL_RESET << std::endl;
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

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << TERMINAL_BOLD_MAGENTA << "\tConstructor Frag with name called" << TERMINAL_RESET << std::endl;
	this->_hp = 100;
	this->_energy = 100;
	this->_attack_damage = 30;
}

void FragTrap::highFivesGuys()
{
	if (!isAble())
		return;
	std::cout << TERMINAL_BOLD_MAGENTA << "FragTrap " << _name << " requests a high five!" << TERMINAL_RESET << std::endl;
}