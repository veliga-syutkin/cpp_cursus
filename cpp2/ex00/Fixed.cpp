/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:45:51 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/10 13:31:46 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/* ************************************************************************** */
// Canonical Orthodox Form

// Default constructor
Fixed::Fixed() : _value(0)
{
    std::cout << TERMINAL_GREEN << "\tDefault constructor called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other) : _value(other._value)
{
	std::cout << TERMINAL_GREEN << "\tCopy constructor called" << TERMINAL_RESET << std::endl;
}

// Assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << TERMINAL_GREEN << "\tAssignation operator called" << TERMINAL_RESET << std::endl;
    if (this != &other) {
        // Assignment logic
		this->_value = other._value;
    }
    return *this;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << TERMINAL_GREEN << "\tDestructor called" << TERMINAL_RESET << std::endl;
}

//############################################################################//
/* ************************************************************************** */
// Private methods

/* ************************************************************************** */
// Protected methods

/* ************************************************************************** */
// Public methods

int	Fixed::getRawBits(void) const
{
	std::cout << TERMINAL_GREEN << "\tgetRawBits called" << TERMINAL_RESET << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << TERMINAL_GREEN << "\tsetRawBits called" << TERMINAL_RESET << std::endl;
	this->_value = raw;
}
