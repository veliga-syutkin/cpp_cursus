/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:18:28 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/29 22:37:00 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request Form", 72, 45) // Initialize with specific name and grades
{
	std::cout << TERMINAL_GREEN << "\tDefault constructor RobotomyRequestForm called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other) // Call the base class copy constructor
{
	std::cout << TERMINAL_GREEN << "\tCopy constructor RobotomyRequestForm called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other); // Call the base class assignment operator
		std::cout << TERMINAL_GREEN << "\tAssignation operator RobotomyRequestForm called" << TERMINAL_RESET << std::endl;
	}
	return (*this);
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << TERMINAL_GREEN << "\tDestructor RobotomyRequestForm called" << TERMINAL_RESET << std::endl;
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

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("Robotomy Request Form for " + target, 72, 45) // Initialize with target
{
	std::cout << TERMINAL_GREEN << "\tParameterized constructor RobotomyRequestForm called for target: " << target << TERMINAL_RESET << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	execCheck(executor); // Check if the form can be executed

	// Simulate a 50% chance of success
	std::srand(std::time(0));
	if (rand() % 2 == 0)
	{
		std::cout << TERMINAL_YELLOW << "Bzzzzzz... " << getName() << " has been robotomized successfully!" << TERMINAL_RESET << std::endl;
	}
	else
	{
		std::cout << TERMINAL_RED << "Robotomy failed for " << getName() << "." << TERMINAL_RESET << std::endl;
	}
}
