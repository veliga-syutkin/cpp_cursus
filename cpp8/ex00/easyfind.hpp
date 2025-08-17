/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:51:37 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/08/17 07:55:01 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include "../terminal_colors.hpp"
# include <algorithm>
# include <iostream>
# include <stdexcept>

/* NB: `iterators` are present in every container (c++98 wise - almost every). https://cplusplus.com/reference/stl/ */

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
