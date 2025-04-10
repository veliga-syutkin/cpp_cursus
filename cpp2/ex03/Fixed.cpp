/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:45:51 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/10 22:29:50 by vsyutkin         ###   ########.fr       */
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
    // std::cout << TERMINAL_GREEN << "\tDefault constructor called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other) : _value(other._value)
{
	// std::cout << TERMINAL_GREEN << "\tCopy constructor called" << TERMINAL_RESET << std::endl;
}

// Assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << TERMINAL_GREEN << "\tAssignation operator called" << TERMINAL_RESET << std::endl;
    if (this != &other) {
        // Assignment logic
		this->_value = other._value;
    }
    return *this;
}

// Destructor
Fixed::~Fixed()
{
	// std::cout << TERMINAL_GREEN << "\tDestructor called" << TERMINAL_RESET << std::endl;
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
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

Fixed::Fixed(const int value) //: _value(value * 256) // 256 = 2 ^ 8 as in _frac_bits
{
	long int tmp = (long)value * (long)256;
	if (tmp > INT_MAX || tmp < INT_MIN) // good practice
	{
		std::cerr << TERMINAL_RED << "\tInt constructor: value out of range" << TERMINAL_RESET << std::endl;
		throw std::overflow_error("Int constructor: value out of range");
	}
	this->_value = static_cast<int>(tmp);
}

Fixed::Fixed(const float value)
{
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
	return (static_cast<float>(this->_value) / 256); // 256 = 2 ^ 8 as in _frac_bits
}

int	Fixed::toInt(void) const
{
	return (this->_value / 256); // 256 = 2 ^ 8 as in _frac_bits
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_value < other._value);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_value <= other._value);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_value != other._value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	long int result = (long)(this->_value / 256) + (long)(other._value / 256);
	if (result > INT_MAX || result < INT_MIN) // good practice
	{
		std::cerr << TERMINAL_RED << "\tAddition: value out of range" << TERMINAL_RESET << std::endl;
		throw std::overflow_error("Addition: value out of range");
	}
	Fixed res(static_cast<int>(result));
	return (res);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	long int result = (long)(this->_value / 256) - (long)(other._value / 256);
	if (result > INT_MAX || result < INT_MIN) // good practice
	{
		std::cerr << TERMINAL_RED << "\tSubstract: value out of range" << TERMINAL_RESET << std::endl;
		throw std::overflow_error("Substract: value out of range");
	}
	Fixed res(static_cast<int>(result));
	return (res);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	long int result = (long)(this->_value / 256) * (long)(other._value / 256);
	if (result > INT_MAX || result < INT_MIN) // good practice
	{
		std::cerr << TERMINAL_RED << "\tMultiplication: value out of range" << TERMINAL_RESET << std::endl;
		throw std::overflow_error("Multiplication: value out of range");
	}
	Fixed res(static_cast<int>(result));
	return (res);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	long int result = (long)(this->_value / 256) / (long)(other._value / 256);
	if (result > INT_MAX || result < INT_MIN) // good practice
	{
		std::cerr << TERMINAL_RED << "\tDivision: value out of range" << TERMINAL_RESET << std::endl;
		throw std::overflow_error("Division: value out of range");
	}
	result = result / 256; // 256 = 2 ^ 8 as in _frac_bits
	Fixed res(static_cast<int>(result));
	return (res);
}

/* ************************************************************************** */
/* 		OPERATORS 															  */
/* ************************************************************************** */

Fixed& Fixed::operator++() // Pre-increment
{
	long tmp = (long)(this->_value) + (long)(1);
	if (tmp > INT_MAX || tmp < INT_MIN) // good practice
	{
		std::cerr << TERMINAL_RED << "\tPre-incrementaion: value out of range" << TERMINAL_RESET << std::endl;
		throw std::overflow_error("Pre-incrementaion: value out of range");
	}
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++(int) // Post-increment
{
	Fixed temp(*this);
	long int tmp = (long)(this->_value) + (long)(1);
	if (tmp > INT_MAX || tmp < INT_MIN) // good practice
	{
		std::cerr << TERMINAL_RED << "\tPost-increment: value out of range" << TERMINAL_RESET << std::endl;
		throw std::overflow_error("Post-increment: value out of range");
	}
	this->_value++;
	return (temp);
}

Fixed& Fixed::operator--() // Pre-decrement
{
	this->_value--;
	long int tmp = (long)(this->_value) - (long)(1);
	if (tmp > INT_MAX || tmp < INT_MIN) // good practice
	{
		std::cerr << TERMINAL_RED << "\tPre-decrement: value out of range" << TERMINAL_RESET << std::endl;
		throw std::overflow_error("Pre-decrement: value out of range");
	}
	return (*this);
}

Fixed Fixed::operator--(int) // Post-decrement
{
	Fixed temp(*this);
	this->_value--;
	long int tmp = (long)(this->_value) - (long)(1);
	if (tmp > INT_MAX || tmp < INT_MIN) // good practice
	{
		std::cerr << TERMINAL_RED << "\tPost-decrement: value out of range" << TERMINAL_RESET << std::endl;
		throw std::overflow_error("Post-decrement: value out of range");
	}
	return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

/* ************************************************************************** */
// Non-member functions

std::ostream& operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
