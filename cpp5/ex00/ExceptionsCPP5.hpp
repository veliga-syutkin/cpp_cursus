/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExceptionsCPP5.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:41:14 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/04 10:02:50 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONSCPP5_HPP
#define EXCEPTIONSCPP5_HPP

# include "../terminal_colors.hpp"
# include <exception>
# include <iostream>

class ExceptionsCPP5 : public std::exception
{
	private:										// Private members
		std::string	_msg;
	protected:										// Protected members for inheritance

	public:
		// ExceptionsCPP5();                                	// Default constructor
		// ExceptionsCPP5(const ExceptionsCPP5 &other);         	// Copy constructor
		// ExceptionsCPP5 &operator=(const ExceptionsCPP5 &other); // Ommitted in exception class
		~ExceptionsCPP5() throw ();                                		// Destructor

		ExceptionsCPP5(const std::string &msg);                                	// Default constructor

		const char* what() const throw();
		// c++11: `virtual const char* what() const noexcept override = 0;`
};

class	BureaucratGradeTooHighException : public ExceptionsCPP5
{
	public:
		BureaucratGradeTooHighException();
};

class	BureaucratGradeTooLowException : public ExceptionsCPP5
{
	public:
		BureaucratGradeTooLowException();
};

#endif // EXCEPTIONSCPP5_HPP
