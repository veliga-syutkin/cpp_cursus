/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:34:51 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/29 22:34:53 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
AForm::AForm() : _name("Default AForm"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << TERMINAL_GREEN << "\tDefault constructor AForm called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
	std::cout << TERMINAL_GREEN << "\tCopy constructor AForm called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		// Note: _name, _gradeToSign, and _gradeToExec are const, so they cannot be assigned.
		_signed = other._signed; // Only _signed can be assigned
		std::cout << TERMINAL_GREEN << "\tAssignation operator AForm called" << TERMINAL_RESET << std::endl;
	}
	return (*this);
}

// Destructor
AForm::~AForm()
{
	std::cout << TERMINAL_GREEN << "\tDestructor AForm called" << TERMINAL_RESET << std::endl;
}

/******************************************************************************/
/*-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-"*/
/*-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._*/
/*-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-"*/
/******************************************************************************/
//	Private methods

/* ************************************************************************** */
//	Protected methods

void	AForm::execCheck(Bureaucrat const &executor) const
{
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExec)
		throw FormExecGradeTooLowException();
}

/* ************************************************************************** */
//	Public methods

AForm::AForm(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExec)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw FormCreateGradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw FormCreateGradeTooLowException();
	std::cout << TERMINAL_GREEN << "\tParameterized constructor AForm called" << TERMINAL_RESET << std::endl;
}

const std::string &AForm::getName() const
{
	return (_name);
}

std::string AForm::isSigned() const
{
	if (_signed)
		return (SIGNED_TRUE);
	else
		return (SIGNED_FALSE);
}

unsigned int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

unsigned int AForm::getGradeToExec() const
{
	return (_gradeToExec);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw FormSignGradeTooLowException();
	_signed = true;
	std::cout << TERMINAL_GREEN << "\tAForm " << _name << " signed by " << bureaucrat.getName() << TERMINAL_RESET << std::endl;
}

std::ostream& operator<<(std::ostream &os, const AForm &AForm)
{
	os << "AForm Name: " << AForm.getName() << ", Status: " << AForm.isSigned()
	   << ", Grade to Sign: " << AForm.getGradeToSign()
	   << ", Grade to Execute: " << AForm.getGradeToExec();
	return os;
}

bool	AForm::getSigned() const
{
	return (_signed);
}