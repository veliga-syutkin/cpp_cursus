/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:31:17 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/10 13:01:46 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once // replace #ifndef/#define/#endif with #pragma once

#include <cstdlib> // for size_t
#include "../terminal_colors.hpp"

template <typename T>
void iter(T *array, size_t length, void (*func)(T &))
{
	try										// Catch block to handle exceptions if the function throws
	{
		for (size_t i = 0; i < length; ++i)
		{
			func(array[i]);
		}
	}
	catch (... &e)
	{
		std::cerr << RED << "An error occurred while iterating over the array: " << e.what() << RESET << std::endl;
	}
}

// Overload function for const arrays
template <typename T>
void iter(const T *array, const size_t length, void (*func)(const T &))
{
	try										// Catch block to handle exceptions if the function throws
	{
		for (size_t i = 0; i < length; ++i)
		{
			func(array[i]);
		}
	}
	catch (... &e)
	{
		std::cerr << RED << "An error occurred while iterating over the array: " << e.what() << RESET << std::endl;
	}
}
