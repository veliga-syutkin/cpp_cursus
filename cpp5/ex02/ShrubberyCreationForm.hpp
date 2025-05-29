/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/05/29 17:37:36 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

# include "../terminal_colors.hpp"
# include "AForm.hpp"
# include <fstream>
# include <iostream>

class ShrubberyCreationForm : public AForm
{
	private:										// Private members

	protected:										// Protected members for inheritance

	public:
		ShrubberyCreationForm();                                	// Default constructor
		ShrubberyCreationForm(const ShrubberyCreationForm &other);         	// Copy constructor
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other); // Assignment operator
		~ShrubberyCreationForm();                                	// Destructor

		ShrubberyCreationForm(const std::string &target);

		void execute(Bureaucrat const & executor) const; // override; // Execute the form
};

#endif // SHRUBBERYCREATIONFORM_HPP
