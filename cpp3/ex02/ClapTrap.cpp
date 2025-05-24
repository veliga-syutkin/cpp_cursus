/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:43:31 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/24 20:37:11 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */
//	Canonical Orthodox Form

// Default constructor
ClapTrap::ClapTrap() : _name("Default"), _hp(10), _energy(10), _attack_damage(0)
{
	std::cout << TERMINAL_GREEN << "\tDefault constructor Clap called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hp(other._hp), _energy(other._energy), _attack_damage(other._attack_damage)
{
	std::cout << TERMINAL_GREEN << "\tCopy constructor Clap called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_energy = other._energy;
		this->_attack_damage = other._attack_damage;
		std::cout << TERMINAL_GREEN << "\tAssignation operator Clap called" << TERMINAL_RESET << std::endl;
    }
    return *this;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << TERMINAL_GREEN << "\tDestructor Clap called" << TERMINAL_RESET << std::endl;
}

//############################################################################//
/* ************************************************************************** */
//	Private methods

// Check if ClapTrap is able to perform actions
bool	ClapTrap::isAble()
{
	if (_hp <= 0)
	{
		std::cerr << TERMINAL_RED << "ClapTrap " << _name << " is dead!" << TERMINAL_RESET << std::endl;
		return false;
	}
	if (_energy <= 0)
	{
		std::cerr << TERMINAL_RED << "ClapTrap " << _name << " has no energy!" << TERMINAL_RESET << std::endl;
		return false;
	}
	return true;
}

/* ************************************************************************** */
//	Protected methods

/* ************************************************************************** */
//	Public methods

// Constructor with name parameter
ClapTrap::ClapTrap(const std::string &name) : _name(name), _hp(10), _energy(10), _attack_damage(0)
{
	std::cout << TERMINAL_GREEN << "\tConstructor Clap with name parameter called" << TERMINAL_RESET << std::endl;
}

// Attack method
void	ClapTrap::attack(const std::string &target)
{
	if (isAble())
	{
		std::cout << TERMINAL_CYAN << "ClapTrap " << _name << " attacks " << target 
			<< ", causing " << _attack_damage << " points of damage!" << TERMINAL_RESET << std::endl;
		_energy--;
	}
}

// Take damage method
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > _hp)
	{
		_hp = 0;
		std::cout << TERMINAL_YELLOW << "ClapTrap " << _name << " has taken too much damage and is now dead!" << TERMINAL_RESET << std::endl;
	}
	else
	{
		_hp -= amount;
		std::cout << TERMINAL_YELLOW << "ClapTrap " << _name << " takes " << amount 
				  << " points of damage! Remaining HP: " << _hp << TERMINAL_RESET << std::endl;
	}
}

// Repair (aka heal) method
void	ClapTrap::beRepaired(unsigned int amount)
{
	unsigned long int	temp;

	if (isAble())
	{
		temp = static_cast<unsigned long int>(_hp) + amount;
		if (temp > UINT_MAX)
			_hp = UINT_MAX;
		else
			_hp += amount;
		std::cout << TERMINAL_GREEN << "ClapTrap " << _name << " repairs itself for " 
			<< amount << " points! New HP: " << _hp << TERMINAL_RESET << std::endl;
		_energy--;
	}
}
