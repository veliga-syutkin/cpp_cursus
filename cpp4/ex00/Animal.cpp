/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:42:11 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/26 16:36:58 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
Animal::Animal() : type("Default Animal Type")
{
	std::cout << TERMINAL_GREEN << "\tDefault constructor Animal called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
Animal::Animal(const Animal &other) : type(other.type) // Copy the type from the other Animal
{
	std::cout << TERMINAL_GREEN << "\tCopy constructor Animal called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->type = other.type; // Copy the type from the other Animal
		std::cout << TERMINAL_GREEN << "\tAssignation operator Animal called" << TERMINAL_RESET << std::endl;
	}
	return *this;
}

// Destructor
Animal::~Animal()
{
	std::cout << TERMINAL_GREEN << "\tDestructor Animal called" << TERMINAL_RESET << std::endl;
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

Animal::Animal(const std::string &type_) : type(type_)
{
	std::cout << TERMINAL_GREEN << "\tConstructor Animal with type called" << TERMINAL_RESET << std::endl;
}

void Animal::makeSound() const
{
	std::cout << TERMINAL_RED << "\tDefault animal sound(TM)" << TERMINAL_RESET << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}
