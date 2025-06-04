/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/05/29 17:37:36 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
# include <fstream>
# include <cstdlib>
# include <ctime>

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation Form", 145, 137) // Initialize with specific name and grades
{
	std::cout << TERMINAL_GREEN << "\tDefault constructor ShrubberyCreationForm called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other) // Call the base class copy constructor
{
	std::cout << TERMINAL_GREEN << "\tCopy constructor ShrubberyCreationForm called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other); // Call the base class assignment operator
		std::cout << TERMINAL_GREEN << "\tAssignation operator ShrubberyCreationForm called" << TERMINAL_RESET << std::endl;
	}
	return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << TERMINAL_GREEN << "\tDestructor ShrubberyCreationForm called" << TERMINAL_RESET << std::endl;
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

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm(target, 145, 137) // Initialize with specific name and grades
{
	std::cout << TERMINAL_GREEN << "\tConstructor ShrubberyCreationForm called with target: " << target << TERMINAL_RESET << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	execCheck(executor); // Check if the executor can execute the form

	std::ofstream ofs((getName() + "_shrubbery").c_str());
	if (!ofs.is_open())
		throw std::runtime_error("Failed to open file for writing");
	std::srand(std::time(0));
	for (int i = 0; i < (rand() % 10); i++)
	{
		ofs << "        _-_\n"
			<< "     /~~   ~~\\\n"
			<< "   /~~         ~~\\\n"
			<< "  {               }\n"
			<< "   \\  _-_-_-_-_  /\n"
			<< "     ~~~~~~~~~~~\n";
	}
	ofs.close();
	std::cout << TERMINAL_GREEN << "Shrubbery created successfully!" << TERMINAL_RESET << std::endl;
}