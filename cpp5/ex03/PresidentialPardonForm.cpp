/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:15:22 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/29 22:15:24 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("Presidential Pardon Form", 25, 5) 
{
	std::cout << TERMINAL_GREEN << "\tDefault constructor PresidentialPardonForm called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other)
{
	std::cout << TERMINAL_GREEN << "\tCopy constructor PresidentialPardonForm called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other); // Call the base class assignment operator
		std::cout << TERMINAL_GREEN << "\tAssignation operator PresidentialPardonForm called" << TERMINAL_RESET << std::endl;
	}
	return (*this);
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << TERMINAL_GREEN << "\tDestructor PresidentialPardonForm called" << TERMINAL_RESET << std::endl;
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

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("Presidential Pardon Form for " + target, 25, 5)
{
	std::cout << TERMINAL_GREEN << "\tParameterized constructor PresidentialPardonForm called" << TERMINAL_RESET << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	execCheck(executor);
	std::cout << TERMINAL_YELLOW << this->getName() << " has been pardoned by Zaphod Beeblebrox." << TERMINAL_RESET << std::endl;
}
