/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrainedAnimal.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:25:40 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/26 21:14:53 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrainedAnimal.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
BrainedAnimal::BrainedAnimal() : Animal("Default Animal Type"), brain(new Brain())
{
	if (!this->brain) // better pass by try catch sequence next time
	{
		std::cerr << TERMINAL_RED << "\tError: Memory allocation for brain failed" << TERMINAL_RESET << std::endl;
		exit(EXIT_FAILURE); // Exit if memory allocation fails
	}
	std::cout << TERMINAL_GREEN << "\tDefault constructor BrainedAnimal called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
BrainedAnimal::BrainedAnimal(const BrainedAnimal &other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << TERMINAL_GREEN << "\tCopy constructor BrainedAnimal called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
BrainedAnimal &BrainedAnimal::operator=(const BrainedAnimal &other)
{
	if (this != &other)
    {
        type = other.type;
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
		std::cout << TERMINAL_GREEN << "\tAssignation operator BrainedAnimal called" << TERMINAL_RESET << std::endl;
	}
	return (*this);
}

// Destructor
BrainedAnimal::~BrainedAnimal()
{
	if (this->brain)
	{
		delete this->brain; // Free the allocated memory for the brain
		this->brain = NULL; // Set the pointer to nullptr to avoid dangling pointer
	}
	std::cout << TERMINAL_GREEN << "\tDestructor BrainedAnimal called" << TERMINAL_RESET << std::endl;
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

BrainedAnimal::BrainedAnimal(const std::string &type_) : Animal(type_), brain(new Brain()) // Initialize type and allocate memory for the brain)
{
	if (!this->brain) // better pass by try catch sequence next time
	{
		std::cerr << TERMINAL_RED << "\tError: Memory allocation for brain failed" << TERMINAL_RESET << std::endl;
		exit(EXIT_FAILURE); // Exit if memory allocation fails
	}
	std::cout << TERMINAL_GREEN << "\tConstructor BrainedAnimal with type called" << TERMINAL_RESET << std::endl;
}

void BrainedAnimal::initializeIdeas(int power)
{
	if (this->brain)
	{
		this->brain->initializeIdeas(power); // Initialize ideas in the brain
	}
	else
	{
		std::cerr << TERMINAL_RED << "\tError: Brain is not initialized" << TERMINAL_RESET << std::endl;
		exit(EXIT_FAILURE); // Exit if brain is not initialized
	}
}

std::string BrainedAnimal::getIdea(int index) const
{
	return (this->brain->getIdea(index));
}

std::string BrainedAnimal::getType() const
{
	return (this->type);
}
