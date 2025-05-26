/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:42:11 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/26 17:44:31 by vsyutkin         ###   ########.fr       */
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
Animal::Animal() : type("Default Animal Type"), brain(new Brain())
{
	if (!this->brain) // better pass by try catch sequence next time
	{
		std::cerr << TERMINAL_RED << "\tError: Memory allocation for brain failed" << TERMINAL_RESET << std::endl;
		exit(EXIT_FAILURE); // Exit if memory allocation fails
	}
	std::cout << TERMINAL_GREEN << "\tDefault constructor Animal called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
Animal::Animal(const Animal &other) : type(other.type), brain(new Brain(*other.brain))
{
	std::cout << TERMINAL_GREEN << "\tCopy constructor Animal called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        type = other.type;
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
        std::cout << TERMINAL_GREEN << "\tAssignation operator Animal called" << TERMINAL_RESET << std::endl;
    }
    return *this;
}

// Destructor
Animal::~Animal()
{
	if (this->brain)
	{
		delete this->brain; // Free the allocated memory for the brain
		this->brain = NULL; // Set the pointer to nullptr to avoid dangling pointer
	}
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

Animal::Animal(const std::string &type_) : type(type_), brain(new Brain()) // Initialize type and allocate memory for the brain
{
	if (!this->brain) // better pass by try catch sequence next time
	{
		std::cerr << TERMINAL_RED << "\tError: Memory allocation for brain failed" << TERMINAL_RESET << std::endl;
		exit(EXIT_FAILURE); // Exit if memory allocation fails
	}
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

std::string Animal::getIdea(int index) const
{
	return (this->brain->getIdea(index));
}
