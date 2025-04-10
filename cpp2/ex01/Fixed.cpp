/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:45:51 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/10 23:03:19 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <climits>
#include <cmath>

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

Fixed::Fixed(const int value) : _value(value * 256) // 256 = 2 ^ 8 as in _frac_bits
{
	std::cout << TERMINAL_GREEN << "\tInt constructor called" << TERMINAL_RESET << std::endl;
	long tmp = (long)value * (long)256;
	if (tmp > INT_MAX || tmp < INT_MIN) // good practice
	{
		std::cerr << TERMINAL_RED << "\tInt constructor: value out of range" << TERMINAL_RESET << std::endl;
		throw std::overflow_error("Int constructor: value out of range");
	}
}

Fixed::Fixed(const float value)
{
	std::cout << TERMINAL_GREEN << "\tFloat constructor called" << TERMINAL_RESET << std::endl;
	double tmp = (double)roundf((double)value * (double)256); // 256 = 2 ^ 8 as in _frac_bits
	if (tmp > INT_MAX || tmp < INT_MIN) // good practice
	{
		std::cerr << TERMINAL_RED << "\tFloat constructor: value out of range" << TERMINAL_RESET << std::endl;
		throw std::overflow_error("Float constructor: value out of range");
	}
	this->_value = static_cast<int>(tmp);
}

float	Fixed::toFloat(void) const
{
	std::cout << TERMINAL_GREEN << "\ttoFloat called" << TERMINAL_RESET << std::endl;
	return (static_cast<float>(this->_value) / 256); // 256 = 2 ^ 8 as in _frac_bits
}

int	Fixed::toInt(void) const
{
	std::cout << TERMINAL_GREEN << "\ttoInt called" << TERMINAL_RESET << std::endl;
	return (this->_value / 256); // 256 = 2 ^ 8 as in _frac_bits
}

/* ************************************************************************** */
// Non-member functions

std::ostream& operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
