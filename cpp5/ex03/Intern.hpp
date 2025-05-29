/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/05/29 22:56:48 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

# include "../terminal_colors.hpp"
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include <iostream>

class Intern
{
	private:										// Private members
		AForm*	(Intern::*formCreate[3])(std::string const &target) const;
	protected:										// Protected members for inheritance

	public:
		Intern();                                	// Default constructor
		Intern(const Intern &other);         	// Copy constructor
		Intern &operator=(const Intern &other); // Assignment operator
		~Intern();                                	// Destructor

		AForm *makeForm(const std::string &formType, const std::string &target) const;

		AForm* createPresidential(const std::string &target) const;
		AForm* createRobotomy(const std::string &target) const;
		AForm* createShrubbery(const std::string &target) const;
};

#endif // INTERN_HPP
