/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/05/29 16:04:39 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
Form::Form() : _name("Default Form"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << TERMINAL_GREEN << "\tDefault constructor Form called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
	std::cout << TERMINAL_GREEN << "\tCopy constructor Form called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		// Note: _name, _gradeToSign, and _gradeToExec are const, so they cannot be assigned.
		_signed = other._signed; // Only _signed can be assigned
		std::cout << TERMINAL_GREEN << "\tAssignation operator Form called" << TERMINAL_RESET << std::endl;
	}
	return (*this);
}

// Destructor
Form::~Form()
{
	std::cout << TERMINAL_GREEN << "\tDestructor Form called" << TERMINAL_RESET << std::endl;
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

Form::Form(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExec)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw FormCreateGradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw FormCreateGradeTooLowException();
	std::cout << TERMINAL_GREEN << "\tParameterized constructor Form called" << TERMINAL_RESET << std::endl;
}

const std::string &Form::getName() const
{
	return (_name);
}

std::string Form::isSigned() const
{
	if (_signed)
		return (SIGNED_TRUE);
	else
		return (SIGNED_FALSE);
}

unsigned int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

unsigned int Form::getGradeToExec() const
{
	return (_gradeToExec);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw FormSignGradeTooLowException();
	_signed = true;
	std::cout << TERMINAL_GREEN << "\tForm " << _name << " signed by " << bureaucrat.getName() << TERMINAL_RESET << std::endl;
}

std::ostream& operator<<(std::ostream &os, const Form &form)
{
	os << "Form Name: " << form.getName() << ", Status: " << form.isSigned()
	   << ", Grade to Sign: " << form.getGradeToSign()
	   << ", Grade to Execute: " << form.getGradeToExec();
	return os;
}