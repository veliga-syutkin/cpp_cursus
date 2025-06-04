/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExceptionsCPP5.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:41:14 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/04 10:04:34 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONSCPP5_HPP
#define EXCEPTIONSCPP5_HPP

# include "../terminal_colors.hpp"
# include <iostream>
# include <exception>

class ExceptionsCPP5 : public std::exception
{
	private:										// Private members

	protected:										// Protected members for inheritance
		std::string	_msg;

	public:
		// ExceptionsCPP5();                                	// Default constructor
		// ExceptionsCPP5(const ExceptionsCPP5 &other);         	// Copy constructor
		// ExceptionsCPP5 &operator=(const ExceptionsCPP5 &other); // Ommitted in exception class
		~ExceptionsCPP5() throw ();                                		// Destructor

		ExceptionsCPP5(const std::string &msg);                                	// Default constructor

		const char* what() const throw();
		// c++11: `virtual const char* what() const noexcept override = 0;`
};

class	BureaucratException : public ExceptionsCPP5
{
	public:
		BureaucratException(const std::string &msg); // Constructor with message
};

class	BureaucratGradeTooHighException : public BureaucratException
{
	public:
		BureaucratGradeTooHighException();
};

class	BureaucratGradeTooLowException : public BureaucratException
{
	public:
		BureaucratGradeTooLowException();
};

class	FormException : public ExceptionsCPP5
{
	public:
		FormException(const std::string &msg); // Constructor with message
};

class	FormSignGradeTooLowException : public FormException
{
	public:
		FormSignGradeTooLowException();
};

// class	FormExecGradeTooLowException : public FormException
// {
// 	public:
// 		FormExecGradeTooLowException();
// };

class	FormCreateGradeTooLowException : public FormException
{
	public:
		FormCreateGradeTooLowException();
};

class	FormCreateGradeTooHighException : public FormException
{
	public:
		FormCreateGradeTooHighException();
};


#endif // EXCEPTIONSCPP5_HPP
