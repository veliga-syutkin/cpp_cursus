/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExceptionsCPP5.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:41:08 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/04 10:12:06 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ExceptionsCPP5.hpp"

ExceptionsCPP5::~ExceptionsCPP5() throw() {};

ExceptionsCPP5::ExceptionsCPP5(const std::string &msg) : _msg(msg) {};

const char *ExceptionsCPP5::what() const throw()
{
	return (_msg.c_str());
}

BureaucratGradeTooHighException::BureaucratGradeTooHighException() : ExceptionsCPP5("Bureaucrat grade too high") {};

BureaucratGradeTooLowException::BureaucratGradeTooLowException() : ExceptionsCPP5("Bureaucrat grade too low") {};