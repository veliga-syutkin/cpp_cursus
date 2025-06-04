/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>                            */
/*                                                                            */
/*   Created: 2025/05/29 16:04:39 by vsyutkin                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include "Bureaucrat.hpp"
# include "ExceptionsCPP5.hpp"

# define SIGNED_TRUE "Signed :D"
# define SIGNED_FALSE "Not signed :c"

class FormException; // Forward declaration of FormException class

class Bureaucrat; // Forward declaration of Bureaucrat class

class Form
{
	private:										// Private members
		const std::string	_name;
		bool				_signed;
		const short int		_gradeToSign;
		const short int		_gradeToExec;
	protected:										// Protected members for inheritance

	public:
		Form();                                	// Default constructor
		Form(const Form &other);         	// Copy constructor
		Form &operator=(const Form &other); // Assignment operator
		~Form();                                	// Destructor

		Form(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExec);
		const std::string &getName() const;      // Get the name of the form
		std::string isSigned() const;   // Check if the form is signed
		unsigned int getGradeToSign() const;    // Get the grade required to sign the form
		unsigned int getGradeToExec() const;    // Get the grade required to execute the form

		void beSigned(const Bureaucrat &bureaucrat); // Sign the form by a bureaucrat
};

std::ostream& operator<<(std::ostream &os, const Form &form);

#endif // FORM_HPP
