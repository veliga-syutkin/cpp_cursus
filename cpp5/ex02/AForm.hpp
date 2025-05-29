/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:15:26 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/29 22:28:11 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

# include "Bureaucrat.hpp"

# define SIGNED_TRUE "Signed :D"
# define SIGNED_FALSE "Not signed :c"

class Bureaucrat; // Forward declaration of Bureaucrat class

class AForm
{
	private:										// Private members
		const std::string	_name;
		bool				_signed;
		const short int		_gradeToSign;
		const short int		_gradeToExec;

	protected:						 				// Protected members for inheritance
		void	execCheck(Bureaucrat const & executor) const;

	public:
		AForm();                                	// Default constructor
		AForm(const AForm &other);         	// Copy constructor
		AForm &operator=(const AForm &other); // Assignment operator
		~AForm();                                	// Destructor

		AForm(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExec);
		const std::string &getName() const;      // Get the name of the AForm
		bool getSigned() const;
		std::string isSigned() const;   // Check if the AForm is signed
		unsigned int getGradeToSign() const;    // Get the grade required to sign the AForm
		unsigned int getGradeToExec() const;    // Get the grade required to execute the AForm

		void beSigned(const Bureaucrat &bureaucrat); // Sign the AForm by a bureaucrat

		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream &os, const AForm &AForm);

#endif // AForm_HPP
