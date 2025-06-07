/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:31:17 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/07 18:38:42 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once // replace #ifndef/#define/#endif with #pragma once

#include <cstdlib> // for size_t

template <typename T>
void iter(T *array, size_t length, void (*func)(T &))
{
	for (size_t i = 0; i < length; ++i)
	{
		func(array[i]);
	}
}

// Overload function for const arrays
template <typename T>
void iter(const T *array, const size_t length, void (*func)(const T &))
{
	for (size_t i = 0; i < length; ++i)
	{
		func(array[i]);
	}
}
