/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:55:26 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/09 13:33:21 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

# include "../terminal_colors.hpp"
# include <iostream>
# include <set>
# include <exception>
# include <algorithm>
# include <iterator>
# include <climits>
# include <cmath>

class Span
{
	private:										// Private members
		std::multiset<int>	_elements;				// Set to store (potentially same) elements, in order.
		unsigned int		_maxSize;				// Maximum size of the set
		unsigned int		_currentSize; 			// Current size of the set (not innate to multiset)

		void				_checkSpanable() const;		// Check if the set is full

	protected:										// Protected members for inheritance

	public:
		Span();                                	// Default constructor
		Span(const Span &other);         	// Copy constructor
		Span &operator=(const Span &other); // Assignment operator
		~Span();                                	// Destructor

		Span(unsigned int N);

		void	addNumber(int number);
		void	addNumber(int *numbers, unsigned int size);

		int		shortestSpan() const;
		int		longestSpan() const;
};

class SpanException : public std::exception
{
	private:

	protected:
		std::string	_message;
	
	public:
		~SpanException() throw() {};
		const char *what() const throw();
};

class SpanFullException : public SpanException
{
	public:
		SpanFullException();
};

class SpanEmptyException : public SpanException
{
	public:
		SpanEmptyException();
};

class SpanNotEnoughElementsException : public SpanException
{
	public:
		SpanNotEnoughElementsException();
};

#endif // SPAN_HPP
