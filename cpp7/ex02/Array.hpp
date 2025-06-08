/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:41:09 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/08 14:41:11 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

# include "../terminal_colors.hpp"
# include <iostream>
# include <stdexcept> // std::exception
# include <cstddef>   // std::size_t

template <typename T>
class Array
{
	private:										// Private members
		T			*_data;
		std::size_t	_size;

	protected:										// Protected members for inheritance

	public:
		Array();                                	// Default constructor
		Array(const Array &other);         	// Copy constructor
		Array &operator=(const Array &other); // Assignment operator
		~Array();                                	// Destructor

		Array(unsigned int n);
		T &operator[](std::size_t index);
		const T &operator[](std::size_t index) const;

		std::size_t size() const;
};

#include "Array.tpp"

#endif // ARRAY_HPP
