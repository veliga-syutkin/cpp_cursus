/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:31:17 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/10 14:06:09 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once // replace #ifndef/#define/#endif with #pragma once

#include <cstdlib> // for size_t
#include <iostream>
#include <stdexcept> // for std::exception
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
	catch (std::exception &e)
	{
		std::cerr << TERMINAL_RED << "An error occurred while iterating over the array: " << e.what() << TERMINAL_RESET << std::endl;
		throw e; // Re-throw the exception to allow further handling if needed
	}
	catch (...)
	{
		std::cerr << TERMINAL_RED << "An unknown error occurred while iterating over the array." << TERMINAL_RESET << std::endl;
		throw; // Re-throw the unknown exception
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
	catch (std::exception &e)
	{
		std::cerr << TERMINAL_RED << "An error occurred while iterating over the array: " << e.what() << TERMINAL_RESET << std::endl;
		throw e; // Re-throw the exception to allow further handling if needed
	}
	catch (...)
	{
		std::cerr << TERMINAL_RED << "An unknown error occurred while iterating over the array." << TERMINAL_RESET << std::endl;
		throw; // Re-throw the unknown exception
	}
}
