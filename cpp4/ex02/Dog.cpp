/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:24:15 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/26 20:54:03 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
Dog::Dog() : BrainedAnimal("Dog")
{
	initializeIdeas(10); // Initialize ideas with a power of 1
	std::cout << TERMINAL_GREEN << "\tDefault constructor Dog called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
Dog::Dog(const Dog &other) : BrainedAnimal(other) // Call the base class copy constructor
{
	std::cout << TERMINAL_GREEN << "\tCopy constructor Dog called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		BrainedAnimal::operator=(other); // Call the base class assignment operator
		std::cout << TERMINAL_GREEN << "\tAssignation operator Dog called" << TERMINAL_RESET << std::endl;
	}
	return *this;
}

// Destructor
Dog::~Dog()
{
	std::cout << TERMINAL_GREEN << "\tDestructor Dog called" << TERMINAL_RESET << std::endl;
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

void Dog::makeSound() const
{
	std::cout << TERMINAL_YELLOW << BARK << TERMINAL_RESET << std::endl;
}