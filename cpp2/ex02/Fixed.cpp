/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:45:51 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/10 18:36:30 by vsyutkin         ###   ########.fr       */
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
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

Fixed::Fixed(const int value) //: _value(value * 256) // 256 = 2 ^ 8 as in _frac_bits
{
	long long int tmp = value * 256;
	if (tmp > INT_MAX || tmp < INT_MIN) // good practice
	{
		std::cerr << TERMINAL_RED << "\tInt constructor: value out of range" << TERMINAL_RESET << std::endl;
		throw std::overflow_error("Int constructor: value out of range");
	}
	this->_value = static_cast<int>(tmp);
}

Fixed::Fixed(const float value)
{
	double tmp = roundf(value * 256); // 256 = 2 ^ 8 as in _frac_bits
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
	long long int result = (this->_value / 256) + (other._value / 256);
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
	long long int result = (this->_value / 256) - (other._value / 256);
	if (result > INT_MAX || result < INT_MIN) // good practice
	{
		std::cerr << TERMINAL_RED << "\tAddition: value out of range" << TERMINAL_RESET << std::endl;
		throw std::overflow_error("Addition: value out of range");
	}
	Fixed res(static_cast<int>(result));
	return (res);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	long long int result = (this->_value / 256) * (other._value / 256);
	std::cout << "result: " << result << std::endl;
	if (result > INT_MAX || result < INT_MIN) // good practice
	{
		std::cerr << TERMINAL_RED << "\tAddition: value out of range" << TERMINAL_RESET << std::endl;
		throw std::overflow_error("Addition: value out of range");
	}
	Fixed res(static_cast<int>(result));
	return (res);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	long long int result = (this->_value / 256) / (other._value / 256);
	if (result > INT_MAX || result < INT_MIN) // good practice
	{
		std::cerr << TERMINAL_RED << "\tAddition: value out of range" << TERMINAL_RESET << std::endl;
		throw std::overflow_error("Addition: value out of range");
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
	long long int tmp = this->_value + 1;
	if (tmp > INT_MAX || tmp < INT_MIN) // good practice
	{
		std::cerr << TERMINAL_RED << "\tAddition: value out of range" << TERMINAL_RESET << std::endl;
		throw std::overflow_error("Addition: value out of range");
	}
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++(int) // Post-increment
{
	Fixed temp(*this);
	long long int tmp = this->_value + 1;
	if (tmp > INT_MAX || tmp < INT_MIN) // good practice
	{
		std::cerr << TERMINAL_RED << "\tAddition: value out of range" << TERMINAL_RESET << std::endl;
		throw std::overflow_error("Addition: value out of range");
	}
	this->_value++;
	return (temp);
}

Fixed& Fixed::operator--() // Pre-decrement
{
	this->_value--;
	long long int tmp = this->_value - 1;
	if (tmp > INT_MAX || tmp < INT_MIN) // good practice
	{
		std::cerr << TERMINAL_RED << "\tAddition: value out of range" << TERMINAL_RESET << std::endl;
		throw std::overflow_error("Addition: value out of range");
	}
	return (*this);
}

Fixed Fixed::operator--(int) // Post-decrement
{
	Fixed temp(*this);
	this->_value--;
	long long int tmp = this->_value - 1;
	if (tmp > INT_MAX || tmp < INT_MIN) // good practice
	{
		std::cerr << TERMINAL_RED << "\tAddition: value out of range" << TERMINAL_RESET << std::endl;
		throw std::overflow_error("Addition: value out of range");
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
	os << fixed.toFloat() << " DEBUG: " << fixed.getRawBits();
	return os;
}
