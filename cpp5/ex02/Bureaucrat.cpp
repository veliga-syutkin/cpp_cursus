/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   Bureaucrat.cpp									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/29 12:55:26 by vsyutkin		  #+#	#+#			 */
/*   Updated: 2025/05/29 14:33:21 by vsyutkin		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\	 	/####| |##########| |##| |#####| |__###########\	 /######@ */
/* @#####|_	 	_|###| |##########| |##| |#####|  __|#########|_	 _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
Bureaucrat::Bureaucrat() : _name("Default Bureaucrat"), _grade(150), _gradeClassified(0)
{
	std::cout << TERMINAL_GREEN << "\tDefault constructor Bureaucrat called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) :  _name(other._name), _grade(other._grade), _gradeClassified(other._gradeClassified)
{
	std::cout << TERMINAL_GREEN << "\tCopy constructor Bureaucrat called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		// Note: _name is const, so it cannot be assigned
		_grade = other._grade; 
		_gradeClassified = other._gradeClassified;
		std::cout << TERMINAL_GREEN << "\tAssignation operator Bureaucrat called" << TERMINAL_RESET << std::endl;
	}
	return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << TERMINAL_GREEN << "\tDestructor Bureaucrat called" << TERMINAL_RESET << std::endl;
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

Bureaucrat::Bureaucrat(const std::string &name, short unsigned int grade) : _name(name), _grade(grade), _gradeClassified((grade-150)*-1)
{
	std::cout << TERMINAL_GREEN << "\tParameterized constructor Bureaucrat called" << TERMINAL_RESET << std::endl;
	if (_gradeClassified > MAX_CLASSIFIED_GRADE)
		throw BureaucratGradeTooHighException();
	if (_gradeClassified < MIN_CLASSIFIED_GRADE)
		throw BureaucratGradeTooLowException();
}

const std::string &Bureaucrat::getName() const
{
	return (_name);
}

const short int &Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::promote()
{
	if (_gradeClassified == MAX_CLASSIFIED_GRADE)
		throw BureaucratGradeTooHighException();
	_gradeClassified++;
	_grade--;
}

void	Bureaucrat::demote()
{
	if(_gradeClassified == MIN_CLASSIFIED_GRADE)
		throw BureaucratGradeTooLowException();
	_gradeClassified--;
	_grade++;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << " ";
	return os;
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << TERMINAL_GREEN << this->getName() << " signed " << form.getName() << TERMINAL_RESET << std::endl;
	}
	catch (const FormSignGradeTooLowException &e)
	{
		std::cerr << TERMINAL_RED 
			<< this->getName() << " couldn't sign " << form.getName() 
			<< " because their grade is too low: " << this->getGrade()
			<< " (required: " << form.getGradeToSign() << ")\n"
			<< TERMINAL_RESET << "Additionnal info: "
			<< e.what() << TERMINAL_RESET << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << TERMINAL_GREEN << this->getName() << " executed " << form.getName() << TERMINAL_RESET << std::endl;
	}
	catch (const FormExecGradeTooLowException &e)
	{
		std::cerr << TERMINAL_RED 
			<< this->getName() << " couldn't execute " << form.getName() 
			<< " because their grade is too low: " << this->getGrade()
			<< " (required: " << form.getGradeToExec() << ")\n"
			<< TERMINAL_RESET << "Additionnal info: "
			<< e.what() << TERMINAL_RESET << std::endl;
	}
}
