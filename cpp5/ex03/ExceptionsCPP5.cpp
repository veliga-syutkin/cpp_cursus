/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExceptionsCPP5.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:41:08 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/05/29 22:03:33 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ExceptionsCPP5.hpp"

// ExceptionsCPP5::~ExceptionsCPP5() {};

ExceptionsCPP5::ExceptionsCPP5(const std::string &msg) : _msg(msg) {};

const char *ExceptionsCPP5::what() const throw()
{
	return (_msg.c_str());
}

BureaucratGradeTooHighException::BureaucratGradeTooHighException() : BureaucratException("Bureaucrat grade too high") {};

BureaucratGradeTooLowException::BureaucratGradeTooLowException() : BureaucratException("Bureaucrat grade too low") {};

FormCreateGradeTooHighException::FormCreateGradeTooHighException() 
	: FormException("Form creation grade is too high") {};

FormCreateGradeTooLowException::FormCreateGradeTooLowException() 
	: FormException("Form creation grade is too low") {};

FormSignGradeTooLowException::FormSignGradeTooLowException() 
	: FormException("Bureaucrat's grade attempting so sign this form is too low") {};

FormExecGradeTooLowException::FormExecGradeTooLowException() 
	: FormException("Bureaucrat's grade attempting to execute this form is too low") {};

FormNotSignedException::FormNotSignedException() 
	: FormException("Form is not signed") {};