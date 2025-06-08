/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:51:37 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/06/08 14:57:03 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include "../terminal_colors.hpp"
# include <algorithm>
# include <iostream>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int value) // for any T, we'll use it's innate `iterator` type
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
	{
		throw std::runtime_error("Value not found in the container");
	}
	return it;
}

template <typename T>
typename T::iterator easyfind(const T &container, const int value) // for any T, we'll use it's innate `iterator` type
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
	{
		throw std::runtime_error("Value not found in the container");
	}
	return it;
}

#endif // EASYFIND_HPP
