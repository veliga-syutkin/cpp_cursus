/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/05/29 17:37:59 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

# include "../terminal_colors.hpp"
# include "AForm.hpp"
# include <iostream>
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
	private:										// Private members

	protected:										// Protected members for inheritance

	public:
		RobotomyRequestForm();                                	// Default constructor
		RobotomyRequestForm(const RobotomyRequestForm &other);         	// Copy constructor
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other); // Assignment operator
		~RobotomyRequestForm();                                	// Destructor

		RobotomyRequestForm(const std::string &target);

		void execute(Bureaucrat const & executor) const; // override; // Execute the form
};

#endif // ROBOTOMYREQUESTFORM_HPP
