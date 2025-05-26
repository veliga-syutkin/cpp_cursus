/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:24:04 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/26 20:53:53 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
Cat::Cat() : BrainedAnimal("Cat")
{
	initializeIdeas(1);
	std::cout << TERMINAL_GREEN << "\tDefault constructor Cat called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
Cat::Cat(const Cat &other) : BrainedAnimal(other) // Call the base class copy constructor
{
	std::cout << TERMINAL_GREEN << "\tCopy constructor Cat called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		BrainedAnimal::operator=(other); // Call the base class assignment operator
		std::cout << TERMINAL_GREEN << "\tAssignation operator Cat called" << TERMINAL_RESET << std::endl;
	}
	return *this;
}

// Destructor
Cat::~Cat()
{
	std::cout << TERMINAL_GREEN << "\tDestructor Cat called" << TERMINAL_RESET << std::endl;
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

void Cat::makeSound() const
{
	std::cout << TERMINAL_BOLD_WHITE << MEOW << TERMINAL_RESET << std::endl;
}