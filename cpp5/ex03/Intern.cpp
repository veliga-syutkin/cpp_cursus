/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/05/29 22:56:48 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
Intern::Intern() 
{
	this->formCreate[0] = &Intern::createPresidential;
	this->formCreate[1] = &Intern::createRobotomy;
	this->formCreate[2] = &Intern::createShrubbery;
	std::cout << TERMINAL_GREEN << "\tDefault constructor Intern called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
Intern::Intern(const Intern &other)
{
	for (int i = 0; i < 3; ++i)
	{
		this->formCreate[i] = other.formCreate[i]; // Copy function pointers
	}
	std::cout << TERMINAL_GREEN << "\tCopy constructor Intern called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 3; ++i)
		{
			this->formCreate[i] = other.formCreate[i]; // Copy function pointers
		}
		std::cout << TERMINAL_GREEN << "\tAssignation operator Intern called" << TERMINAL_RESET << std::endl;
	}
	return (*this);
}

// Destructor
Intern::~Intern()
{
	std::cout << TERMINAL_GREEN << "\tDestructor Intern called" << TERMINAL_RESET << std::endl;
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

AForm* Intern::createPresidential(const std::string &target) const
{
    std::cout << "Intern creates Presidential Pardon Form" << std::endl;
    return new PresidentialPardonForm(target);
}
AForm* Intern::createRobotomy(const std::string &target) const
{
    std::cout << "Intern creates Robotomy Request Form" << std::endl;
    return new RobotomyRequestForm(target);
}
AForm* Intern::createShrubbery(const std::string &target) const
{
    std::cout << "Intern creates Shrubbery Creation Form" << target << std::endl;
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string &formType, const std::string &target) const
{
    static const std::string names[3] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };
    for (int i = 0; i < 3; ++i)
    {
        if (formType == names[i])
        {
            return (this->*formCreate[i])(target);
        }
    }
    std::cout << "Unknown form type: " << formType << std::endl;
    return NULL;
}