/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:55:20 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/09 13:30:58 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// Default constructor
Span::Span() : _maxSize(0), _currentSize(0)
{
	// Initialize the set with a default capacity of 0
	std::cout << TERMINAL_GREEN << "\tDefault constructor Span called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
Span::Span(const Span &other)
{
	this->_elements = other._elements; // Copy the multiset elements
	this->_maxSize = other._maxSize;   // Copy the maximum size
	this->_currentSize = other._currentSize; // Copy the current size
	std::cout << TERMINAL_GREEN << "\tCopy constructor Span called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_elements = other._elements; // Copy the multiset elements
		this->_maxSize = other._maxSize;   // Copy the maximum size
		this->_currentSize = other._currentSize; // Copy the current size
		std::cout << TERMINAL_GREEN << "\tAssignation operator Span called" << TERMINAL_RESET << std::endl;
	}
	return (*this);
}

// Destructor
Span::~Span()
{
	std::cout << TERMINAL_GREEN << "\tDestructor Span called" << TERMINAL_RESET << std::endl;
}

/******************************************************************************/
/*-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-"*/
/*-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._*/
/*-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-"*/
/******************************************************************************/
//	Private methods

void	Span::_checkSpanable() const
{
	if (_elements.empty())
		throw SpanEmptyException();
	if (_elements.size() < 2)
		throw SpanNotEnoughElementsException();
}

/* ************************************************************************** */
//	Protected methods

/* ************************************************************************** */
//	Public methods

Span::Span(unsigned int N) : _maxSize(N), _currentSize(0)
{
	// Nothing	
}

// Add a single number to the multiset.
void	Span::addNumber(int number)
{
	if (_currentSize >= _maxSize)
	{
		throw SpanFullException();
	}
	_elements.insert(number);
	_currentSize++;
	std::cout << TERMINAL_GREEN << "\tAdded number: " << number << " to Span"
		// << TERMINAL_RED << " (Current size: " << _currentSize << ", Max size: " << _maxSize << ")"
		<< TERMINAL_RESET << std::endl;
}

// Add an array of numbers to the multiset.
void	Span::addNumber(int *numbers, unsigned int size)
{
	if (_currentSize + size > _maxSize)
	{
		throw SpanFullException();
	}
	_currentSize += size;
	for (unsigned int i = 0; i < size; ++i)
	{
		_elements.insert(numbers[i]);
	}
}

// This function calculates the longest span between the smallest and largest elements in the multiset.
// (Since the multiset is ordered, we can use begin() and rbegin() to get the smallest and largest elements.)
int	Span::longestSpan() const
{
	_checkSpanable();
	return (abs(*(_elements.begin()) - *(_elements.rbegin()))); // rbegin() != end() because end() is not a valid element (see it as '\0')
}

// This function calculates the shortest span between any two elements in the multiset.
int	Span::shortestSpan() const
{
	_checkSpanable();
	int	shortest = INT_MAX;
	std::multiset<int>::iterator current = _elements.begin();
	std::multiset<int>::iterator next = ++_elements.begin(); // Start from the second element
	while (next != _elements.end())
	{
		// std::cout << "Calulating difference between " << *current << " and " << *next << std::endl;
		if (abs(*current - *next) < shortest)	// shortest is always positive
			shortest = abs(*current - *next);
		current++;
		next++;
	}
	return (shortest);
}

/* ************************************************************************** */
// Exception methods

// SpanException::SpanException() : _message("Span Exception")
// {
// }

const char *SpanException::what() const throw()
{
	return (_message.c_str());
}

SpanFullException::SpanFullException() : SpanException()
{
	_message = "Span is full";
}

SpanEmptyException::SpanEmptyException() : SpanException()
{
	_message = "Span is empty";
}

SpanNotEnoughElementsException::SpanNotEnoughElementsException() : SpanException()
{
	_message = "Not enough elements in Span to calculate span";
}
