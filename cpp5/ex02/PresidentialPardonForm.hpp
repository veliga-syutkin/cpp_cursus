/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/05/29 17:37:59 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

# include "../terminal_colors.hpp"
# include "AForm.hpp"
# include <iostream>

class PresidentialPardonForm : public AForm
{
	private:										// Private members

	protected:										// Protected members for inheritance

	public:
		PresidentialPardonForm();                                	// Default constructor
		PresidentialPardonForm(const PresidentialPardonForm &other);         	// Copy constructor
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other); // Assignment operator
		~PresidentialPardonForm();                                	// Destructor

		PresidentialPardonForm(const std::string &target);

		void execute(Bureaucrat const & executor) const; // override; // Execute the form
};

#endif // PRESIDENTIALPARDONFORM_HPP
