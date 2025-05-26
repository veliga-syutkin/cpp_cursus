/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:00:58 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/26 21:08:36 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <sstream>

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
Brain::Brain()
{
	std::cout << TERMINAL_GREEN << "\tDefault constructor Brain called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; ++i)
	{
		this->_ideas[i] = other._ideas[i]; // Copy each idea from the other Brain
	}
	std::cout << TERMINAL_GREEN << "\tCopy constructor Brain called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
		{
			this->_ideas[i] = other._ideas[i]; // Copy each idea from the other Brain
		}
		std::cout << TERMINAL_GREEN << "\tAssignation operator Brain called" << TERMINAL_RESET << std::endl;
	}
	return (*this);
}

// Destructor
Brain::~Brain()
{
	std::cout << TERMINAL_GREEN << "\tDestructor Brain called" << TERMINAL_RESET << std::endl;
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

void Brain::initializeIdeas(int power)
{
	for (int i = 0; i < 100; ++i)
	{
		std::ostringstream oss;
		oss << (1000 * power - 7 * power * i);
		this->_ideas[i] = oss.str();
	}
	std::cout << TERMINAL_GREEN << "\tBrain ideas initialized" << TERMINAL_RESET << std::endl;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
	return ("");
	return (_ideas[index]);
}